#include<time.h> 
#include <conio.h> 
#include<Windows.h> 
#include<iostream>

using namespace std;
using namespace System;

#define IZQUIERDA 75
#define DERECHA 77
#define ARRIBA 72
#define ABAJO 80
#define FILAS 24
#define COLUMNAS 40

struct Pescado {
	int x;
	int y;
	int dx;
	int dy;
	int limizq;
	int limder;
	int ancho;
	int peso;
};
struct anz
{
	int x=COLUMNAS-9, y=5, puntos=0,vidas=3;
};

void maslento(int velo) {
	Sleep(velo);
}

int ganaste()
{
	system("color 4a");
	system("color 5a");
	system("color 6a");
	system("color 1a");
	system("color 4a");
	system("color 5a");
	system("color 6a");
	system("color 1a");
	system("color 6a");
	system("color 1a");
	system("color 4a");
	system("color 5a");
	system("color 6a");
	system("color 1a");
	system("color 0a");
	cout << endl;
	cout << endl;
	cout << "#=-------------------------------------------------------------------------------#" << endl;
	cout << "|                            FELICITACIONES!!                                    |" << endl;
	cout << "|   _ _ _      _ _      _       _      _ _        _ _ _    _ _ _ _ _    _ _ _ _  |" << endl;
	cout << "| /||||    |||    ||_    ||   _|||    ||||  ||||||  ||||_| |" << endl;
	cout << "|||  _ _   ||_ ||  |||_  ||  ||_ ||  || _         ||      ||_ _    |" << endl;
	cout << "||| |||  |||||  || ||||  |||||    |||       ||      ||||   |" << endl;
	cout << "||| _ |  ||   ||  ||   |||  ||   ||   _ _ ||      ||      ||_ _ _  |" << endl;
	cout << "|  ||||  ||   ||  ||     ||  ||   ||  ||||        ||      ||||_| |" << endl;
	cout << "#--------------------------------------------------------------------------------#" << endl;
	_getch();
	return 0;
}

int gameOver()
{
	system("color 0f");
	cout << endl;
	cout << endl;
	cout << "#----------------------------------------------------------------------#" << endl;
	cout << "|                                                                      |" << endl;
	cout << "|  __ ___ ___ ___      __  _   _ ___   ___   |" << endl;
	cout << "| |  __ |__| |  |  | |__     |     |  | /  |__  |__/   |" << endl;
	cout << "| |__| |     | |  |  | |__     |_|  |/   |__  |    |   |" << endl;
	cout << "|                                                                      |" << endl;
	cout << "|                       Gracias Por Jugar...                           |" << endl;
	cout << "#----------------------------------------------------------------------#" << endl;
	_getch();
	return 0;
}

void dibumapa(int ** map) {
	system("cls");

	for (int i = 0; i < FILAS; i++)
	{
		for (int j = 0; j < COLUMNAS; j++)
		{
			if (map[i][j] == 2) {
				Console::ForegroundColor = ConsoleColor::Blue;
				Console::SetCursorPosition(j, i);
				cout << char(219);
			}
			if (map[i][j] == 4) {
				Console::ForegroundColor = ConsoleColor::Red;
				Console::SetCursorPosition(j, i);
				cout << char(219);
			}
			if (map[i][j] == 7) {
				Console::ForegroundColor = ConsoleColor::Red;
				Console::SetCursorPosition(j, i);
				cout << "|";
			}

		}
	}
}

