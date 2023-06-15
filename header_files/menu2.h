// menu2.h
// Copyright 2020, Konstantinos Thanos [Mathematician, MSc]. All rights reserved.
//=============================
// Menu after successful Log In
//=============================
#ifndef MENU2_H
#define MENU2_H

// Local header files
#include "viewposts.h"
#include "viewfriendposts.h"
#include "menu3.h"
#include "friendrequest.h"
#include "friends.h"
#include "deletefriends.h"
#include "exxit.h"

int mainmenu();
void viewfriendposts();

void menu2()
{
    cout << endl << "\e[1m MENU Red social \e[0m" << endl << "\e[3m(Teclee la opcion deseada)\e[0m" << endl << string(33, '=') << endl;
    cout << "[1] Mi muro l" << endl;
    cout << "[2] Muros de amigos " << endl;
    cout << "[3] Enviar solicitud" << endl;
    cout << "[4] Aceptar/Rechazar solicitud de amistad" << endl;
    cout << "[5] Mis amigos " << endl;
    cout << "[6] Eliminar amigos" << endl;
    cout << "[7] Atras" << endl;
    cout << "[8] cerrar session " << endl;
    cout << "[9] Exit the program" << endl;
    cout << endl;

    // Choose from the available numbers (1,...,9)
    int menuChoice;
    cout << "Opcion : ";
    cin >> menuChoice; // User gives choice number
    switch (menuChoice)
    {
        case 1:
            viewposts();
            break;
        case 2:
            viewfriendposts();
            break;
        case 3:
            menu3();
            break;
        case 4:
            friendrequest();
            break;
        case 5:
            friends();
            break;
        case 6:
            deletefriends();
            break;
        case 7:
            mainmenu();
            break;
        case 8:
            cout << "¡Has terminado tu sesion satisfactoriamente!" << endl;
            mainmenu();
            break;
        case 9:
            exxit();
            break;
        default:
            cout << "¡Mala decisión! Intentar otra vez" << endl;
            menu2();
            break;
    }
}


#endif // MENU2_H
