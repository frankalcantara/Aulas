---
author: Frank Coelho de Alcantara
title: Lógica, Introdução e Cálculo Proposicional 
data: 6 de agosto, 2020
version: 0.5 
---

# Introdução {.P}

<style> 
p {
    text-align: justify !important;
}
h1{ font-size: 1.9em !important;}
h2{ text-align: left !important; font-size: 1.6em !important;}
strong {
    color:antiquewhite;
}
.reveal img, .reveal video, .reveal iframe {
    max-width: 60%;
    max-height: 60%;
}

.reveal img {
  display: block;
  margin-left: auto;
  margin-right: auto;
}
.reveal.cube .slides section:not(.stack):before {
    background: inherit !important;
}

.reveal blockquote {
    display: block;
    position: relative;
    width: 90% !important;
    padding: 5%;
}

.reveal table {
    font-size: 70% !important;
}
.reveal ul {
    font-size: 70% !important;
}
.katex .base {
   color: antiquewhite !important;
}
</style>


<hr> 

> "Logic is the technique by which we add conviction to truth." </br> Jean de la Bruyere {.P}

<hr> 

## Ciência e Filosofia {.P}

<hr> 

A lógica é a ciencia da _avaliação sistemática de argumentos_ em busca do convencimento. A Lógica busca o convencimento, a certeza, na forma dos argumentos e não conteúdo destes argumentos. Busca a verdade pela análise de um argumento em relação a outro, de forma racional, formal e estruturada. {.P} 

Existem duas formas de se estudar lógica: formal e filosófica. A lógica formal está tão enraizada na sociedade ocidental que ser considerado ilógico é uma espécie de ofensa. Maximize a ofensa se for da minha geração que cresceu assistindo as deduções do _Sr.Spock_. A lógica está em tudo praticamente tudo que fazemos. Usamos a lógica para justificar conceitos, definir teorias e reforçar observações sobre o mundo e o que fazemos nele. Usamos a lógica para concluir e para convencer outras pessoas das nossas conclusões. Como se diz popularmente, _quanto mais frágil o argumento mais alta a voz_.

Neste livro, vamos nos dedicar a lógica formal, matemática, para uso na resolução de problemas computacionais e como suporte ao estudo da inteligência artificial. Vamos estudar lógica proposicional, ou cálculo proposicional, e lógica predicativa, ou cálculo predicativo. A leitora há de entender e perdoar mas, neste livro usarei os termos cálculo proposicional e cálculo predicativo. Não é nenhuma fixação com a matemática é apenas para manter este estudo dentro da ciência da computação e para explicitar, desde já, que estudaremos __provas matemáticas__. 

A lógica, diferentemente do português, inglês ou madarim, é uma linguagem artificialmente criada sobre uma estrutura matemática para permitir a análise de argumentos, garantir que esta análise seja compreendida por qualquer um que conheça a linguagem, e encontrar a verdade, ou não. Este é o ponto principal, definir que um determinado argumento é verdadeiro, ou falso. Dando a mesma importância a qualquer um dos resultados desde que o resultado seja verdadeiro, ainda que o argumento seja falso. Ficou complicado? A amável leitora pode definir a lógica como sendo a ciência da avaliação de argumentos. Nesta ciência temos dois resultados possíveis para cada argumento, eles podem ser verdadeiros ou falsos. A lógica quer encontrar esta convicção, esta certeza, a verdade absoluta sobre um argumento, seja ele verdadeiro ou falso.

Os argumentos, no que concerne a lógica, são grupos de sentenças que suportam um raciocínio específico, chamadas de __premissas ou proposições__ e uma sentença que representa a conclusão lógica obtida a partir das premissas, criativamente chamada de __conclusão__. Mais tarde veremos que todos os argumentos possuem uma __conclusão__ mas, nem todos os argumentos têm __premissas__. O conjunto de premissas pode ser vazio. Coisas de matemática que fazem a lógica tão interessante e poderosa. Em busca da verdade, é função da lógica avaliar estes argumentos.