void crearmapa(int ** mapa)
{
	for (int i = 0; i < FILAS; i++)
	{
		for (int j = 0; j < COLUMNAS; j++)
		{
			if (i == 0 || j == 0 || i == FILAS - 1 || j == COLUMNAS - 1) {
				mapa[i][j] = 2;
			}
			else if ((j == COLUMNAS - 2 && i > FILAS - 18) ||
				(j == COLUMNAS - 4 && i > FILAS - 18) ||
				(j == COLUMNAS - 6 && i > FILAS - 18) ||
				(i == FILAS - 18 && j > COLUMNAS - 7))
			{
				mapa[i][j] = 4;
			}

			else {
				mapa[i][j] = 0;
			}

		}
	}
}
void crearpiezapez(char * pieza) {
	char mataux[2] = { char(62),char(79) };

	for (int i = 0; i < 2; i++)
	{
		pieza[i] = mataux[i];
	}
}
void crearpiezapez2(char * pieza) {
	char mataux[2] = { char(79),char(60) };

	for (int i = 0; i < 2; i++)
	{
		pieza[i] = mataux[i];
	}
}
void crearpiezapezatrapado(char * pieza) {
	char mataux[2] = { char(64),0 };

	for (int i = 0; i < 2; i++)
	{
		pieza[i] = mataux[i];
	}
}
void crearpiezacaña(char * pieza)
{
	char mataux[2] = { char(124),0 };

	for (int i = 0; i < 2; i++)
	{
		pieza[i] = mataux[i];
	}
}
void crearpiezatiburon(char * pieza) {
	Console::ForegroundColor = ConsoleColor::Magenta;
	char mataux[4] = { char(62),char(94),char(111),char(62) };

	for (int i = 0; i < 4; i++)
	{
		pieza[i] = mataux[i];
	}
}
void crearpiezatiburon2(char * pieza) {
	Console::ForegroundColor = ConsoleColor::Magenta;
	char mataux[4] = { char(60),char(111),char(94),char(60) };

	for (int i = 0; i < 4; i++)
	{
		pieza[i] = mataux[i];
	}
}
void crearpiezapersona() {
	Console::SetCursorPosition(COLUMNAS - 10, 3);
	Console::ForegroundColor = ConsoleColor::Yellow;
	cout << "      " << char(219) << char(219) << endl;
	Console::SetCursorPosition(COLUMNAS - 10, 4);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "  __o=" << char(219) << char(219) << endl;
	Console::SetCursorPosition(COLUMNAS - 10, 5);
	Console::ForegroundColor = ConsoleColor::Blue;
	cout << "      " << char(219) << char(219) << endl;

}
char pez[2][2] = { {'>','o'} ,{'o','<'} };
char tibu[2][3] = { {'>','=','o'} ,{'o','=','<'} };
void mover(Pescado& a) {
	if (a.x + a.dx < a.limizq || a.x + a.dx + a.ancho>a.limder)
	{
		a.dx = -a.dx;
	}
	a.x += a.dx;
}


void dibujarpez(Pescado pz) {
	for (int i = 0; i < pz.ancho; i++)
	{
		Console::SetCursorPosition(pz.x + i, pz.y);
		cout << pez[pz.dx == -1][i];
	}
}

void dibujartibu(Pescado pz) {
	for (int i = 0; i < pz.ancho; i++)
	{
		Console::SetCursorPosition(pz.x + i, pz.y);
		cout << tibu[pz.dx == -1][i];
	}
}
void borrar(Pescado pz) {
	for (int i = 0; i < pz.ancho; i++)
	{
		Console::SetCursorPosition(pz.x + i, pz.y);
		cout << " ";
	}
}
int alturas[4]={10,13,16,19};
int puntos[4] ={ 10,12,14,16 };
void respawn(Pescado&pz, int ancho) {
	Random m;
	int altura = m.Next(4);
		pz.y = alturas[altura];
		pz.peso = puntos[altura];;
		pz.x = m.Next(2, COLUMNAS - 7);
		do
		{
			pz.dx = m.Next(-1, 2);

		} while (pz.dx == 0);
		pz.ancho = ancho;
		pz.limder = COLUMNAS - 5 - pz.ancho;
		pz.limizq = 1;
		pz.dy = 0;
	
}
void generador(int cant, Pescado*pz,int ancho) {
	Random m;
	for (int i = 0; i < cant; i++)
	{

		int altura = m.Next(4);
		pz[i].y = alturas[altura];
		pz[i].peso = puntos[altura];;
		pz[i].x = m.Next(2, COLUMNAS - 7);
		do
		{
		pz[i].dx = m.Next(-1,2);

		} while (pz[i].dx==0);
		pz[i].ancho = ancho;
		pz[i].limder=COLUMNAS-5-pz[i].ancho;
		pz[i].limizq=1;
		pz[i].dy = 0;
		if(ancho==3){
			pz[i].y = alturas[0];
		}
	}
}
bool colision(int x,int y,Pescado pz) {
	if (pz.x <= x && x < pz.ancho + pz.x&&pz.y == y) { return true; }
	return false;
}



