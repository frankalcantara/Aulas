/**
 * @file ExercicioJogoDaVelha.cpp
 * @author Devan Wiech (https://www.dreamincode.net/forums/topic/199059-tic-tac-toe-using-classes/)
 * @brief Está postado em um forum, apenas modifiquei e corrigi
 * @version 0.1
 * @date ???
 * @mod Frank de Alcantara 20-20-11-04
 * 
 * 
 */
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//A classe do jogo
class jogoDaVelha{
  public: 
    jogoDaVelha();//constructor
    int jogadorEscolhido(){return jogador;};
    int linhaEscolhida(){return linha;};
    int colunaEscolhida(){return coluna;};
    int Check_Board();
    void escolherJogador(int a){jogador=a;};
    void escolherLinha(int b) {linha = b;};
    void escolherColuna(int c){coluna=c;};
    void tabuleiro();
    bool verificaJogada(int, int);
  private: 
    int linha;
    int coluna;
    int jogador;
    int board[3][3];
    char valorCelula[3][3];
};

jogoDaVelha::jogoDaVelha(){
  //inicializa as propriedades da classe
  linha = 0;
  coluna = 0;
  jogador = 1;
  for (int i = 0; i<3; i++){
    for (int j = 0; j<3; j++){
      board[i][j] = 0;
      valorCelula[i][j] = ' ';
    }
  }
  //mostra o tabuleiro
  tabuleiro();
}

bool jogoDaVelha::verificaJogada(int linha, int coluna){
  if (linha!= 0 && linha!= 1 && linha!= 2 ){
    cout<<"Escolha Inválida!!!"<<endl;
    return 0;
  } else if (coluna!=0 && coluna!= 1 && coluna!= 2 ) {
    cout<<"Escolha Inválida!!!"<<endl;
    return 0;
  } else if (board[linha][coluna] == 1 || board[linha][coluna] == 2){
    cout<<"Espaço já ocupado!!!" <<endl;
    return 0;
  } else {
    board[linha][coluna] = jogador;
    return 1;
  }
 
}

int jogoDaVelha::Check_Board(){
  int soma= 0, teste= 0, contador= 0;
  
  for (int i= 0; i<3; i++){
    soma=0;
    for(int j=0; j<3; j++){
      if (board[i][j] == 0){
        contador++;
      }
      soma +=(board[i][j]*board[i][j]);
    }
    
    if (soma == 3 ||soma == 12){
      teste=soma;
      break;
    }
    soma=0;
  }
  
  for (int j=0; j<3; j++){
    soma=0;
    for (int i=0; i<3; i++){
      soma+=(board[i][j]*board[i][j]);
    }
    if (soma==3 || soma==12){
      teste=soma;
      break;
    }
    soma=0;
  }

  if(teste!=3 ||teste!=12){
    soma = (board[0][0] * board[0][0])+ (board[1][1] * board[1][1]) +
        (board[2][2] * board[2][2]);

    if ( soma == 3 || soma == 12){
      teste=soma;
    }
  }

  if (teste != 3 || teste != 12){
    soma = (board[2][0] * board[2][0])+ (board[1][1] * board[1][1]) + 
        (board[0][2] * board[0][2]);

    if (soma==3||soma==12){
      teste=soma;
    }
  }

  if (teste==3){  
    teste = 1;
  } else if (teste == 12) {
    teste = 2;
  } else if (contador == 0) {
    teste = 3;
  } else {
    teste = 0;
  }
  //atualiza o tabuleiro
  tabuleiro();
  return teste;
}

void jogoDaVelha::tabuleiro(){
  for ( int linha = 0; linha < 3; linha ++){
    for ( int coluna = 0; coluna < 3; coluna++){
      if ( board[linha][coluna] == 0) {
        valorCelula[linha][coluna] = ' ';
      }
      if ( board[linha][coluna] == 1){
        valorCelula[linha][coluna] = 'X';
      }
      if ( board[linha][coluna] == 2) {
        valorCelula[linha][coluna] = 'O';
      }
    }
  }

  //limpa a tela a cada jogada
  cout<<"\033[2J"<<"\033[1;1H"<<endl;
  cout<< "\nJogador 1: X" << "\nJogador 2: O" << endl;
  cout<<"\n\n";
  cout <<valorCelula[0][0] << " | "<<valorCelula[0][1]<<" | " << valorCelula[0][2] << " " << endl;
  cout <<valorCelula[1][0] << " | "<<valorCelula[1][1]<<" | " << valorCelula[1][2] << " " << endl;
  cout <<valorCelula[2][0] << " | "<<valorCelula[2][1]<<" | " << valorCelula[2][2] << " " << endl;
 
}

int main(){
  jogoDaVelha jogo;

  bool teste;
  bool jogando=true;
  int linha=0;
  int coluna=0;
  int jogador;
  int check=0;
  
  while (jogando){
    //começa com o jogador 1 por que inicializamos no constructor
    jogador= jogo.jogadorEscolhido();
    
    cout<<"\nJOGADOR: "<<jogador<< endl;
    cout<< "Escolha a linha (0, 1, or 2): ";
    cin>>linha;
    cout<<"\nEscolha a coluna (0, 1, or 2): ";
    cin>>coluna;

    jogo.escolherLinha(linha);
    jogo.escolherColuna(coluna);

    teste= jogo.verificaJogada( jogo.linhaEscolhida(), jogo.colunaEscolhida());

    if (teste==1){
      check=jogo.Check_Board();
    } else {
      
      while (teste==0){
        cout<<"JOGADOR: "<<jogo.jogadorEscolhido()<<" escolha inválida "<<endl;
        cout<<"Escolha uma linha (0, 1, or 2): ";
        cin>>linha;
        cout<<"Escolha uma coluna (0, 1, or 2): ";
        cin>>coluna;
        
        jogo.escolherLinha(linha);
        jogo.escolherColuna(coluna);
        
        teste=jogo.verificaJogada(jogo.linhaEscolhida(), jogo.colunaEscolhida());
      }

      check= jogo.Check_Board();
    }

    if (check==1 ||check==1){
        break;
    } else if (check==3){
      jogo.tabuleiro();
      cout<<"\nEMPATE!!!!"<<endl;
      return 0;
    }

    if (jogador == 1){
      jogador = 2;
    } else {
      jogador=1;
    }

    jogo.escolherJogador(jogador);
  } // fim do while     

   cout<<"\nJOGADOR: "<< check <<" VENCEU!!!"<<endl;

  return 0;
}//fim do main
 
 /**
  * @brief simplifique este algoritmo e coloque cores. 
  * 
  */