A avaliação dos argumentos é a função principal da lógica e esta avaliação é feita a luz do raciocínio. Suponha que você suporte o seguinte argumento: _todos os filósofos são inteligentes_ e que em uma festa seu amigo Paulo lhe apresente a Jéssica com a sentença: _Jéssica é filósofa_. A conclusão lógica e irrefutável é que _Jéssica é inteligente_. Este é nosso primeiro exemplo de cálculo proposicional. Duas __proposições__, ou premissas, se preferirem levam invariávelmente a uma __conclusão__. Podemos contestar estas proposições em busca da sua veracidade, ou não. Por exemplo, podemos discutir se é verdade que todos os filósofos são inteligentes. Mas, neste caso, teríamos que ter __argumentos__ para avaliar a verdade de _todos os filósofos são inteligentes_, ou ainda verficiar se é verdade que _Jéssica é filósofa_. Contudo, se consideramos que as duas __proposições__ são válidas, somos forçados, pela lógica, a inferir que _Jéssica é inteligente_ e, além de nosso primeiro exemplo de __cálculo proposicional__ acabamos de ver o nosso primeiro exemplo de __inferência__. Antes de nos aprofundarmos nestes conceitos, um pouco de história.

<hr> 

## Um pouco de História {.P}

<hr> 

O estudo da lógica começa com [Aristóteles (384 A.C. –322 A.C.)](https://en.wikipedia.org/wiki/Aristotle) {.P}

Aristóteles era filho do médico do rei da Macedônia e órfão ainda jovem, Aristóteles foi criado em um ambiente rico e aprendeu poesia e retórica e teve o previlégio de frequentar a Academia de Platão. Estão nos tratados de Aristóteles os primeiros registros da lógica. Ainda na Grécia antiga e lógica floresceu na Escola de Megara onde se estudavam quebra-cabeças lógicos e acabaram por definir o conceito de paradoxo, encontrando alguns, que veremos quando for o caso e na Escola Stoica.

Na Escola Estoica, [Diodorus Cronus](https://en.wikipedia.org/wiki/Diodorus_Cronus), um dos professores, desenvolveu o racioníno lógico baseado em três silogismos onde o terceiro indica a conclusão. O mesmo raciocínio que vimos no exemplo da Jéssica. Não temos muita certeza sobre a relação entre Cronus e Aristóteles cremos que Cronus tenha influenciado Aristóteles na criação da lógica, talvez como um contemporâneo mais velho ou como um concorrente.  

Aristóteles havia proposto os silogismos, uma aproximação linguística da lógica. Cabe a Cronus a estruturação do cálculo proposicional.

Depois de Aristoteles, Cronus e seus contemporâneos a lógica dormiu por quase dois mil anos até que no fim do Século XIX o imperialismo britânico permitiu que a lógica voltasse a florescer. Este florescimento moderno começa nos trabalhos de Leibniz.

[Leibniz](https://en.wikipedia.org/wiki/Gottfried_Wilhelm_Leibniz) que além de ajudar no desenvolvimento do cálculo, e dos números binários, definiu os conceitos de conjunção, disjunção, negação e identidade, as operações fundamentais do Cálculo Proposicional. {.P}

[George Boole](https://en.wikipedia.org/wiki/George_Boole), em 1854 _The Laws of Thought_ apresentando o que conhecemos hoje como __Algebra Booleana__. {.P}

Agora, neste ponto da história temos o conceito de proposição, operações matemáticas que podem ser feitas com estas proposições e uma algebra de adequada a um sistema de numeração adequado a operar entre os conceitos de verdadeiro e falso. A base da tecnologia computacional que usamos hoje estava definida no anos de 1854. O próximo passo importante neste caminho é o Paradoxo de Russel. Mas antes, o que é um paradoxo?

<hr/>

## Paradoxo {.P}

<hr/>

Paradoxo é uma sentença que não tem a verdade bem definida, se a sentença for verdadeira, o argumento é falso. Se a sentença for falsa, o argumento é verdadeiro. {.P}

O paradoxo do mentiroso, que pode ser ligado as escolas gregas de filosofia, pode ser demonstrado com a declaração: __esta declaração é falsa__. {.P}

E deixo que a leitora responda, a sentença em destaque neste parágrafo é verdadeira ou falsa? Só seja honesta e responda antes de ler a continuação.

Existem algumas considerações que devemos fazer. Vamos, antes de qualquer coisa chamar a declaração __esta sentença é falsa__ de premissa. Se a premissa é verdadeira, então __esta declaração é falsa__ é verdadeira. Portanto, a declaração deve ser falsa. A hipótese de que a premissa é verdadeira leva à conclusão de que a declaração é falsa, ou seja, existe uma contradição. Ou se a leitora ainda não estiver tonta, podemos considerar que a premissa é falsa. Neste caso, __esta declaração é falsa__ é falsa. Portanto a premissa deve ser verdadeira. A hipótese que a premissa é falsa leva a conclusão que __esta declaração é falsa__ é verdadeira, outra contradição. Se a premissa não é verdadeira nem falsa, temos um paradoxo.

<hr/> 

## Bertand Russel {.P}

<hr/> 

[Bertrand Russel](https://en.wikipedia.org/wiki/Bertrand_Russell) (1872 – 1970) pretenciosamente tentou reescrever toda a matemática a partir dos conceitos de conjuntos e fracassou ao encontrar um dos mais famosos paradoxos da história da matemática. {.P}

Esta pretensão não era exclusiva de Russell, outros matemáticos antes dele, e alguns depois, perseguiram este objetivo. Entre estes destaca-se [Kurt Gödel](https://en.wikipedia.org/wiki/Kurt_G%C3%B6del) cujo trabalho tem impacto direto na computação e será estudado neste livro.  

Russell estudou filosofia, matemática e lógica. Em 1901, estudando a Teoria dos Conjuntos de Cantor, encontou um paradox na definição de conjuntos. O mesmo paradoxo já havia sido estudado, mas não publicado por Ernst Zermelo em 1899 e pelo próprio Georg Cantor em 1890. Contudo, atribuímos este paradoxo a Russell graças a sua publicação. Ainda assim, a tentativa de Russell registrada no livro __Principia Mathematica__ contribui definitivamente para o formalismo da lógica como parte da matemática. A simbologia de linguagem da lógica que adotamos neste livro tem origem no __Principia Mathematica__ de Bertrand Russel e Alfred North Whitehead.

<hr/> 

## O Paradoxo de Russell {.P} 

Considere $A$ como o conjunto formado por todos os conjuntos que não contém a si mesmos. De tal forma que: $A=\{S|S \notin S\}$ {.P}

Seria $A$ um elemento de si mesmo? Seria o conjunto $A$ um elemento do conjunto dos conjuntos que não contém a si mesmos? {.P}

Vamos pensar um pouco sobre isso. Se $A$ é um elemento $A$ isso significa que ele é um elemento de si mesmo. Logo, pela própria definição de $A$ ele não poderia conter a si mesmo, já que $A$ é o conjunto de conjuntos que não contém a si mesmos. Como esta opção é impossível, devemos concluir que $A$ não é um elemento de si mesmo. Mas, se ele não contém a si mesmo. Ele precisa, necessariamente, ser um elemento do conjunto dos cojuntos que não contém a si mesmo. E pronto, lá se foi a teoria dos cojuntos por água abaixo, levando consigo uma parte importante do cérebro deste pobre autor.

<hr/>

<!-- fazer aqui a definição do paradoxo de russel segundo o matheus sugeriu -->

# Cálculo Proposicional {.P}

<hr/>

No __Cálculo Proposicional__ vamos usar as proposições como operandos em expressões lógicas. {.P}. 

A proposição, é uma declaração, na forma de sentença, que é verdadeira __ou__ falsa. {.P}

Anteriormente, nos referimos as proposições como premissas, estes termos podem ser usados de forma livre para significar a mesma coisa, pelo menos neste livro. Ou seja, a proposição é uma declaração cuja verdade só pode ser demonstrada entre um de dois estados diferentes. Ou a proposição é verdadeira, ou é falsa. Uma proposição jamais será verdadeira e falsa e, da mesma forma uma proposição não poderá ser nem verdadeira e nem falsa. Este é o sentido do conector __ou__ este conector, significa que só pode existir um dos dois estados possíveis.

O __Cálculo Proposicional__ é a parte da lógica que estuda a existência das proposições, a criação de proposições simples (ou atômicas), a criação de proposições complexas (ou compostas). As preposições podem ser combinadas, por meio de operadores, cinco no total, para formar novas proposições. 

<hr/>

## Exemplos de Proposição (1) {.P}

<hr/>

1. Lima é a Capital da China. 
2. Paris é a Capital da França. 
3. $1+2=3$ 
4. Todos os gatos são animais. {.P}

<hr/>

Todas as declarações do exemplo 1 são proposições. Todas estas sentenças, ou são verdadeiras (2 e 4), ou falsas (1, 3) e não resta dúvida sobre a verdade de cada uma destas declarações. Estas proposições também são atômicas, ou simples, elas estão contidas em si mesmo e podem ser representadas por variáveis. No Cálculo Proposicional usamos letras minúsculas para representar as proposicões. As letras $p,q,r,s,t$ são as letras que usaremos com mais frequencia neste livro.  Também usaremos as letras $T$ para representar verdadeiro e $F$ para representar falso como símbolos para indicar a verdade de uma determinada proposição. Assim voltando ao Exemplo 1 temos:

## Exemplos de Proposição (1) {.P}

<hr/>

1. $p = \text{Lima é a Capital da China.} | p = F$
2. $q = \text{Paris é a Capital da França.} | q = T$
3. $r = \text{1+2=3} | r = F$
4. $s = \text{Todos os gatos são animais.} | s = T$ {.P}

<hr/>

## Exemplos de Proposição (2) {.P}

<hr/>

Toda proposição é uma sentença mas, nem toda sentença é uma proposição. {.P}

1. Escreva este texto ainda hoje.
2. $x+4=6$ {.P}

<hr/>

A sentença um não é uma proposição por que não é uma declaração e a sentença 2 não é porque não temos como garantir se ela é verdadeira ou falsa. Observe que, no momento em que atribuirmos um valor a $x$, poderemos definir se a sentença 2 é verdadeira ou falsa e teremos uma proposição.

## Cálculo Proposicional Operador unário {.P}

<hr/>

Temos um e apenas um operador unário em cálculo proposicional, o operador de negação representando por $\neg$. {.P}

Se uma proposição é verdadeira a aplicação deste operador a transforma em falsa e vice-versa. Podemos usar este operador quantas vezes for necessário, sempre a frente de proposição que estamos operando $\neg q$ {,P}

- $q = T$ logo $\neg q = F$ {,P}
- $r = F$ logo $\neg \neg r = F$ {,P}

<hr/>

## Cálculo Proposicional Operador Binário {.P}
<hr/>

Temos quatro operadores binários. {.P}

- A conjunção ou operador E (_and_) representado por $\land$ tal que: $(p \land q)$
- A disjunção ou operador Ou (_or_) representado por $\lor$ tal que: $(p \lor q)$
- A condicional representada pelo operador $\to$ tal que: $(p \to q)$
- A Bi-condicional representada pelo operador $\leftrightarrow$ {.P} tal que: $(p \leftrightarrow q)$

<hr/>
<!--  colocar aqui exemplos destas operações. -->

# Material de apoio {.P}

<hr> {.P}

Você pode baixar a versão em pdf desta aula [clicando aqui](./1-Apresenta.pdf) {.P}

<hr> {.P}

# Obras Citadas {.P}

<small>


</small>


