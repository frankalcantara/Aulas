//main
#include <iostream>
#include "relogio.h"
using namespace std;

int main()
{
    //Declare two relogio objects
    relogio myRelogio, newRelogio;

    //Set the time of myRelogio to 12:45:30 am.
    myRelogio.setRelogio(12, 45, 30, "am");

    //Set the time of the newRelogio object to 2:15:30 pm.
    newRelogio.setRelogio(2, 15, 30, "pm");

    //Display the time of myRelogio in both standard and
    //military format
    cout << "A hora padrão é: ";
    myRelogio.displayPadrao();

    cout << "\nA hora em formato militar é: ";
    myRelogio.displayMilitary();

    //Set the two times to the same time
    myRelogio = newRelogio;

    //Display the time of myRelogio in standard time  
    cout << "\nA hora padrão no relogio novo é: ";
    myRelogio.displayPadrao();

    return 0;
}

//relogio.h
  //Eliminate the problem of multiple inclusions
#ifndef relogio_H
#define relogio_H

#include <iostream>
class relogio
{
private:
    int hora;           //an hora in the range 1 - 12
    int minuto;         //a minuto in the range 0 - 59
    int segundo;         //a segundo in the range 0 - 59
    std::string meridiano;    // AM or PM 

public:
    void setRelogio(int h, int m, int s, std::string mer);
    void displayPadrao();
    void displayMilitary();
};
#endif

//relogio.cpp
#include <iostream>     //contains cin & cout
#include "relogio.h"      //contains the definition of the relogio class

void relogio::setRelogio(int h, int m, int s, std::string AmOrPm) {
    //hora, minuto, segundo and meridiano são privados
    hora = h;
    minuto = m;
    segundo = s;
    meridiano = AmOrPm;
}

void relogio::displayPadrao() {
    std::cout << hora << ':' << minuto << ':' << segundo << ' ' << meridiano;
}

void relogio::displayMilitary() {
    int horaMilitar = hora;
    if (meridiano == "PM" && hora != 12) horaMilitar += 12;
    if (meridiano == "AM" && hora == 12) horaMilitar -= 12;
    std::cout << horaMilitar << ':' << minuto << ':' << segundo;
}