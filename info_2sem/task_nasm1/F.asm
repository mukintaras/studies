global main

extern exit
extern scanf
extern printf

section .text

main:
	push dword b
	push dword a
	push dword inpf
	call scanf
	add esp, 12

	mov eax, [a]
	mov ebx, [b]
	
	cmp eax, ebx

	jg greater

	push dword [a]
	jmp end

	greater:
		push dword [b]

	end:
	push dword outf
	call printf

	push dword 0
	call exit

section .data
inpf db "%d%d", 0
outf db "%d", 0xA, 0

section .bss
a resd 1
b resd 1