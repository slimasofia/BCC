.code16
.text 				    

.globl _start

_start:
	movw $array, %si      # carrega o endereço de 'array' em SI						
	movb array_size, %cl  # move o tamanho do array para CL					 		
	xor %ax, %ax	      # limpa AX (vai receber o resultado)

sum_loop:
	mov (%si), %bl        # lê o valor do primeiro elemento do array e armazena em BL
	add %bl, %al	      # adiciona o valor de BL a AL										
	inc %si               # incrementa SI para apontar para o próximo elemento
	dec %cl               # decrementa o contador
	jnz sum_loop          # se o contador não for zero, repete o loop

	hlt                   # (verificar o valor em AX que tem que ser 6)

array:			      
	.byte 1, 2 , 3	      # definindo o array
array_size:
	.byte 3

. = _start + 510

.byte 0x55		        
.byte 0xaa		        