bool movimiento(int cantpeces,int canttiburones,int**mapa,  int tiempo,int nivel) {
	dibumapa(mapa);
	crearpiezapersona();
	int presa=-1;
	Pescado*	arrpeces=new Pescado[cantpeces];
	Pescado*arrtiburones=new Pescado[canttiburones];
	anz jugador;
	generador(cantpeces, arrpeces, 2);
	generador(canttiburones, arrtiburones, 3);
	//tabla de informacion
	Console::SetCursorPosition(COLUMNAS + 11, 6);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "<TIEMPO>";
	Console::SetCursorPosition(COLUMNAS + 14, 7);
	Console::ForegroundColor = ConsoleColor::White;
	cout << tiempo<<" ";
	Console::SetCursorPosition(COLUMNAS + 10, 2);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "<PUNTAJE>" << endl;
	Console::SetCursorPosition(COLUMNAS + 14, 3);
	cout << jugador.puntos;
	Console::SetCursorPosition(COLUMNAS + 12, 9);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "<VIDAS>" << endl;
	Console::SetCursorPosition(COLUMNAS + 15, 10);
	cout << jugador.vidas;
	Console::SetCursorPosition(COLUMNAS + 12, 13);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "<NIVEL>" << endl;
	Console::SetCursorPosition(COLUMNAS + 15, 14);
	cout << nivel;
	Console::SetCursorPosition(COLUMNAS + 7, 17);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "<INSTRUCCIONES>" << endl;
	Console::SetCursorPosition(COLUMNAS + 7, 19);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "[^]:Subir ca" << char(164) << "a";
	Console::SetCursorPosition(COLUMNAS + 7, 20);
	Console::ForegroundColor = ConsoleColor::White;
	cout << "[v]:Bajar ca" << char(164) << "a";

	int dxtib = 1, dytib = 0;//direccion del tiburon
	int dxca = 0, dyca = 1;//direcciones de la ca?a

	while (tiempo>0&&jugador.vidas>0)
	{
		tiempo--;
		if (kbhit()) {
			int dy = 0;
			char tecla = _getch();
			switch (tecla)
			{
			case ARRIBA:dy=-1;break;
			case ABAJO: dy=1;break;
			default:break;
			}
			Console::SetCursorPosition(jugador.x, jugador.y); cout << " ";
			if (jugador.y + dy<5 || jugador.y + dy > FILAS - 2) { dy = 0; }
			jugador.y += dy;
			if (presa != -1) {
				borrar(arrpeces[presa]);
				arrpeces[presa].y += dy;
				if (arrpeces[presa].y == 6) {
					jugador.puntos += arrpeces[presa].peso; // puntaje que le das
					respawn(arrpeces[presa], 2);
					presa = -1;
					if (jugador.puntos >= 100/puntaje/) { return true; }
				}
			}
		}
			Console::SetCursorPosition(jugador.x, jugador.y); cout << "J";
		for (int i = 5; i < jugador.y; i++)
		{

			Console::SetCursorPosition(jugador.x, i); cout << "|";
		}
		//borrar figura pez , tiburon y caña
		for (int i = 0; i < cantpeces; i++) {

			if (presa == -1&&colision(jugador.x, jugador.y,arrpeces[i])) {
				presa = i;
				arrpeces[i].limizq = jugador.x - 3;
			}
			borrar(arrpeces[i]);
			mover(arrpeces[i]);
			dibujarpez(arrpeces[i]);
		}
		for (int i = 0; i < canttiburones; i++) {
			if (presa != -1 && colision( arrpeces[presa].x, arrpeces[presa].y, arrtiburones[i])) {
				borrar(arrpeces[presa]);
				respawn(arrpeces[presa], 2);
				presa = -1;
				jugador.vidas--;
			}
			borrar(arrtiburones[i]);
			mover(arrtiburones[i]);
			dibujartibu(arrtiburones[i]);
		}

		//dibujar peces con validacion derecha o izquierda
		


	



		//tabla de informacion
		Console::SetCursorPosition(COLUMNAS + 11, 6);
		Console::ForegroundColor = ConsoleColor::White;
		cout << "<TIEMPO>";
		Console::SetCursorPosition(COLUMNAS + 14, 7);
		Console::ForegroundColor = ConsoleColor::White;
		cout << tiempo;
		Console::SetCursorPosition(COLUMNAS + 10, 2);
		Console::ForegroundColor = ConsoleColor::White;
		cout << "<PUNTAJE>" << endl;
		Console::SetCursorPosition(COLUMNAS + 14, 3);
		cout << jugador.puntos;
		Console::SetCursorPosition(COLUMNAS + 12, 9);
		Console::ForegroundColor = ConsoleColor::White;
		cout << "<VIDAS>" << endl;
		Console::SetCursorPosition(COLUMNAS + 15, 10);
		cout << jugador.vidas;
		Console::SetCursorPosition(COLUMNAS + 12, 13);
		Console::ForegroundColor = ConsoleColor::White;
		cout << "<NIVEL>" << endl;
		Console::SetCursorPosition(COLUMNAS + 15, 14);
		cout << nivel;
		Console::SetCursorPosition(COLUMNAS + 7, 17);
		Console::ForegroundColor = ConsoleColor::White;
		cout << "<INSTRUCCIONES>" << endl;
		Console::SetCursorPosition(COLUMNAS + 7, 19);
		Console::ForegroundColor = ConsoleColor::White;
		cout << "[^]:Subir ca" << char(164) << "a";
		Console::SetCursorPosition(COLUMNAS + 7, 20);
		Console::ForegroundColor = ConsoleColor::White;
		cout << "[v]:Bajar ca" << char(164) << "a";


		//validacion cuando acaba el tiempo
		
		maslento(110);
		}
	return false;
	}



