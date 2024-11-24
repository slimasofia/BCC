.code16 			    
.text 				    

.globl _start

_start:
	
	# ds: registrador de segmento    
	# posição: (ds:si)

	mov $0x1000, %ax  # movendo 0x1000 para o registrador ax
	mov %ax, %ds      # configurando ds com o valor de AX, definindo o segmento base para acessos de memória
	mov $0x200, %si   # SI aponta para a posição 0x200 (deslocamento)
	mov $0x55, %bl	  # 	
	mov %bl, (%si)    # lê o conteúdo de bl e armazena na memória no endereço DS:SI (0x1000 x 16 + 0x200 = 0x10200)

	hlt
	
	# a posição de memória 0x10200 deve conter 0x55 (85) 
	  # pra verificar: x /1bx 0x10200

. = _start + 510

.byte 0x55		        
.byte 0xaa		   
