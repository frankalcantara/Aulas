/*
SUPER SIMPLES 1
Baseado no trabalho de 	Milind Kulkarni
*/

/*
{x} : x is opcional
símbolos em letras maiúsculas são terminais
símbolos em letras minúsculas são não terminais.
espaços e identação são ignorados.
a gramática usa regras do tipo: A->wB
*/

/* Programa */
program->PROGRAM id BEGIN pgm_body END
id->IDENTIFIER
pgm_body->decl func_declarations
decl->string_decl_list{ decl } | var_decl_list{ decl } | empty

/* Declaração de strings */
string_decl_list->string_decl{ string_decl_tail }
string_decl->STRING id : = str; | empty
str->STRINGLITERAL
string_decl_tail->string_decl{ string_decl_tail }

/* declaração de variáveis */
var_decl_list->var_decl{ var_decl_tail }
var_decl->var_type id_list; | empty
var_type->FLOAT | INT
any_type->var_type | VOID
id_list->id id_tail
id_tail->, id id_tail | empty
var_decl_tail->var_decl{ var_decl_tail }

/* parametros de funções */
param_decl_list->param_decl param_decl_tail
param_decl->var_type id
param_decl_tail   ->, param_decl param_decl_tail | empty

/* declaração de funções */
func_declarations->func_decl{ func_decl_tail }
func_decl->FUNCTION any_type id({ param_decl_list }) BEGIN func_body END | empty
func_decl_tail->func_decl{ func_decl_tail }
func_body->decl stmt_list

/* declarações */
stmt_list->stmt stmt_tail | empty
stmt_tail->stmt stmt_tail | empty
stmt->base_stmt | if_stmt | do_while_stmt
base_stmt->assign_stmt | read_stmt | write_stmt | return_stmt
assign_stmt->assign_expr;
assign_expr->id : = expr
read_stmt->READ(id_list);
write_stmt->WRITE(id_list);
return_stmt->RETURN expr;

/* Expressões */
expr->factor expr_tail
expr_tail->addop factor expr_tail | empty
factor->postfix_expr factor_tail
factor_tail->mulop postfix_expr factor_tail | empty
postfix_expr->primary | call_expr
call_expr->id({ expr_list })
expr_list->expr expr_list_tail
expr_list_tail->, expr expr_list_tail | empty
primary-> (expr) | id | INTLITERAL | FLOATLITERAL
addop-> + | -
mulop-> * | /

/* condicionais */
if_stmt->IF(cond) { decl } stmt_list else_part ENDIF
else_part->ELSIF(cond) { decl } stmt_list else_part | empty
cond->expr compop expr | TRUE | FALSE
compop-> < | > | = | != | <= | >=

/* laço while */
do_while_stmt->DO{ decl } stmt_list WHILE(cond);

/* Continue e Break*/
aug_stmt_list->aug_stmt aug_stmt_list | empty
aug_stmt->base_stmt | aug_if_stmt | do_while_stmt | CONTINUE; | BREAK;

/*
Todos os identificadores começam com letras com comprimento máximo de 30
Os identificadores são sensíveis as letras maiúsculas e minúsculas.
*/

/* Complementos
INTLITERAL: número inteiros
    ex.) 0, 5, 123678
FLOATLITERAL: ponto flutuante disponível em duas formas
    yyyy.xxxxxx or .xxxxxxx
    ex.) 3.1415926, .21, .0007

STRINGLITERAL(máximo 80 caracteres incluíndo a marca de fim: '\0')
qualquer símbolo pode ser usado nas strings exceto '"'

    ex.) "Hello world!", "***********", "imprime na tela"

COMMENT:
começam com "--" e valem até o fim da linha
ex.)-- isto será um comentário

KEYWORDS

PROGRAM, BEGIN, END, FUNCTION, READ, WRITE,
IF, ELSIF, ENDIF, DO, WHILE, CONTINUE, BREAK,
RETURN, INT, VOID, STRING, FLOAT,
TRUE, FALSE

0PERADORES
    : = + - * / = != < > ( ) ; , <= >=


EXEMPLO 1
PROGRAM fibonacci
   BEGIN
       STRING input := "Digite um INTEIRO: ";
       STRING space := " ";
       STRING eol := "\n";

       FUNCTION INT F (INT n)
       BEGIN
           IF (n > 2)
                RETURN F(n-1)+F(n-2);
           ELSIF (n = 0)   --VEJA UM COMENTÁRIO!!!
               RETURN 0;
           ELSIF (n = 1)
               RETURN 1;
           ELSIF (n = 2)
               RETURN 1;
            ENDIF
       END

       FUNCTION VOID main ()
       BEGIN
           INT i, end, result;
           WRITE(input);
           READ(end);

       i := 0;
       DO
           result := F(i);
           WRITE (i,space);
           WRITE (result,eol);
           i := i + 1;
       WHILE (i != end);
       END
   END

EXEMPLO 2
PROGRAM laço
BEGIN

     STRING palpite := "Adivinhe o número: ";
     STRING correto := "Correto!\n";
     STRING errado := "Errado!\n";
     STRING msg1 := "Você tentou  ";
     STRING msg2 := " vezes";

    INT i;
    INT j;

    PROTO VOID main();

    FUNCTION VOID main()
    BEGIN
        i := 17;
        j := 0;
        k := 0;
        DO
            WRITE(palpite);
            READ(j);
            k := k + 1;
            IF (i = j)
                 WRITE(correto);
                 BREAK;
            ELSIF (TRUE)
                 WRITE(errado);
            ENDIF
        WHILE (TRUE);

        WRITE (msg1, k, msg2);
    END
END
*/