void main() {

	//creamos 2 numeros random
	system("color 1a");
	int*mapa = new int[FILAS];//matriz mapa
	for (int i = 0; i < FILAS; i++)
	{
		mapa[i] = new int[COLUMNAS];
	}

	char*pieza = new char; *pieza = pieza[2];
	char*pieza2 = new char; *pieza2 = pieza2[4];//matriz del tiburon
	char*pieza3 = new char; *pieza3 = pieza3[2];//matriz de la caña
	char*pieza4 = new char; *pieza4 = pieza3[2];//matriz de la caña

	int npeces = 7;//variable para el numero de peces
	Pescado *pez = new Pescado[npeces];//struct para los peces
	char*tecla = new char;
	int*puntaje = new int;
	int tiempo = 180;//variable para el tiempo que se desea
	*puntaje = 0;//inicializamos el puntaje en 0
	int vidas = 3;
	int nivel = 1;
	int direpeces = 1;
	
	int xtib = FILAS - 18, ytib = 6;//coordenadas del tiburon
	int xca = COLUMNAS - 8, yca = FILAS - 19;//coordenadas de la caña
	Console::CursorVisible = false;
	crearmapa(mapa);//asignamos la matriz del mapa
	crearpiezapez(pieza);
	crearpiezatiburon(pieza2);
	crearpiezacaña(pieza3);
	if (movimiento(6, 2/variacion del pez/, mapa, tiempo, nivel)) {//entramos al movimiento
		crearmapa(mapa);
		if (movimiento(8, 4/variacion del pez/, mapa, tiempo, nivel)) {//entramos al movimiento
			crearmapa(mapa);
			if (movimiento(6, 6/variacion del pez/, mapa, tiempo, nivel)) {//entramos al movimiento
				crearmapa(mapa);
				if (movimiento(10, 20/variacion del pez/, mapa, tiempo, nivel)) {//entramos al movimiento
					//creditos


				}
				else {
					//gameover
				}

			}
			else {
				//gameover
			}

		}
		else {
			//gameover
		}
	
	}
	else {
		//gameover
	}
	_getch();
}
