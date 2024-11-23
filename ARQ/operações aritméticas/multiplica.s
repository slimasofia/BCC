.code16 			    
.text 				    

.globl _start

_start:				
	movb $0x12, %al 	# move 18 para o registrador al
	movb $0x12, %bl		# move 18 para o registrador bl
	mul %bl			# efetua a multiplicação; o registrador ax deve conter 324
	hlt

. = _start + 510

.byte 0x55		        
.byte 0xaa		        
