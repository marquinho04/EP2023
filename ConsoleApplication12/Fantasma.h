#pragma once
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;
char mapa_fantasma[4][5] = {
	{' ','_','_','_',' '},
	{'/','o',' ','o',92},
	{'|',' ',' ',' ','|'},
	{'|',',',',',',','|'}
};
class Fantasma
{
public:
	Fantasma(int x, int y);
	~Fantasma();
	void borrar();
	bool validarMovimiento();
	void mover();
	void dibujar(int color);
	void setDX(int d);
	void setDY(int d);
	int getX();
	int getY();
	int getAncho();
	int getAlto();
	void movimientoInvalido();
	bool colision(Rectangle rectangulo);
	Rectangle getRectangulo();
private:
	int x, y, dx, dy, ancho, alto;
	char** figura;
	int velocidad, aceleracion;
};

Fantasma::Fantasma(int x, int y)
{
	this->x = x;
	this->y = y;
	do
	{
		dx = rand() % 2 - 1;
		dy = rand() % 2 - 1;
	} while (dx == 0 && dy == 0);

	ancho = 5;
	alto = 4;
	figura = new char* [alto];
	for (int i = 0; i < alto; i++)
	{
		figura[i] = new char[ancho];
		for (int j = 0; j < ancho; j++)
		{
			figura[i][j] = mapa_fantasma[i][j];
		}
	}
}

Fantasma::~Fantasma() {
	for (int i = 0; i < alto; i++)
	{
		delete[] figura[i];
	}
	delete[] figura;
}
void Fantasma::borrar() {
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
	}
}
bool Fantasma::validarMovimiento() {
	return x + dx < 0 || x + dx + ancho>100 || y + dy < 0 || y + dy + alto>24;
}

void Fantasma::mover() {
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
void Fantasma::dibujar(int color) {
	for (int i = 0; i < alto; i++)
	{
		for (int j = 0; j < ancho; j++)
		{
			switch (color) {
			case 0:
				Console::ForegroundColor = ConsoleColor::Red;
				break;
			case 1:
				Console::ForegroundColor = ConsoleColor::Blue;
				break;
			case 2:
				Console::ForegroundColor = ConsoleColor::Green;
				break;
			case 3:
				Console::ForegroundColor = ConsoleColor::Magenta;
				break;
			}
			Console::SetCursorPosition(x + j, y + i);
			cout << figura[i][j];
		}
	}
}
void Fantasma::setDX(int d) { dx = d; }
void Fantasma::setDY(int d) { dy = d; }
int Fantasma::getX() { return x; }
int Fantasma::getY() { return y; }
int Fantasma::getAncho() { return ancho; }
int Fantasma::getAlto() { return alto; }
void Fantasma::movimientoInvalido() {
	do
	{
		dx = rand() % 3 - 1;
		dy = rand() % 3 - 1;
	} while (dx == 0 && dy == 0);
}
bool Fantasma::colision(Rectangle rectangulo) {
	return rectangulo.IntersectsWith(getRectangulo());
}
Rectangle Fantasma::getRectangulo() { return Rectangle(x, y, ancho, alto); }


