# burocracias 
.code16 			    
.text 				    
.globl _start

# ponto de entrada do programa
_start: 

    # Definir a posição da string no segmento de dados
    movw $message, %si  # SI aponta para o início da string

print_string:
    # Carrega o próximo caractere da string (a partir de %si) no registrador AL
    lodsb               # Carrega o byte em [SI] para AL e incrementa SI
    cmpb $0, %al        # Verifica se o caractere é o terminador nulo (0)
    je done             # Se for, salta para 'done'

    # Definir AH com a função de teletipo (0x0e) para impressão
    movb $0x0e, %ah

    # Chamar interrupção de vídeo 0x10 para exibir o caractere
    int $0x10

    # Repetir para o próximo caractere
    jmp print_string

done:
    # loop para manter o processador em estado de halt
    loop_final:
        hlt
        jmp loop_final

# Define a string a ser impressa
# A string termina com um byte nulo (0) para indicar o fim
message:
    .ascii "Ola, mundo!\0"

# move o contador da posição atual no código (representado pelo .) para o byte 510
. = _start + 510

# assinatura de boot MBR
# pro programa ser reconhecido como boot MBR, é preciso que os bytes 510 e 511 tenham os valores 0x55 e 0xaa
.byte 0x55		        
.byte 0xaa	

