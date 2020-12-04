section .text

    global  ft_strcpy
    extern	ft_strlen	;include ft_strlen

ft_strcpy:
	push	rdi			;push rdi on top of the stack
	mov		rdi, rsi	;rdi(1st argument register) = rsi(2nd argument register) so ft_strlen can calculate the length of rsi string
	call	ft_strlen	;calculate the length of the string stored in rdi and returns it in rax register
	mov		rcx, rax	;stores rax value(source string length) in rcx(counter register) which is used implicitly by rep to do "rcx" repetitions
	pop		rdi			;pull rdi from stack and put it back in rdi so destination adress is the right one
	mov		rax, rdi	;rax(return value register) is now rdi(1st param register (dest string adress))
	cld					;make sure DF(Direction Flag) = 0, used in movsb to decrement(DF = 1) or increment(DF = 0) pointers value
	rep		movsb		;rep repeat "rcx" time the action movsb which move rsi inside rdi and increment(if DF flag is 0) both rdi and rsi
	mov		rdi, 0		;because rdi was incremented by movsb rdi points to the end of the string, we add 0 to match \0 rule
	ret