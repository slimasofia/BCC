# burocracias 
.code16 			    
.text 				    
.globl _start

# ponto de entrada do programa
_start: 

# cl recebe 80 para ser usado no loop 
# (quantidade de caracteres numa linha)
movb $80, %cl
print_row:
    # registrador al recebe 'x'
    movb $'x' , %al
    # registrador ah recebe 0x0e (corzinha)
    movb $0x0e, %ah		
    # interrupção de vídeo (printa na tela)
    int  $0x10
    # decrementa o cl
    decb %cl
    # se cl for diferente de 0, volta pro print_row
    jnz print_row

# cl recebe 23 pra ser usado no loop 
# (25 linhas - 1 do começo e 1 do final)
movb $23, %cl
loop_23:
    # registrador al recebe 'x'
    movb $'x' , %al
    # corzinha
    movb $0x0e, %ah		
    # printa
    int  $0x10

    # registrador ch recebe 78 (quantidade de espaços entre o x do começo e o x do final da linha)
    movb $78, %ch
    loop_78:
        # registrador al recebe ' '
        movb $' ' , %al
        # corzinha
        movb $0x0e, %ah		
        # printa o espaço
        int  $0x10
        # decrementa o ch
        decb %ch
        # se ch for diferente de 0, volta pro loop_78
        jnz loop_78

    # printa o x no final da linha
    movb $'x' , %al
    movb $0x0e, %ah		
    int  $0x10

    # decrementa o cl
    decb %cl
    # se cl for diferente de 0, volta pro loop_23
    jnz loop_23

# cl recebe 79 para ser usado no loop 
#(1 caractere a menos para ele não pular sozinho pra próxima linha e a primeira ficar fora da tela)
movb $79, %cl

# printar a linha de x do final
print_row2:
    movb $'x' , %al
    movb $0x0e, %ah		
    int  $0x10
    decb %cl
    jnz print_row2

# loop para manter o processador em estado de halt
loop_final:
    hlt
    jmp loop_final

# move o contador da posição atual no código (representado pelo .) para o byte 510
. = _start + 510

# assinatura de boot MBR
# pro programa ser reconhecido como boot MBR, é preciso que os bytes 510 e 511 tenham os valores 0x55 e 0xaa
.byte 0x55		        
.byte 0xaa		        
