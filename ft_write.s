section	.text

	global	ft_write
	extern	__errno_location	;include _errno_location

ft_write:						;(1st arg : rdi : fd)(2nd : rsi : buf)(3rd : rdx : count)
	mov		rax, 1				;rax will be used to know which function syscall call (1 is for calling write)
	syscall						;use same param register as our function. return a value btw -4095 and -1, if error happens, that correspond to errno
	add		rax, 0				;sets signed flag if rax < 0
	js	error					;check if the last operation result in a signed result(signed flag), if yes jump to error
	jmp	stop					;normal return

error:
	mov		r8, rax				;store rax value in r8			
	call	__errno_location	;call function to get errno adress in rax
	neg		r8					;r8 is now positive
	mov		[rax], r8			;store value of r8 at the adress stored in rax
	mov		rax, -1				;set rax at -1
	ret							;return rax

stop:
	ret							;return rax which has been fulfill by syscall write and correspondto byte written