// mainmenu.h
// Copyright 2020, Konstantinos Thanos [Mathematician, MSc]. All rights reserved.
//=======================
// First Menu and Options
//=======================
#ifndef MAINMENU_H
#define MAINMENU_H

// Local header files
#include "registration.h"

int mainmenu()
{
    // Main Menu Options
    cout << endl << "\e[1mMAIN MENU\e[0m" << endl << "\e[3m(teclee la opcion )\e[0m" << endl << string(33, '=') << endl;
    cout << "[1] Registrarse" << endl;
    cout << "[2] Logearse" << endl;
    cout << "[3] Salida  del program " << endl << endl;

    // Choose one from the available numbers (1,2,3)
    int choice;
    cout << "Opcion : ";
    cin >> choice; // User enters the desired number
    cin.ignore();

    switch (choice)
    {	
        case 1:
            registration();
            break;
        case 2:
            login();
            break;
        case 3:
            exxit();
            break;
        default:
            cout << "opcion no valida ! intenta de nuevo ..." << endl << endl;
            mainmenu();
    }
    return 0;
}


#endif // MAINMENU_H
