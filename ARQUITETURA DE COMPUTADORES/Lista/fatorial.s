.code16
.text 

.globl _start

_start:
    xor %ax, %ax        # zera AX
    mov $5, %bl         # move o número 3 para BL (para calcular seu fatorial)
    call fatorial       # Chama a subrotina para calcular o fatorial
    hlt                 

fatorial:
    mov $1, %ax         # inicializa AX com 1

fatorial_loop:
    cmp $1, %bl         # Compara BL com 1
    jle fatorial_done   # Se BL <= 1, termina o cálculo

    mul %bl             # Multiplica o conteúdo de AX pelo valor de BL (fatorial)
    dec %bl             # Decrementa BL (reduz o número para o próximo passo do fatorial)
    jmp fatorial_loop   # repete

fatorial_done:
    ret                

. = _start + 510

.byte 0x55
.byte 0xaa

