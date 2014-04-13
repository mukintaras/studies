global main

extern exit
extern printf

section .text

main:
	
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
outf db "%ld", 0xA, 0