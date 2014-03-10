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

	jo over

	push dword nope
	jmp end

	over:
		push dword yep 

	end:
	call puts

	push dword 0
	call exit

section .data
inpf db "%d%d", 0
yep db "YES", 0xA, 0
nope db "NO", 0xA, 0

section .bss
a resd 1
b resd 1