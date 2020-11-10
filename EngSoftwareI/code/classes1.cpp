//atenção, este código está propositalmente cheio de erros.
#include <iostream>
using namespace std; 

//classe base que usaremos para entender o processo
class Abstrata { 
public: 
    int varPublica; 
    //todos os membros declarados como público estão disponíveis para todo mundo
    void testaProtected(){
      cout << varPublica + varPrivada;
    }
protected: 
    //os membros protected podem ser acessados pela classe e seus herdeiros. 
    //mas, cuidado, o modo de herança altera essa visibilidade
    int varProtegida; 
private: 
    //membros declarados private só podem ser acessados por métodos dentro da própria classe
    //esta é uma boa prática de programação. Declaramos todos as propriedades private e 
    //fazemos métodos públicos para ler e escrever nestas propriedades.
    int varPrivada; 
}; 
  
//classe herdeira, em public
class ConcretaPublica : public Abstrata { 
  //teste para uso da variável privada da classe abstrata
  //deve dar um erro de compilação
    void testaPrivate(){
      cout << varPublica + varPrivada;
    };
  //teste para uso de membros protegidos
  //deve funcionar por que a classe concreta foi herdada de modo público
    void testaProtected(){
      cout << varPublica + varProtegida;
    }

    //constructor
    ConcretaPublica(){
      cout<<varPublica;
    }
}; 
//classe herdeira em Protected 
class ConcretaProtected : protected Abstrata{
  //teste para uso da variável privada da classe abstrata
  //deve dar um erro de compilação
  void testaPrivate(){
      cout << varPublica + varPrivada;
    }

  //teste para uso de membros protegidos
  //deve funcionar por que o que é protected na classe abstrata será protected aqui
    void testaProtected(){
      cout << varPublica + varProtegida;
    }

  //constructor
    ConcretaProtected(){
      cout<<varPublica;
    }
};

//classe herdeira em Private 
//isso vai trocar todos membros de Abstrata para private
class ConcretaPrivate : private Abstrata{
  
  //teste para uso da variável privada da classe abstrata
  //deve dar um erro de compilação
  void testaPrivate(){
      cout << varPublica + varPrivada;
    }

  //teste para uso de membros protegidos
  //deve funcionar por que o que é protected virou private aqui
    void testaProtected(){
      cout << varPublica + varProtegida;
    }
  
  //constructor
    ConcretaPrivate(){
      cout<<varPublica;
    }
  public:
  //mas podemos, trocar protected para public manualmente nesta class.
  using Abstrata::varProtegida;
  //não faça isso, esta é uma daquelas coisas que você pode, mas não deve fazer.
};

// demonstração dos problemas 
int main() 
{ 
    ConcretaPublica NossoObjetoPublico; 
  
    // varPublica é publica na classe abstrata e será herdada
    // pelo objeto criado a partir da classe concreta.
    cout << NossoObjetoPublico.varPublica << endl; 
  
    // varProtegida é protected na classe abstrata
    // continua protegida e temos um erro de compilação
    cout << NossoObjetoPublico.varProtegida << endl; 
  
    // varPrivada não é acessível pela classe concreta
    // varPrivada vai continuar privada e isso vai provocar
    // um erro de compilação
    cout << NossoObjetoPublico.varPrivada << endl; 
  
    ConcretaProtected NossoObjetoProtected; 
  
    // varPublica é pública mas vai se tornar privada na class ConcretaProtected
    // então teremos um erro de visibilidade
    cout << NossoObjetoProtected.varPublica << endl; 
  
    // varProtegida é protected na classe abstrata e vai ficar assim na classe CroncretaPrivate
    // so it will give visibility error 
    cout << NossoObjetoProtected.varProtegida << endl; 
  
    // varPrivada não é acessível por ConcretaProtected logo
    // varPrivada não será acessível e irá provocar um erro de visibilidade
    cout << NossoObjetoProtected.varPrivate << endl; 

    ConcretaPrivate NossoObjetoPrivate; 
  
    // varPublica é publica mas vai ficare private 
    // resultando em um erro 
    cout << NossoObjetoPrivate.varPublica << endl; 
  
    // varProtegica é protected e vai ficar privada 
    // resultando em erro de visibilidade
    cout << NossoObjetoPrivate.varProtegida << endl; 
  
    // varPrivate é privada e não é acessível por ConcretaPrivada
    // Continuará Private resultando em outro erro de visibilidade
    cout << NossoObjetoPrivate.varPrivada << endl; 

}; 