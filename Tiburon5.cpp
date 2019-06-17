#include"stdafx.h"
#include <iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
using namespace System;

void gotoxy(int x, int y) {

	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;

	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hcon, dwPos);

}

void CañaPescar() {

	int x = 10, y = 10;
	bool Game_over = false;

	while (!Game_over) {
		gotoxy(x, y); printf("|");

		if (kbhit()) {

			char tecla = getch();

			gotoxy(10, 10);
		//if (tecla == 'j')x--;
		//if (tecla == 'l')x++;
			if (tecla == 'k')y++;
			gotoxy(x, y); printf(" ");
			if (tecla == 'i')y--;
		
			
		}
	}
}

/*


|
||(     )  * 
||(    o )***
||(     )  *  
|

*/
void DibujarTiburonA(int x, int y) {

	Console::SetCursorPosition(x, y);
	cout << "A";
	Console::SetCursorPosition(x, y + 1);
	cout << "Z";
	Console::SetCursorPosition(x, y + 2);
	cout << "U";
	Console::SetCursorPosition(x, y + 3);
	cout << "L";
}

void DibujarTiburonB(int x, int y) {

	Console::SetCursorPosition(x, y);
	cout << "L";
	Console::SetCursorPosition(x, y + 1);
	cout << "O";
	Console::SetCursorPosition(x, y + 2);
	cout << "L";
	Console::SetCursorPosition(x, y + 3);
	cout << "(._.)/";
}
void BorrarTiburon(int x, int y) {

	Console::SetCursorPosition(x, y);
	cout << " ";
	Console::SetCursorPosition(x, y + 1);
	cout << " ";
	Console::SetCursorPosition(x, y + 2);
	cout << " ";
	Console::SetCursorPosition(x, y + 3);
	cout << "      ";
}
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

	if (((x + a) < 10) || ((x + a) > 50)) { a = -a; }//Eje x
	if (((y + b) < 0) || ((y + b) > 24)) { b = -b; }//Eje y

	x = x + a;
	y = y + b;

	if (a == 1) {

		Pez1(x, y+5);
		Sleep(20);
		BorrarPez(x, y+5);
	}
	else if (a == -1) {

		Pez2(x, y+5);
		Sleep(20);
		BorrarPez(x, y+5);
	}

}
void MovimientoPez(int &x, int &y, int &a, int &b) {

	while (1) {

		Pececito(x, y, a, b);

	}
}

void Tiburon(int &x, int &y, int &a, int &b) {//la fuente de los peces y el tiburon sera de 30x70


	if (((x + a) < 10) || ((x + a) > 70)) { a = -a; }//Eje x
	if (((y + b) < 0) || ((y + b) > 24)) { b = -b; }//Eje y


	x = x + a;
	y = y + b;

	if (a == 1) {

		DibujarTiburonA(x, y);
		Sleep(20);
		BorrarTiburon(x, y);
	}
	else if (a == -1) {

		DibujarTiburonB(x, y);
		Sleep(20);
		BorrarTiburon(x, y);
	}

}
void MovimientoTiburon(int &x, int &y, int &a, int &b) {

	while (1) {

		Tiburon(x, y, a, b);

	}
}

void Muro(int x, int y) {

	Console::SetCursorPosition(x, y);

		for (int i = 0; i < 20; i++) {

			Console::SetCursorPosition(9 ,y+i );
			printf("%c",219);

			Console::SetCursorPosition(71,y+i );

			printf("%c",219);

		}

		for (int i = 0; i < 63 ; i++) {

			Console::SetCursorPosition(9+i, 8 );
			printf("%c", 223);

			Console::SetCursorPosition(9+i,  29);

			printf("%c", 223);

		}
}
int main() {

	int x = 10, y = 9, a = 1, b = 0;

	Console::CursorVisible = false;
	
	Pececito(x, y, a, b);
	Muro(x,y);
	MovimientoTiburon(x, y, a, b);
	Pececito(x, y, a, b);
	CañaPescar();
	_getch();
	return 0;
}

