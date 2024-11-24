.code16 			    
.text 				    

.globl _start

_start:
    	xor %ah, %ah        # Zera o registrador AH (AH = 0x00)	
    	xor %al, %al        # Zera o registrador AL (AL = 0x00)
    	xor %bl, %bl        # Zera o registrador BL (BL = 0x00)

	# AND
	movb $0x0F, %al # (00001111)
	movb $0xF0, %bl # (11110000)
	andb %bl, %al   # o resultado é 0x00 e fica em al

	# após AND:
	# al está zerado
	# bl contém 0xF0 (240)

	# OR
	movb $0x0F, %al # (00001111)
	orb %bl, %al    # o resultado é 11111111 (0xFF) e fica em al

	# após OR:
	# al contém 0xFF (255)
	# bl contém 0xF0

	# NOT
	notb %al # no registrador al está armazenado 0xFF, que e após a operação vira 0x00

	# após NOT:
	# al está zerado
	# bl contém 0xF0

	# XOR
	movb $0x0F, %al
	xorb %bl, %al   # o resultado é 0xFF e fica armazenado em al

	# após XOR:
	# al contém 0xFF
	# bl contém 0xF0


. = _start + 510

.byte 0x55		        
.byte 0xaa		        
