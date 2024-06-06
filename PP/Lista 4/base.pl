pai(joao, maria).
pai(joao, pedro).
pai(joao, marcos).
pai(joao, joana).
pai(pedro, ricardo).
pai(pedro, bruno).
pai(bruno, victor).

sexo(maria, feminino).
sexo(joana, feminino).
sexo(joao, masculino).
sexo(pedro, masculino).
sexo(marcos, masculino).
sexo(ricardo, masculino).
sexo(bruno, masculino).
sexo(victor, masculino).

irmao(X,Y) :- X\==Y, pai(Z,X), pai(Z,Y), sexo(X, masculino).
irma(X,Y) :- X\==Y, pai(Z,X), pai(Z,Y), sexo(X,feminino).

neto(X,Y) :- pai(Z,X), pai(Y,Z), sexo(X,masculino).
neta(X,Y) :- pai(Z,X), pai(Y,Z), sexo(X,feminino).

bisneto(X,Y):- pai(Y,B), pai(A,X), pai(B,A),sexo(X,masculino).

aluno(pedro).
aluno(marcos).
aluno(julia).
aluno(carla).

nota(pedro, 5).
nota(marcos, 9).
nota(julia, 7).
nota(carla, 6).

frequencia(pedro, 50).
frequencia(marcos, 90).
frequencia(julia, 80).
frequencia(carla, 95).

passou(X) :- aluno(X), nota(X,Y), Y>=7.
passou2(X) :- aluno(X), nota(X, Y), Y>=7, frequencia(X,Z), Z>=75.
