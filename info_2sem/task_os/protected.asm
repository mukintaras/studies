[BITS 16]
[ORG 0x7c00]
_start:	
	cli
	mov ax, cs
	mov ds, ax
	mov ss, ax
	mov sp, _start

	;; Загрузка регистра GDTR:	
	lgdt [gd_reg]

	;; Включение A20: 
	in al, 0x92
	or al, 2
	out 0x92, al

	;; Установка бита PE (Protection Enabled) регистра CR0
	mov eax, cr0 
	or al, 1	
	mov cr0, eax  

	;; С помощью длинного прыжка мы загружаем
	;; селектор нужного сегмента в регистр CS
	;; (напрямую это сделать нельзя)
	;; 8 (1000b) - первый дескриптор в GDT, RPL=0
	jmp 0x8: _protected


[BITS 32]
_protected:	
	;; Загрузим регистры DS и SS селектором
	;; сегмента данных
	mov ax, 0x10
	mov ds, ax
	mov ss, ax

	mov esi, msg_hello
	call kputs	

	;; Завесим процессор
	hlt
	jmp short $


cursor:	dd 0
%define VIDEO_RAM 0xB8000
%define COLOR_RAM 0xB7FFF
%define TSTART 0x20
%define TEND 0x40

;; Функция выполняет прямой вывод в память видеоадаптера
;; которая находится в VGA-картах (и не только) по адресу 0xB8000

mov ebx, TSTART

putone:
	mov [ebx], 0xFF
	inc ebx
	cmp ebx, TEND
	jne putone

mov ebx, TSTART

readone:
	cmp [ebx], 0xFF
	jne prbad
	inc ebx
	cmp ebx, TEND
	jne readone

prgood:
	mov esi, msg_good
	call kputsgood
	jmp end

prbad
	mov esi, msg_bad
	call kputsbad
	jmp end
	
kputsbad:
	pusha
.loopb:	
	lodsb 
	test al, al
	mov bl, 00001100b

	jz .quitb
	mov ecx, [cursor]
	mov [VIDEO_RAM+ecx*2], al
	mov [COLOR_RAM+ecx*2], bl
	inc dword [cursor]
	jmp short .loopb

.quitb:	
	popa
	ret

kputsgood:
	pusha
.loopg:	
	lodsb 
	test al, al
	mov bl, 00001010b

	jz .quitg
	mov ecx, [cursor]
	mov [VIDEO_RAM+ecx*2], al
	mov [COLOR_RAM+ecx*2], bl
	inc dword [cursor]
	jmp short .loopg

.quitg:	
	popa
	ret

end:
		

gdt:
	dw 0, 0, 0, 0	; Нулевой дескриптор

	db 0xFF		; Сегмент кода с DPL=0 
	db 0xFF		; Базой=0 и Лимитом=4 Гб 
	db 0x00
	db 0x00
	db 0x00
	db 10011010b
	db 0xCF
	db 0x00
	
	db 0xFF		; Сегмент данных с DPL=0
	db 0xFF		; Базой=0 и Лимитом=4Гб	
	db 0x00	
	db 0x00
	db 0x00
	db 10010010b
	db 0xCF
	db 0x00


	;; Значение, которое мы загрузим в GDTR:	
gd_reg:
	dw 8192
	dd gdt

msg_hello:	db "Hello from the world of 32-bit Protected Mode ",0x0a,0x0d,0
msg_bad: db "Memory BAD",0x0a,0x0d,0
msg_good: db "Memory GOOD",0x0a,0x0d,0

	times 510-($-$$) db 0
	db 0xaa, 0x55


