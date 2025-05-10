.code16 			    
.text 				    

.globl _start

_start:				
	movw $0x12, %ax   # movendo um valor em hexadecimal para o registrador ax (valor: 18)
	movw $0x56, %bx   # movendo o valor 86 para o registrador bx
	addw %bx, %ax     # ax = ax + bx o resultado está em ax
	hlt	

. = _start + 510

.byte 0x55		        
.byte 0xaa		        
