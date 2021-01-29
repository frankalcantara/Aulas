/**
 * @file ClasseEstudante.cpp
 * @author Frank de Alcantara
 * @brief  Exemplo de criação de classes e métodos em c++
 * @version 0.1
 * @date 2020-07-20
 * 
 * 
 */
#include <iostream>
using namespace std;
  
class Estudante{
    private:
       string  nome;
       int   matricula;
       int   nota;
       float percentualAtingido;
    public:
       void setDetalhes(void);
       void displayDetalhes(void);
};
 
//observe que estou usando comandos ascii para controlar o terminal
//funciona muito bem em linux, não testei no windows.
void Estudante::setDetalhes(void){
    cout << "\033[1;31m"<<"Digite nome: " << "\033[0m" ;
    cin >> nome;
    cout <<"\033[1;31m"<< "Digite matricula: "<< "\033[0m" ;
    cin >> matricula;
    cout <<"\033[1;31m"<< "Digite nota (máximo 200): "<< "\033[0m" ;
    cin >> nota;
     
    percentualAtingido=(float)nota/200*100;
}
 
void Estudante::displayDetalhes(void){
   cout << "\033[1;31m"<< "nome:" << "\033[0m" << nome << 
   "\033[1;31m" <<"\nMatricula:" << "\033[0m"<< matricula <<"\033[1;31m"<< "\nNotal:" <<  "\033[0m"<< nota << "\033[1;31m"<< "\nPercentual Atingido:"<< "\033[0m"<<percentualAtingido<<"\n\n"<<endl;
}
 
int main() {

    int n;

    cout << "\033[1;34m" << "Quantidade de Estudantes: " << "\033[0m";
    cin >> n;


    Estudante* Estd;
    Estd = new Estudante[n];

    for (int i = 0;i < n; i++) {
        cout << "\033[1;32m" << "\nDados dos Estudante (" << i + 1 << "): \n" << "\033[0m";
        Estd[i].setDetalhes();
    }

    cout << endl;
    //para imprimir os dados...
    for (int i = 0;i < n; i++) {
        cout << "\033[2J" << "\033[1;1H" << "\033[1;32m" << "\nDetalhes do Estudante (" << (i + 1) << "):\n";
        Estd[i].displayDetalhes();
    }
}//fim do main
        
            
                