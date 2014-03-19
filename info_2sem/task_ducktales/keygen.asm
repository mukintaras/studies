global main

extern exit
extern scanf
extern printf

section .text

main:
	push dword a
	push dword inpf
	call scanf

	mov eax, [a]
	
	sub eax, 0x18894

	push eax
	push dword outf
	call printf

	push 0
	call exit

section .data
inpf db "%d", 0
outf db "%d", 0xA, 0

section .bss
a resd 1