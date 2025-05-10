.code16 			    
.text 				    

.globl _start

_start:
	
	# ds: registrador de segmento    
	# posição: (ds:si)

	mov $0x1000, %ax  # movendo 0x1000 para o registrador ax
	mov %ax, %ds      # configurando ds com o valor de AX, definindo o segmento base para acessos de memória
	mov $0x200, %si   # SI aponta para a posição 0x200 (deslocamento)
	xor %ax, %ax	  # zerando o valor de ax
	mov (%si), %al    # lê o conteúdo da memória no endereço DS:SI (0x1000 x 16 + 0x200 = 0x10200 --> 4096 x 16 + 512 = 66048) e armazena em AL

	# AL deve conter o conteúdo de 0x10200

	hlt

. = _start + 510

.byte 0x55		        
.byte 0xaa		        
