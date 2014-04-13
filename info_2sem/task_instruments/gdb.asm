global main

extern exit
extern printf

section .text

main:

	push 77
	push dword outf
	call printf

	push 0
	call exit

section .data
inpf db "%d", 0
outf db "%d", 0xA, 0

section .bss
a resd 1