global main

extern exit
extern scanf
extern printf

section .text

main:
	push dword a
	push dword b
	push dword inpf
	call scanf

	mov eax, [a]
	mov edx, [b]
	sub edx, eax

	push edx
	push dword outf
	call printf

	push dword 0
	call exit

section .data
inpf db "%d %d", 0
outf db "%d", 0xA, 0

section .bss
a resd 1
b resd 1