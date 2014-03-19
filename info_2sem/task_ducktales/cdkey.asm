global main

extern exit
extern scanf
extern puts

section .text

main:
	push dword b
	push dword a
	push dword inpf
	call scanf

	mov eax, [a]
	mov ebx, [b]
	
	add eax, ebx

	cmp eax, 42

	je eq

	push dword nemsg
	jmp fin

	eq:
	push dword eqmsg

	fin:
	call puts

	push 0
	call exit

section .data
inpf db "%d%d", 0
eqmsg db "Accepted!", 0xA, 0
nemsg db "Wrong key!", 0xA, 0

section .bss
a resd 1
b resd 1