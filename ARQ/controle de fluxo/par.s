.code16 			    
.text 				    

.globl _start

_start:
	movw $0x50, %ax		# movendo o número 80 para AX (verificar se ele é par)
	movb $2, %bl		# movendo 2 para bl
	call par_impar
	hlt

par_impar:
	div %bl			# divide o que está em ax pelo que está em bl, o resto fica em ah
	test %ah, %ah		# 'test' realiza a operação lógica 'and', 
				# se 'test' for seguido por um jnz, o salto acontecerá se houver qualquer bit correspondente igual a 1 em ambos os operadores
	jnz impar 		# se o resto for diferente de 0 vai para "impar"
	mov $0, %ax		# move 0 para ax se o número for par
	ret

impar:
	mov $1, %ax 		# retorna 1 em ax se o número for impar
	ret

. = _start + 510

.byte 0x55		        
.byte 0xaa		   
