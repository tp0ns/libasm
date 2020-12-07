section	.text

	global	ft_strdup
	extern	ft_strlen
	extern	malloc
	extern	ft_strcpy

ft_strdup:					;(1st arg : rdi : *s)
	mov		r8, rdi			;copy rdi in r8
	call	ft_strlen		;call ft_strlen and stores result in rax
	inc		rax				;add space to malloc \0
	mov		rdi, rax		;store rax value in rdi to know how much memory has to be allocated
	call	malloc			;calls malloc
	cmp		rax, 0			;compare return of malloc to zero
	je		error			;if previous operation was right, jumps to error
	mov		rdi, rax		;set allocated pointer as 1st argument
	mov		rsi, r8			;set r8(*s) as second argument
	call	ft_strcpy		;call ft_strcpy, which copy r8 (*s) content inside rdi and return rdi in rax
	ret						;return rax

error:
	ret						;return rax