global subroutine

section .text

subroutine:
	push ebx

	mov ecx, [esp+0x8]
	mov edx, [esp+0xc]

	mov ebx, ecx
	
	sub ebx, edx
	lea eax, [ecx+edx*1]
	cmp ecx, edx

	cmovle eax, ebx

	pop ebx
	ret