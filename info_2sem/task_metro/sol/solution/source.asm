global main

extern exit

section .text

main:
	
	mov eax, [esp+4]
	
	sub eax, 1

	push eax
	call exit

section .data
outf db "%d", 0xA, 0

section .bss
a resd 1