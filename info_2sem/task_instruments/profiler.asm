global main

extern exit
extern printf
extern scanf

section .text

main:

; push dword a
; push inpf
; call scanf

; push a
; push outfc
; call printf

jmp csidiv

csnop:

	rdtsc

	mov esi, eax
	xor eax, eax
	cpuid

	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	
	rdtsc

	sub eax, esi
	mov edi, eax

jmp end

csidiv:

	rdtsc

	mov esi, eax
	xor eax, eax
	cpuid
	mov ecx, 1

	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	idiv ecx
	
	rdtsc

	sub eax, esi
	mov edi, eax

jmp end

csfdiv:

	rdtsc

	mov esi, eax
	xor eax, eax
	cpuid
	mov ecx, 1

	fldpi

	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	fdiv st0
	
	rdtsc

	sub eax, esi
	mov edi, eax

jmp end

end:

	rdtsc

	mov esi, eax
	xor eax, eax
	cpuid
	
	rdtsc

	sub eax, esi



	sub edi, eax

	sar edi, 6

	

	push edi
	push outf
	call printf

	push 0
	call exit

section .data
inpf db "%c", 0
outf db "%d", 0xA, 0
outfc db "%c", 0xA, 0
nopc db "n"
idivc db "i"
fdivc db "f"

section .bss
a resd 1