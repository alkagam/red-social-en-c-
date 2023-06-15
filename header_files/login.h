// login.h
// Copyright 2020, Konstantinos Thanos [Mathematician, MSc]. All rights reserved.
//===========
// User Login
//===========
#ifndef LOGIN_H
#define LOGIN_H

// Local header files
#include "menu2.h"

int mainmenu();

// Declaration of variables, defined in main.cpp
extern string password;
extern string logpass;

void login()
{
    ifstream data("database"); // Open database file with usernames and passwords

    // Check if user is already registered
    if (!data.is_open())
    {
        cout << endl;
        cout << " Tienes que registrarte primero!" << endl;
        mainmenu();
    }
     
    cout << endl << "Escribe Tu usuario : ";
    getline(cin, logname);  // User enters username to login

    cout << "Escribe tu contrasena : ";
    getline(cin, logpass); // User enters password to login

    int j;
    while(!data.eof()){
        getline(data, name, '\n');     // Reading the usernames from the database
        getline(data, password, '\n'); // Reading the passwords from the database

        // Check if username and password are correct
        if ( logname == name && logpass == password )
        {
            cout << endl;
            cout << "¡Iniciado sesion correctamente!" << endl;
            cout << "\e[3mBienvenidos , \e[0m" << logname << "\e[3m !\e[0m" << endl;
            menu2();
            break;
        }
        else if (logname != name && logpass == password) {j=1;}
        else if (logname == name && logpass != password) {j=2;}
    }
    // Check for wrong username or password
    if(j==1)
    {
        cout << endl << "Usuario incorrecto!" << endl << "intenta de nuevo" << endl;
        login();
    }   
    else if (j==2)
    {
        cout << endl << "contrasenaa!" << endl << "Intenta de nuevo" << endl;
        login();
    }   
    data.close(); // Close database file
}


#endif // LOGIN_H
