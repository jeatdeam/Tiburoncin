#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include"Contacto.h"
#include"ArregloContacto.h"
#include"Funciones.h"
using namespace System;
using namespace std;

int main()
{

	//variables
	int op;
	char *nombrecontacto = new char[20];//para el nombre
	int edadcontacto;//para la edad

	//definir objetos

	Contacto *objcontacto;
	ArregloContacto *objarreglocontacto;
	// instanciar el objeto objarreglocontacto

	objarreglocontacto = new ArregloContacto();

	while (1) {

		Console::Clear();
		op = Menu();

		if (op == 1) {
			if (objarreglocontacto->Getn() > 0)
			{
				cout << "Nombre \t\t EDAD\n";
                for (int i = 0; i < objarreglocontacto->Getn(); i++)
				{
					//obtener el contacto
					objcontacto = objarreglocontacto->GetContacto(i);
					cout << objcontacto->Getnombre();
					cout << "\t";
					cout << objcontacto->Getedad();
					cout << endl;
				}
				//_getch();
			}
			else 
				cout << "\n El arreglo no tiene datos...";
			_getch();
		}
		 if (op == 2) {

			objcontacto = new Contacto();
			cout << "Nuevo CONTACTO" << endl;
			cin.ignore();
			cout << "Ingrese Nombre : "; cin.getline(nombrecontacto, 20);
			cout << "Ingrese Edad : "; cin >> edadcontacto;
			//agregamo el objeto al arreglo
			objarreglocontacto->AgregarContacto(objcontacto);

		}

	}
	//_getch();
    return 0;
}
