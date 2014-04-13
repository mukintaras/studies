global main

extern exit
extern printf

section .text

main:
	
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



	rdtsc

	mov esi, eax
	xor eax, eax
	cpuid

	mov ecx, 1

	nop
	
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
outf db "%ld", 0xA, 0