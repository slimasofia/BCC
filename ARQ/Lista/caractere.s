.code16 			    
.text 				    

.globl _start

_start:
	movb $0x01, %ah		# configurando o registrador ah com o número da função (AH = 01 lê um caractere do teclado)
	int $0x21		# chamando a interrupção (o caractere lido é retornado em AL)	

	mov %al, %dl		# a função 02 espera o caractere a ser mostrado em DL
	movb $0x02, %ah		# (AH = 02 exibe um caractere na tela)
	int $0x21

	hlt


. = _start + 510

.byte 0x55		        
.byte 0xaa		   
