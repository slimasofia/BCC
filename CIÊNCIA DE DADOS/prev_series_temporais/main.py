import pandas as pd
from sklearn.linear_model import LinearRegression
from sklearn.model_selection import TimeSeriesSplit
from sklearn.metrics import root_mean_squared_error

# --- CARREGAMENTO E TRATAMENTO ---

# importa o arquivo CSV bruto para dentro de um DataFrame do pandas
df = pd.read_csv('itsa4_data_1004.csv')
# converte a coluna de texto para o formato nativo de datas do Python
df['Date'] = pd.to_datetime(df['Date'])
# desconsidera datas antes de 01/01/2025
df = df[df['Date'] >= '2025-01-01']
# ordena cronologicamente para garantir que o modelo aprenda o fluxo correto do tempo
df = df.sort_values('Date').reset_index(drop=True)

# criando as features
# são as variáveis de entrada que darão o contexto matemático para o modelo

df['MA7'] = df['Price'].rolling(window=7).mean()   # Média móvel curta: identifica a tendência de preços da última semana
df['Lag_1'] = df['Price'].shift(1)                 # traz o preço de fechamento de ontem para ser a âncora da linha de hoje
df['Retorno'] = df['Price'].pct_change()           # Variação percentual: mede o ganho ou perda de força da ação de um dia para o outro
df['Amplitude'] = df['High'] - df['Low']           # mede se o pregão foi calmo ou agitado
df['Var_Dia'] = df['Price'] - df['Open']           # verifica se a ação ganhou ou perdeu valor durante o horário de negociação
df['MA21'] = df['Price'].rolling(window=21).mean() # Média móvel longa: identifica a tendência consolidada do último mês útil

# criando os alvos (o que aconteceu no dia seguinte)
df['Target_Close'] = df['Price'].shift(-1)
df['Target_Open'] = df['Open'].shift(-1)

# cálculos de médias e shifts criam valores nulos nas bordas da tabela
# remove as linhas com NaN e separa os dados para evitar erros matemáticos no treinamento
df_limpo = df.dropna().reset_index(drop=True)

#'X' contém as pistas do dia e 'y' contém as respostas (o preço do dia seguinte)
features = ['MA7', 'Lag_1', 'Retorno', 'Amplitude', 'Var_Dia', 'MA21']
X = df_limpo[features]
y_close = df_limpo['Target_Close']
y_open = df_limpo['Target_Open']

# --- TREINAMENTO (K-Fold Cross Validation) ---

# criação dos modelos
mod_close = LinearRegression()
mod_open = LinearRegression()

# técnica de validação temporal exigida
# divide o conjunto de dados em 5 blocos sequenciais, garantindo que o passado sempre treine o futuro (evitando vazamento de dados)
tscv = TimeSeriesSplit(n_splits=5)

# treinando o modelo de fechamento
# o loop iterativo ajusta a equação da reta para minimizar a margem de erro entre as pistas (X) e o alvo (y_close)
for train_idx, test_idx in tscv.split(X):
    mod_close.fit(X.iloc[train_idx], y_close.iloc[train_idx])

# treinando o modelo de abertura
for train_idx, test_idx in tscv.split(X):
    mod_open.fit(X.iloc[train_idx], y_open.iloc[train_idx])

# --- PREVISÃO PARA O PRÓXIMO DIA ---

# pega a última linha real baixada hoje para prever o amanhã
dados_hoje = X.tail(1)

# aplica as variáveis extraídas na equação matemática ajustada durante o treinamento para obter o valor futuro
prev_c = mod_close.predict(dados_hoje)
prev_o = mod_open.predict(dados_hoje)

print("\n" + "="*40)
print(f"RESULTADOS PARA O PRÓXIMO PREGÃO:")
print(f"Previsão ABERTURA:   R$ {prev_o[0]:.2f}")
print(f"Previsão FECHAMENTO: R$ {prev_c[0]:.2f}")
print("="*40)