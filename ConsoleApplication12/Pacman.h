#pragma once
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;
char mapa_pacman[4][5] = {
	{' ','_','_',' ',' '},
	{'/',' ','o',92,' '},
	{'|',' ',' ',' ','<'},
	{92,'_','_','/',' '}
};
class Pacman
{
public:
	Pacman();
	~Pacman();
	void borrar();
	bool validarMovimiento();
	void movimientoInvalido();
	void mover();
	void dibujar();
	void setDX(int d);
	void setDY(int d);
	int getX();
	int getY();
	int getAncho();
	int getAlto();
	void posInicial();
	bool colision(Rectangle rectangulo);
	Rectangle getRectangulo();
private:
	int x, y, dx, dy, ancho, alto;
	char** figura;
	int velocidad, aceleracion;
};
void Pacman::posInicial() {
	x = 0; y = 0;
}
Pacman::Pacman()
{
	x = 0;
	y = 0;
	dx = 0; dy = 0;
	ancho = 5;
	alto = 4;
	figura = new char* [alto];
	for (int i = 0; i < alto; i++)
	{
		figura[i] = new char[ancho];
		for (int j = 0; j < ancho; j++)
		{
			figura[i][j] = mapa_pacman[i][j];
		}
	}
}

Pacman::~Pacman() {
	for (int i = 0; i < alto; i++)
	{
		delete[] figura[i];
	}
	delete[] figura;
}
void Pacman::borrar() {
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
	}
}
bool Pacman::validarMovimiento() {
	return x + dx < 0 || x + dx + ancho>100 || y + dy < 0 || y + dy + alto>24;
}
void Pacman::movimientoInvalido() { dx = 0, dy = 0; }

void Pacman::mover() {
	if (aceleracion >= velocidad)
	{
		x += dx; y += dy;
		aceleracion = 0;
	}
	else
	{
		aceleracion++;
	}
}
void Pacman::dibujar() {
	for (int i = 0; i < alto; i++)
	{
		for (int j = 0; j < ancho; j++)
		{
			Console::ForegroundColor = ConsoleColor::Yellow;
			Console::SetCursorPosition(x + j, y + i);
			cout << figura[i][j];
		}
	}
}
void Pacman::setDX(int d) { dx = d; }
void Pacman::setDY(int d) { dy = d; }
int Pacman::getX() { return x; }
int Pacman::getY() { return y; }
int Pacman::getAncho() { return ancho; }
int Pacman::getAlto() { return alto; }

bool Pacman::colision(Rectangle rectangulo) {
	return rectangulo.IntersectsWith(getRectangulo());
}
Rectangle Pacman::getRectangulo() { return Rectangle(x, y, ancho, alto); }

