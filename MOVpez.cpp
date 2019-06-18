#include "stdafx.h"
#include <iostream>
#include<conio.h>
#include<Windows.h>
using namespace System;
using namespace std;

void Pez1(int x, int y) {

	Console::SetCursorPosition(x, y + 5);

	Console::ForegroundColor = ConsoleColor::Blue;

	cout << "><((((o>";

}
void Pez2(int x, int y) {


	Console::SetCursorPosition(x, y + 5);

	Console::ForegroundColor = ConsoleColor::Blue;

	cout << "<o))))><";
}
void BorrarPez(int x, int y) {

	Console::SetCursorPosition(x, y + 5);
	cout << "        ";

}
void Pececito(int &x, int &y, int &a, int &b) {

	if (((x + a) < 10) || ((x + a) > 60)) { a = -a; }//Eje x
	if (((y + b) < 0) || ((y + b) > 24)) { b = -b; }//Eje y

	x = x + a;
	y = y + b;

	if (a == 1) {

		Pez1(x, y);
		Sleep(20);
		BorrarPez(x, y);
	}
	else if (a == -1) {

		Pez2(x, y);
		Sleep(20);
		BorrarPez(x, y);
	}


	/*if (a == 1) {

		Pez1(x, y+5);
		Sleep(20);
		BorrarPez(x, y+5);
	}
	else if (a == -1) {

		Pez2(x, y+5);
		Sleep(20);
		BorrarPez(x, y+5);
	}
	*/
}

void Pez2(int &x1, int &y1, int &a1, int &b1) {

	if (((x1 + a1) < 10) || ((x1 + a1) > 60)) { a1 = -a1; }//Eje x
	if (((y1 + b1) < 5) || ((y1 + b1) > 29)) { b1 = -b1; }//Eje y

	x1 = x1 + a1;
	y1 = y1 + b1;

	if (a1 == 1) {

		Pez1(x1, y1 );
		Sleep(20);
		BorrarPez(x1, y1);
	}
	else if (a1 == -1) {

		Pez2(x1, y1);
		Sleep(20);
		BorrarPez(x1, y1);
	}

}
void MovimientoPez(int &x, int &y, int &a, int &b) {

	while (1) {

		Pececito(x, y, a, b);

	}
}
void MovimientoPez2(int &x1, int &y1, int &a1, int &b1) {

	while (2) {

		Pez2(x1, y1, a1, b1);

	}
}


int main()
{
	int x=10, y=9, a=1, b=0;
	int x1 = 10, y1 = 14, a1 = 1, b1 = 0;
	MovimientoPez(x,y,a,b);
	MovimientoPez2(x1, y1, a1, b1);
    return 0;
}
