.code16
.text
.globl _start

_start:
	movw $string1, %si   	# carrega o endereço da string1 em SI
    	movw $string2, %di   	# carrega o endereço da string2 em DI

compare_loop:
    	movb (%si), %al		# carrega o byte atual da string1 em AL e faz SI apontar para o próximo elemento da string
    	movb (%di), %bl     	# carrega o byte atual da string2 em BL
	add $1, %si		# incrementa SI para o próximo caractere	
    	add $1, %di         	# incrementa DI para o próximo caractere
    
    	cmpb %al, %bl       	# compara o caractere de string1 com string2
    	jne not_equal       	# se diferente, salta para 'not_equal'
    
    	cmpb $0, %al        	# verifica se o caractere atual é o terminador nulo
    	je equal            	# se for, as strings são iguais, salta para 'equal'

    	jmp compare_loop    	# continua comparando os próximos caracteres
	hlt

not_equal:
	mov $0, %ax		# move zero pra AX se as strings forem diferentes	
    	hlt                 
equal:
	mov $1, %ax		# move 1 pra AX se as strings forem iguais
    	hlt              

string1:
    .ascii "hello\0"  
string2:
    .ascii "world\0"

. = _start + 510
.byte 0x55
.byte 0xaa
