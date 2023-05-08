#pragma once
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;
class PacDots
{
public:
	PacDots();
	~PacDots();
	void borrar();
	void dibujar();
	bool colision(Rectangle rectangulo);
	Rectangle getRectangulo();
private:
	int x, y, dx, dy, ancho, alto;
	char** figura;
};

PacDots::PacDots() {//100*20
	x = rand() % 100;//0-99
	y = rand() % 14 + 4;//4-14
	dx = 0; dy = 0;
	ancho = 1;
	alto = 1;
	figura = new char* [alto];
	figura[0] = new char[ancho];
	figura[0][0] = 4;
}
PacDots::~PacDots() {
	for (int i = 0; i < alto; i++)
	{
		delete[] figura[i];
	}
	delete[] figura;
}
void PacDots::borrar() {
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
	}
}

void PacDots::dibujar() {
	for (int i = 0; i < alto; i++)
	{
		for (int j = 0; j < ancho; j++)
		{
			Console::ForegroundColor = ConsoleColor::Red;
			Console::SetCursorPosition(x + j, y + i);
			cout << figura[i][j];
		}
	}
}
bool PacDots::colision(Rectangle rectangulo) {
	return rectangulo.IntersectsWith(getRectangulo());
}
Rectangle PacDots::getRectangulo() { return Rectangle(x, y, ancho, alto); }

