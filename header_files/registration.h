// registration.h
// Copyright 2020, Konstantinos Thanos [Mathematician, MSc]. All rights reserved.
//==============================
// New User Registration Process
//==============================
#ifndef REGISTRATION_H
#define REGISTRATION_H

// Local header files
#include "login.h"

// Declaration of variables, defined in main.cpp
extern string password;
extern string regname;
extern string regpass;

int registration()
{
    ifstream data("database"); // Open database file
	
    cout << endl << "Escriba el nombre de usuario deseado:";
    getline(cin, regname); // User gives desired username

	// Check if given username already exists in database
	while(!data.eof())
	{
		getline(data, name, '\n');     // Reading the usernames from the database
		getline(data, password, '\n'); // Reading the passwords from the database
		while(regname == name)
		{
			 cout << "El nombre de usuario ya existe! Intentar otra vez..." << endl;
			 registration(); // If name already exists start process of registration again
		}
	}
	data.close(); // Close file
	
    cout << "Escribe la contrasena deseada:";
    getline (cin, regpass); // User gives desired password

	// If password is less than 4 chars try another one
    while (regpass.length() < 4) 
    {
        cout << endl << "¡La contraseña elegida es demasiado corta!" << endl;
        cout << "La contraseña debe tener al menos cuatro (4) caracteres." << endl << endl;
        cout << "Intenta otra contrasena : ";
        getline ( cin, regpass );
    }
    
	ofstream newData("database", ios::app);      // Open database file to write new username and password
	
	ofstream newfile(regname.c_str(), ios::app); // Create file of new user with his username as file name        
	newfile.close();
	
	// Add name and password of new user to the database file
	newData << regname << '\n';
	newData << regpass << '\n';
	newData.close(); // Close database file

	cout << endl;
	cout << regname+",¡Se ha registrado exitosamente!" << endl << endl;
	cout << " Que te gustaría hacer:" << endl << string(24, '=') << endl;
	cout << "[1] Logearte" << endl;
	cout << "[2] Regresar a Menu principal" << endl;
	cout << "[3] Salir del programa" << endl << endl;
	cout << "Choice : ";
	
	// Process after successful registration
	int regChoice;
	cin >> regChoice;
	cin.ignore();
	
	switch (regChoice)
	{
		case 1:
			login();
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			exxit();
			break;
		default:
			cout << "opcion no valida ! intenta de nuevo ...x	" << endl;
			mainmenu();
			break;
	}
    return 0;
}


#endif // REGISTRATION_H
