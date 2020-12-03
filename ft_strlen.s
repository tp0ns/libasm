section	.text ; tells program which kind of section follows (could be .data or .code)
	
	global	ft_strlen ; ft_strlen will be global and not static

ft_strlen:
	mov		rax, 0;
	jmp		count;

count:
	cmp		BYTE [rdi + rax], 0;
	je		stop;
	inc		rax;
	jmp		count;

stop:
	ret;