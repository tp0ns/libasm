section	.text						;tells program which kind of section follows (could be .data or .code)
	
	global	ft_strlen				;ft_strlen will be global and not static

ft_strlen:
	mov		rax, 0					;AX/EAX/RAX will always be the ret value
	jmp		count;					;Program counter point now to count function

count:								;count function
	cmp		BYTE [rdi + rax], 0;	;compare the value of the byte pointed to by "rdi + rax" to 0 (actually does 0 - [rdi + rax] without modyfing anything) if == 0 then zeroflag == 1 
	je		stop					;if zero flag == 1 then program counter point to stop function (je(jump equal) is alias for jz(jump if zero)
	inc		rax						;increment the value stored in rax
	jmp		count					;program counter point again to count function

stop:
	ret								;function stop and return the value stored in AX/EAX/RAX