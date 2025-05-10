.code16 			    
.text 				    

.globl _start

_start:	
	# 80/40
	# div %divisor
	# o divisor é um valor de 8 bits
	# o dividendo é um valor de 16 bits - será armazenado nos registradores AL e AH
	# o resultado será armazenado em AL e o resto em AH

	movw $0x50, %ax # 80 em decimal
	movb $0x28, %bl # 40 em decimal
	div %bl	        # divide o que está em ax (16 bits) pelo que está em bl (8 bits)
	hlt

. = _start + 510

.byte 0x55		        
.byte 0xaa		        
