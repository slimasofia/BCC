.code16 			    
.text 				    

.globl _start

_start:
	# loop que conta de 1 a 10
	# ('loop' decrements CX by 1 and transfers control to the target operand if CX is not 0)
	
	xor %ax, %ax		# zerando AX
	xor %ecx, %ecx		# zerando CX
	mov $10, %cx 		# definindo o contador 	

loop_start:	
	inc %ax			# incrementando AX em 1
	loop loop_start		# decrementa CX e verifica se ele é diferente de 0, se sim, volta para o loop_start
	hlt

. = _start + 510

.byte 0x55		        
.byte 0xaa		   
