using LinearAlgebra

function simplex(c, A, b, ind_B_inicial, ind_N_inicial)
    ind_B = copy(ind_B_inicial)
    ind_N = copy(ind_N_inicial)

    iteracao = 1

    while true
        println("\n --- Iteração $iteracao ---")

        # vetor de custos das variáveis básicas
        c_B = c[ind_B]
        # vetor de custos das váriaveis não-básicas
        c_N = c[ind_N]

        # partições básicas
        B = A[:, ind_B]
        N = A[:, ind_N]

        # PASSO 1: CÁLCULO DA SOLUÇÃO BÁSICA
        x_B = B \ b

        # PASSO 2: CÁLCULO DOS CUSTOS RELATIVOS
        # 2.1 - vetor multiplicador simplex
        lambda_vec = B' \ c_B

        # 2.2 - custos relativos
        c_hat = c_N - N' * lambda_vec

        # 2.3 - determinar a variável a entrar na base
        valor_min, pos_k = findmin(c_hat)

        # PASSO 3: TESTE DE OTIMALIDADE
        if valor_min >= -1e-7
            fx = c_B' * x_B
            println("-> Fim do algoritmo.")

            # verificar a possibilidade de existir soluções ótimas múltiplas (como no exemplo 2.27)
            if any(c_hat .<= 1e-7)
                println("É possível que esse problema tenha soluções ótimas múltiplas.")
            else
                println("Solução ótima única encontrada.")
            end

            println("Valor da função objetivo f(x): ", fx)
            break
            
        else
            k = pos_k # posição (no vetor N) da variável que vai entrar na base

            # PASSO 4: DIREÇÃO SIMPLEX
            a_Nk = N[:, k] # extrair a coluna onde está a variável que vai entrar na base
            y = B \ a_Nk   # resolver o sistema pra By = a_Nk

            # PASSO 5: DETERMINAÇÃO DO PASSO E VARIÁVEL A SAIR
            x_B = B \ b

            epsilon = Inf   # inicia supondo que o passo pode ser infinito e nenhuma variável sai
            pos_l = 0       # posição da variável a sair da base

            # percorre cada posição do vetor y
            for i in 1:length(y)
                if y[i] > 1e-7
                    razao_atual = x_B[i] / y[i]
                    
                    # se essa divisão for menor que o nosso epsilon atual, a variável é atualizada
                    if razao_atual < epsilon
                        epsilon = razao_atual
                        pos_l = i   # variável que gerou esse menor valor
                    end
                end
            end

            # se o epsilon continuou infinito, é porque nenhum y era > 0
            if epsilon == Inf
                println("-> Fim do algoritmo.")
                println("O problema não tem solução ótima.")
                break

            else
                fx = c_B' * x_B
                println("A variável x_", ind_N[pos_k], " entra na base valendo ", epsilon)
                println("A variável x_", ind_B[pos_l], " sai da base.")
                println("Valor da função objetivo f(x): ", fx)

                # PASSO 6: atualização nova partição básica
                variavel_entrando = ind_N[pos_k]
                variavel_saindo = ind_B[pos_l]
                
                ind_B[pos_l] = variavel_entrando
                ind_N[pos_k] = variavel_saindo
            end
        end
        iteracao += 1
    end
end

# TESTE DO EXEMPLO 2.26 (Solução Ótima Única)
println("\nTESTANDO EXEMPLO 2.26")
c_226 = [-1.0, -2.0, 0.0, 0.0, 0.0]
A_226 = [ 1.0  1.0  1.0  0.0  0.0;
          1.0 -1.0  0.0  1.0  0.0;
         -1.0  1.0  0.0  0.0  1.0]
b_226 = [6.0, 4.0, 4.0]
B_idx_226 = [3, 4, 5]
N_idx_226 = [1, 2]

simplex(c_226, A_226, b_226, B_idx_226, N_idx_226)

# TESTE DO EXEMPLO 2.27 (Soluções Ótimas Múltiplas)
#println("\nTESTANDO EXEMPLO 2.27")
#c_227 = [-1.0, -1.0, 0.0, 0.0, 0.0]
#A_227 = [ 1.0  1.0  1.0  0.0  0.0;
#          1.0 -1.0  0.0  1.0  0.0;
#         -1.0  1.0  0.0  0.0  1.0]
#b_227 = [6.0, 4.0, 4.0]
#B_idx_227 = [3, 4, 5]
#N_idx_227 = [1, 2]
#
#simplex(c_227, A_227, b_227, B_idx_227, N_idx_227)
#
## TESTE DO EXEMPLO 2.28 (Problema se solução ótima - solução ilimitada)
#println("\nTESTANDO EXEMPLO 2.28")
#c_228 = [-1.0, -1.0, 0.0, 0.0]
#A_228 = [ 1.0 -1.0  1.0  0.0;
#         -1.0 1.0  0.0  1.0]
#b_228 = [4.0, 4.0]
#B_idx_228 = [3, 4]
#N_idx_228 = [1, 2]
#
#
#simplex(c_228, A_228, b_228, B_idx_228, N_idx_228)
#
