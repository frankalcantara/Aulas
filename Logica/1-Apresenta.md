---
author: Frank Coelho de Alcantara
title: Lógica, Introdução e Cálculo Proposicional 
data: 6 de agosto, 2020
version: 0.5 
---

# Introdução {.P}

<style> 
p { text-align: justify !important; }
h1{ font-size: 1.9em !important;}
h2{ text-align: left !important; font-size: 1.6em !important;}
strong { color:antiquewhite; }
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
.reveal table { font-size: 70% !important; }
.reveal ul { font-size: 70% !important; }
.katex .base { color: antiquewhite !important; }

.sy{font-size:1.2em !important; text-align:left !important;}
</style>

<hr> 

> "Logic is the technique by which we add conviction to truth." </br> Jean de la Bruyere {.P}

<hr> 

## Ciência e Filosofia {.P}

<hr> 

A lógica é a ciencia da _avaliação sistemática de argumentos_ em busca do convencimento. A Lógica busca o convencimento, a certeza, na forma dos argumentos e não conteúdo destes argumentos. Busca a verdade pela análise de um argumento em relação a outro, de forma racional, formal e estruturada. {.P}

Existem duas formas de se estudar lógica: formal e filosófica. A lógica formal está tão enraizada na sociedade ocidental que ser considerado ilógico é uma espécie de ofensa. Maximize a ofensa se for da minha geração que cresceu assistindo as deduções do _Sr.Spock_. A lógica está em praticamente tudo que fazemos. Usamos a lógica para justificar conceitos, definir teorias e reforçar observações sobre o mundo e o que fazemos nele. Usamos a lógica para concluir e para convencer outras pessoas das nossas conclusões. Como se diz popularmente, _quanto mais frágil o argumento mais alta a voz_. Talvez, seja melhor usar a lógica que gritos, ou bombas, para fazer valer a sua opinião.

Neste livro, vamos nos dedicar a lógica formal, matemática, para uso na resolução de problemas computacionais e como suporte ao estudo da inteligência artificial. Vamos estudar lógica proposicional, ou __cálculo proposicional__, e lógica predicativa, ou __cálculo predicativo__. A leitora há de entender e perdoar mas, neste livro usarei os termos __cálculo proposicional__ e __cálculo predicativo__. Não é nenhuma fixação com a matemática é apenas para manter este estudo dentro da ciência da computação e para explicitar, desde já, que estudaremos __provas matemáticas__. A lógica matemática e computacional, não está só enteressada no convencimento, este convencimento deve ser uma __prova irrefutável da verdade__.

A lógica, diferentemente do português, inglês ou madarim, é uma linguagem artificialmente criada sobre uma estrutura matemática para permitir a análise de argumentos, garantir que esta análise seja compreendida por qualquer um que conheça a linguagem, e encontrar a verdade, ou não. 

O encontro da verdade, mais que isso a prova da verdade, é o ponto principal de todo este esforço de construção do pensamenta. Definir que um determinado argumento é verdadeiro, ou falso. Dando a mesma importância a qualquer um dos resultados desde que o resultado seja verdadeiro, ainda que o argumento seja falso. Ficou complicado? A amável leitora pode definir a lógica como sendo a ciência da avaliação de argumentos. Nesta ciência temos dois resultados possíveis para cada argumento, eles podem ser verdadeiros ou falsos. A lógica quer encontrar esta convicção, esta certeza, a verdade absoluta sobre um argumento, seja ele verdadeiro ou falso.

Os argumentos, no que concerne a lógica, são grupos de sentenças que suportam um raciocínio específico, chamadas de __premissas ou proposições__ e uma sentença que representa a conclusão lógica obtida a partir das premissas, criativamente chamada de __conclusão__. Mais tarde veremos que todos os argumentos possuem uma __conclusão__ mas, nem todos os argumentos têm __premissas__. O conjunto de premissas pode ser vazio. Coisas de matemática que fazem a lógica tão interessante e poderosa. Em busca da verdade, é função da lógica avaliar estes argumentos.

