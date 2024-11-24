# não sei qual o problema disso aqui já tentei tudo talvez seja o segmento base e a posição do array na memória

.code16
.text 				    

.globl _start

.section .data
array:
	.byte 1, 2 , 3, 4, 5
array_size:
	.byte 5

.section .text
_start:
	
	mov $0x1000, %ax # configurando o segmento base pra 0x1000
	mov %ax, %ds     # configura o segmento de dados
	
	xor %ax, %ax
	xor %bx, %bx
	lea array, %si   # carrega o endereço de 'array' em SI
	movb array_size, %cl
	

sum_loop:
	hlt
	mov (%si), %bl        # Lê o valor no endereço DS:SI (primeiro elemento do array) e armazena em bl
	add %bl, %al
	inc %si               # Incrementa SI para apontar para o próximo elemento
	dec %cl               # Decrementa o contador (CL)
	jnz sum_loop          # Se o contador não for zero, repete o loop

	hlt                   # Para a execução (verifique o valor em AX)

	#add $1, %si
	

. = _start + 510

.byte 0x55		        
.byte 0xaa		        
