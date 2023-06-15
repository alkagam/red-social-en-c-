
#ifndef EXXIT_H
#define EXXIT_H

// Header files
#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

// Declaration of variables, defined in main.cpp
extern string logname;

int exxit()
{
    cout << endl << "Terminanacion de Programa.." << endl;
    usleep(1000000); // Suspend execution for microsecond intervals
    cout << " Gracias por tu visita <3 "+logname+" !" << endl;
    return 0;
}


#endif // EXXIT_H
