/*
* Programa para analisar lexicamente
* um streaming de símbolos originados
* no teclado. O programa demonstra o processo
* exemplificado no Capítulo 2 do Livro. Este 
* exemplo reconhece apenas <, >, >=, <=. =
* e iginora se existema digitos, letras ou outros
* símbolos. O Objetivo é mostrar como é simples 
* codificar um diagrama de transição.
* Author: Frank C. de Alcantara
* Data: 20/03/2017
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

#define OP = 1
#define EQ = 2
#define GT = 3
#define LT = 4
#define GE = 5
#define LE = 6

/* 
	Protótipos das funções utilizada 
*/
void iniciar(char *);
void proximo(char *);

void estado0(char *);
void estado1(char *);
void estado2(char *);
void estado3(char *);
void estado4(char *);
void estado5(char *);
void estado6(char *);
void estado7(char *);

int main()
{
    // para inicializar o ponteiro
    char coisa = ' ';
    char *look;
    look = &coisa;
    *look = ' ';

    iniciar(look);

    getchar();
    return 0;
}

/* 
* Estado inicial do analisador léxico
* chamada todas as vezes que voltamos a 
* este estado inicial
*/
void iniciar(char *look)
{
    proximo(look);
    if (*look == '\n')
    {
        getchar();
        exit(1);
    }
    estado0(look);
}

/* 
* Para ler o próximo caracter de entrada 
*/
void proximo(char *look)
{
    *look = getchar();
}

/*
* Estado Inicial, 
* reconhece os caracteres e distribui para
* os próximos estágios.
*/
void estado0(char *look)
{

    switch (*look)
    {
    case '<':
        proximo(look);
        estado1(look);
        break;
    case '>':
        proximo(look);
        estado5(look);
        break;
    case '=':
        estado4(look);
        break;
    default:
        iniciar(look);
        break;
    }
}
/*
* Todos os outros estados. 
*/

void estado1(char *look)
{
    switch (*look)
    {
    case '=':
        estado2(look);
        break;
    default:
        estado3(look);
        ;
        break;
    }
}
void estado2(char *look)
{
    printf("Os simbolos <=, geraram o token %s", "<OP, LE>\n");
    iniciar(look);
}
void estado3(char *look)
{
    printf("O simbolo <, gerou o token %s", "<OP, LT>\n");
    iniciar(look);
}
void estado4(char *look)
{
    printf("O simbolo =, gerou o token %s", "<OP, EQ>\n");
    iniciar(look);
}
void estado5(char *look)
{
    switch (*look)
    {
    case '=':
        estado7(look);
        break;
    default:
        estado6(look);
        break;
    }
}
void estado6(char *look)
{
    printf("O simbolo >, gerou o token %s", "<OP, GT>\n");
    iniciar(look);
}
void estado7(char *look)
{
    printf("Os simbolos >=, geraram o token %s", "<OP, GE>\n");
    iniciar(look);
}
