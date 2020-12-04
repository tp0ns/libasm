section .text

    global ft_strcmp

ft_strcmp:
    mov		rax, 0			;intitiate rax value to 0
    jmp		compare			;go to compare function

compare:
	mov		al, BYTE [rdi]	;stores first byte(out of 8) of rdi and store it in al(1 byte register of rax)
	mov		cl,	BYTE [rsi]	;same as above but with rsi/cl/rcx
	cmp		al, 0			;check if al == 0
	je		stop			;if yes go to stop
	cmp		cl, 0			;check if cl == 0
	je		stop			;if yes go to stop
	cmp		al, cl			;if(al != cl)
	jne		stop			;goto stop
	inc		rdi				;increment rdi
	inc		rsi				;increment rsi
	jmp		compare			;repeat compare

stop:
	movzx	rax, al			;copy al into rax and fill remaining space with 0
	movzx	rcx, cl			;copy cl into rcx and fill remaining space with 0
	sub		rax, rcx		;rax - rcx and store result in rax
	ret						;return rax as usual