A avaliação dos argumentos é a função principal da lógica e esta avaliação é feita a luz do raciocínio. Suponha que você suporte o seguinte argumento: _todos os filósofos são inteligentes_ e que em uma festa seu amigo Paulo lhe apresente a Jéssica com a sentença: _Jéssica é filósofa_. A conclusão lógica e irrefutável é que _Jéssica é inteligente_. Este é nosso primeiro exemplo de cálculo proposicional. Duas __proposições__, ou premissas, se preferirem levam invariávelmente a uma __conclusão__. Podemos contestar estas proposições em busca da sua veracidade, ou não. Por exemplo, podemos discutir se é verdade que todos os filósofos são inteligentes. Mas, neste caso, teríamos que ter __argumentos__ para avaliar a verdade de _todos os filósofos são inteligentes_, ou ainda verficiar se é verdade que _Jéssica é filósofa_. Contudo, se consideramos que as duas __proposições__ são válidas, somos forçados, pela lógica, a inferir que _Jéssica é inteligente_ e, além de nosso primeiro exemplo de __cálculo proposicional__ acabamos de ver o nosso primeiro exemplo de __inferência__. Antes de nos aprofundarmos nestes conceitos, um pouco de história.

<hr> 

## Um pouco de História {.P}

<hr> 

O estudo da lógica começa com [Aristóteles (384 A.C. –322 A.C.)](https://en.wikipedia.org/wiki/Aristotle) {.P}

Aristóteles era filho do médico do rei da Macedônia e órfão ainda jovem, Aristóteles foi criado em um ambiente rico e aprendeu poesia e retórica e teve o previlégio de frequentar a Academia de Platão. Estão nos tratados de Aristóteles os primeiros registros da lógica. Ainda na Grécia antiga e lógica floresceu na Escola de Megara onde se estudavam quebra-cabeças lógicos e acabaram por definir o conceito de paradoxo, encontrando alguns, que veremos quando for o caso e na Escola Stoica.

Na Escola Estoica, [Diodorus Cronus](https://en.wikipedia.org/wiki/Diodorus_Cronus), um dos professores, desenvolveu o racioníno lógico baseado em três sentenças onde a terceira indica a conclusão. O mesmo raciocínio que vimos no exemplo da Jéssica. Não temos muita certeza sobre a relação entre Cronus e Aristóteles cremos que Cronus tenha influenciado Aristóteles, talvez como um contemporâneo mais velho ou como um concorrente. Assim, apesar de muitos autores atribuirem a Aristóteles a criação dos silogismos está realmente claro, se foi um, o outro, ou uma consequência do trabalho de ambos.   

Podemos considerar que cabe a Cronus a criação do que chamamos hoje de __cálculo proposicional__ a Aristóteles cabe o mérito de perceber que a forma da argumentação têm mais impacto na percepção da verdade que o conteúdo dos argumentos. E a forma de estruturar estas sentenças para permiter a conclusão lógica é chamada de __silogismo__.

## Silogismos {.P}

<hr>

Silogismos são estruturas de raciocínio formadas por duas sentenças, chamadas de premissas, ou proposições, e uma conclusão. {.P}

<hr>

O silogismo é a forma de ordenar as premissas de forma a conduzir o raciocínio a conclusão lógica. Se as premissas forem verdadeiras, a conclusão será inevitável. Vimos um silogismo quando falamos que _Jéssica é inteligente_. Se nos preocuparmos com a forma teríamos: 

Depois de Aristoteles, Cronus e seus contemporâneos a lógica dormiu por quase dois mil anos até que no fim do Século XIX o imperialismo britânico permitiu que a lógica voltasse a florescer. Este florescimento moderno começa nos trabalhos de Leibniz.

##   {.P}

<hr/>

[Leibniz](https://en.wikipedia.org/wiki/Gottfried_Wilhelm_Leibniz) que além de ajudar no desenvolvimento do cálculo, e dos números binários, definiu os conceitos de conjunção, disjunção, negação e identidade, as operações fundamentais do Cálculo Proposicional. {.P}

[George Boole](https://en.wikipedia.org/wiki/George_Boole), em 1854 _The Laws of Thought_ apresentando o que conhecemos hoje como __Algebra Booleana__. {.P}

Agora, neste ponto da história temos o conceito de proposição, operações matemáticas que podem ser feitas com estas proposições e uma algebra de adequada a um sistema de numeração adequado a operar entre os conceitos de verdadeiro e falso. A base da tecnologia computacional que usamos hoje estava definida no anos de 1854. O próximo passo importante neste caminho é o Paradoxo de Russel. Mas antes, o que é um paradoxo?

<hr/>

## Paradoxo {.P}

<hr/>

Paradoxo é uma sentença que não tem a verdade bem definida, se a sentença for verdadeira, o argumento é falso. Se a sentença for falsa, o argumento é verdadeiro. {.P}

O paradoxo do mentiroso, que pode ser ligado as escolas gregas de filosofia, pode ser demonstrado com a declaração: __esta declaração é falsa__. {.P}

E deixo que a leitora responda, a sentença em destaque neste parágrafo é verdadeira ou falsa? Só seja honesta e responda antes de ler a continuação.

Existem algumas considerações que devemos fazer. Vamos, antes de qualquer coisa chamar a declaração __esta sentença é falsa__ de premissa. Se a premissa é verdadeira, então __esta declaração é falsa__ é verdadeira. Portanto, a declaração deve ser falsa. A hipótese de que a premissa é verdadeira leva à conclusão de que a declaração é falsa, ou seja, existe uma contradição. Ou se a leitora ainda não estiver tonta, podemos considerar que a premissa é falsa. Neste caso, __esta declaração é falsa__ é falsa. Portanto a premissa deve ser verdadeira. A hipótese que a premissa é falsa leva a conclusão que __esta declaração é falsa__ é verdadeira, outra contradição. Se a premissa não é verdadeira nem falsa, temos um paradoxo. Outras considerações também precisam ser feitas. Veja, que do ponto de vista da filosofia, esta frase, provávelmente cunhada no Século VI A.C. quase trezentos anos antes de Aristoteles e Cronus, por um Cretense chamado Epinemides, se quer é considerado um paradoxo. Século VI A.C. este paradoxo vem dando nós nas mentes mais brilhantes da história desde então, com tal significância que Paulo, utiliza uma variação deste paradoxo em uma das Epístolas a Titos (cap. 1 v:12 e 13):

>12 Um deles, seu próprio profeta, disse: __Os cretenses säo sempre mentirosos, bestas ruins, ventres preguiçosos__. <br>
13 Este testemunho é verdadeiro. Portanto, repreende-os severamente, para que sejam säos na fé.

Há uma carga gigantesca de ironia, da parte de Paulo, nestes dois versos mas, compreenda, vou deixar a análise teológica e filosófica destes dois versos para hora, lugar, texto e escritor certo.

Ainda, já que este é um livro de lógica matemática, e vamos dar nós em nossas próprias mentes, precisamos falar do [Paradoxos de Zeno](https://math.dartmouth.edu/~matc/Readers/HowManyAngels/SpaceTimeMotion/STM.html). Zeno, Zenon, ou Zenão em português, conhecido como Zeno de Elea também se preocupou com paradoxos antes dos tempos de Aristóteles. Seus paradoxos influenciama a física e a matemática até os dias de hoje. Um deles, o paradoxo do deslocamento, é utilizado para explicar cálculo diferencial até os dias de hoje. Infelizmente não restou nada dos escritos de Zeno e tudo que temos sobre ele está nos trabalhos de Aristóteles, milagrosamente preservados pelos estudiosos árabes e persas. A leitora deve estar curiosa então responda a seguinte questão: considere a lâmpada do seu escritório, esta lâmpada está ligada a um interruptor e você pode desligar, ou ligar a lâmpada, infinitas vezes, em um espaço finito de tempo que contaremos. A lâmpada começa ligada, um minuto depois você a desliga, passam-se 30 segundos e você a liga novamente, mais quinze segundos se vão e você a desliga e, a cada passagem da metade do tempo gasto na última interação, você muda o estado da lâmpada. Depois de dois minutos, a lâmpada estará apagada ou acesa?

Estes foram exemplos de paradoxos que aborrecem a humanidade há milhares de anos. São importantes, sem dúvida, mas não se comparam aos paradoxos e avanços que podemos ver  a partir do final dos anos 1800. E, neste caso, o Paradoxo de Russel se destaca.

<hr/> 

## Bertand Russel {.P}

<hr/> 



[Bertrand Russel](https://en.wikipedia.org/wiki/Bertrand_Russell) (1872 – 1970) pretenciosamente tentou reescrever toda a matemática a partir dos conceitos de conjuntos e fracassou ao encontrar um dos mais famosos paradoxos da história da matemática. {.P}

Esta pretensão não era exclusiva de Russell, outros matemáticos antes dele, e alguns depois, perseguiram este objetivo. Entre estes destacam-se [Kurt Gödel](https://en.wikipedia.org/wiki/Kurt_G%C3%B6del) e [Alonzo Church](https://en.wikipedia.org/wiki/Alonzo_Church) cujos trabalhos, em lógica e nas teorias da computabilidade e complexidade têm impacto direto na criação do mundo em que vivemos e serão, estudadas neste livro.  

Russell estudou filosofia, matemática e lógica. Em 1901, estudando a Teoria dos Conjuntos de [Georg Cantor](https://en.wikipedia.org/wiki/Georg_Cantor), encontou um paradox na definição de conjuntos. O mesmo paradoxo já havia sido estudado, mas não publicado por [Ernst Zermelo](https://en.wikipedia.org/wiki/Ernst_Zermelo) em 1899 e pelo próprio Georg Cantor em 1890. Contudo, a história atribui este paradoxo a Russell graças a sua publicação. 
A tentativa de Russell e Alfred North Whitehead, registrada no livro __Principia Mathematica__ contribui definitivamente para o formalismo da lógica como parte da matemática. A simbologia de linguagem da lógica que adotamos neste livro tem origem no __Principia Mathematica__ mas foi atualizada ao longo das décadas. Se a curiosa leitora estiver interessada, a Universidade de Stanford mantém uma sinopse de todo [__Principia Mathematica__](https://plato.stanford.edu/entries/principia-mathematica/).

<hr/> 

## O Paradoxo de Russell {.P}

<hr/> 

Considere $A$ como o conjunto formado por todos os conjuntos que não contém a si mesmos. De tal forma que: $A=\{S|S \notin S\}$ {.P}

Seria $A$ um elemento de si mesmo? Seria o conjunto $A$ um elemento do conjunto dos conjuntos que não contém a si mesmos? {.P}

Vamos pensar um pouco sobre isso. Se $A$ é um elemento $A$ isso significa que ele é um elemento de si mesmo. Logo, pela própria definição de $A$ ele não poderia conter a si mesmo, já que $A$ é o conjunto de conjuntos que não contém a si mesmos. Como esta opção é impossível, devemos concluir que $A$ não é um elemento de si mesmo. Mas, se ele não contém a si mesmo. Ele precisa, necessariamente, ser um elemento do conjunto dos cojuntos que não contém a si mesmo. E pronto, lá se foi a teoria dos cojuntos por água abaixo, levando consigo uma parte importante do cérebro deste pobre autor.

<hr/>

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
3. $1+1=2$ .
4. Todos os gatos são animais. {.P}

<hr/>

Todas as declarações do exemplo 1 são proposições. Todas estas sentenças, ou são verdadeiras (2 e 4), ou falsas (1, 3) e não resta dúvida sobre a verdade de cada uma destas declarações. Aqui, no domíno da linguística e do racional, a prova matemática é dispensável. A verdade é interente ao seu conjunto interno de conhecimento, os milhares de proposições que você foi aceitando como verdadeira ao longo da vida. Entretanto, pelo menos uma delas, podemos provar matematicamente, ainda que o esforço seja mínimo comparado as outras três, a proposição "1+1=2" foi matemáticamente provada em pouco mais de 360 páginas.

As proposições que usamos nos exemplo são ditas atômicas, ou simples, elas estão contidas em si mesmo e podem ser representadas por variáveis. No Cálculo Proposicional usamos letras minúsculas para representar as proposicões. As letras $p,q,r,s,t$ são as letras que usaremos com mais frequencia neste livro.  

Também usaremos as letras maiúsculas $T$ para representar verdadeiro e $F$ para representar falso como símbolos para indicar a verdade de uma determinada proposição. Assim voltando ao Exemplo 1 temos:

## Exemplos de Proposição (1) {.P}

<hr/>

1. $p = \text{Lima é a Capital da China.} | p = F$
2. $q = \text{Paris é a Capital da França.} | q = T$
3. $r = \text{1+1=2} | r = F$
4. $s = \text{Todos os gatos são animais.} | s = T$ {.P}

<hr/>

## Exemplos de Proposição (2) {.P}

<hr/>

Toda proposição é uma sentença mas, nem toda sentença é uma proposição. {.P}

1. Escreva este texto ainda hoje.
2. $x+4=6$ {.P}

<hr/>

A sentença $1$ não é uma proposição por que não é uma declaração e a sentença $2$ não uma proposição porque não temos como garantir se ela é verdadeira ou falsa. Observe que, neste caso, no momento em que atribuirmos um valor a $x$, poderemos definir se a sentença 2 é verdadeira ou falsa e teremos uma proposição.

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
SALMON, W. C. SPACE, TIME, AND MOTION A Philosophical Introduction. University of Arizona, 2009. Disponivel em: <https://math.dartmouth.edu/~matc/Readers/HowManyAngels/SpaceTimeMotion/STM.html>. Acesso em: 08 ago. 2020.


</small>


