//main
#include <iostream>
#include "clock.h"
using namespace std;

int main()
{
    //Declare two Clock objects
    Clock myClock, newClock;

    //Set the time of myClock to 12:45:30 am.
    myClock.setClock(12, 45, 30, "am");

    //Set the time of the newClock object to 2:15:30 pm.
    newClock.setClock(2, 15, 30, "pm");

    //Display the time of myClock in both standard and
    //military format
    cout << "The time on the Digital Clock (in standard form) is: ";
    myClock.displayStandard();

    cout << "\nThe time in military format is: ";
    myClock.displayMilitary();

    //Set the two times to the same time
    myClock = newClock;

    //Display the time of myClock in standard time  
    cout << "\nThe time on the Digital New Clock (in standard form) is: ";
    myClock.displayStandard();

    return 0;
}

//clock.h
  //Eliminate the problem of multiple inclusions
#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>


 //The Clock class definition starts here.
class Clock
{
private:
    //declarations of data members that are private
    int hour;           //an hour in the range 1 - 12
    int minute;         //a minute in the range 0 - 59
    int second;         //a second in the range 0 - 59
    std::string meridian;    // AM or PM 

public:
    //function prototypes of member functions (methods)

    //Set the clock to the specified time
    void setClock(int h, int m, int s, std::string mer);

    //Display the time in standard notation 
    void displayStandard();

    //Display the time in military notation
    void displayMilitary();
};

//The Clock class definition ends with the closing brace and semicolon.
#endif

//clock.cpp
#include <iostream>     //contains cin & cout
#include "clock.h"      //contains the definition of the Clock class


 //Function:  setClock() 
//Purpose:   This function assigns the time specified by the user.
 //           No error checking is done to check for illegal dates.
 //           Arguments include the hour (h), minute (m), second(s)
 //           and AmOrPm (means AM and PM).
void Clock::setClock(int h, int m, int s, std::string AmOrPm)
//IN      IN      IN     IN
{
    //hour, minute, second and meridian are private data members
    hour = h;
    minute = m;
    second = s;
    meridian = AmOrPm;
}


//Function: displayStandard()
//Purpose:  This function displays the clock time in standard format.
//
//Assumption:   The time has been assigned a valid value.
void Clock::displayStandard()
{
    std::cout << hour << ':' << minute << ':' << second << ' ' << meridian;
}

//Function: displayMilitary()
//Purpose:  This function displays the time in military format.
//
//Assumption:   The Clock has been assigned a valid value.
void Clock::displayMilitary()
{
    int militaryHour = hour;

    //if it is pm and it isn't 12:00 noon, then add 
    //12 hours to the time
    if (meridian == "PM" && hour != 12)
        militaryHour += 12;

    //if it is 12:00 midnight, then subtract 12 hours
    if (meridian == "AM" && hour == 12)
        militaryHour -= 12;

    std::cout << militaryHour << ':' << minute << ':' << second;
}