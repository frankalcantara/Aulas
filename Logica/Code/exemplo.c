//este é um exemplo em prolog
professor(paulo,calculo).
professor(ana,eletromag).
professor(silvia,logica).
matriculado(marcos,calculo).
matriculado(joana,eletromag).
matriculado(joana,logica).
matriculado(lucas,calculo).
matriculado(lucas,logica).


/** <explica>
predicado ensina será verdadeiro se existe um professor da disciplina C e um aluno S está matriculado em C

*/

ensina(P,S) :- professor(P,C), matriculado(S,C).