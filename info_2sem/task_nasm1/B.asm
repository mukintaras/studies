extern puts
extern exit
extern scanf
extern printf

section .text
 
global main
main:
	push dword inp
	push dword formin
	call scanf
	add esp, 8

	mov eax, [inp]
	and eax, 0xFFFF

	push eax
	push dword formout
	call printf

	push dword 0
	call exit

section .data
formin db "%u", 0
formout db "%u", 0xA, 0

section .bss
inp resw 1 