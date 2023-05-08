#pragma once
#include <iostream>
using namespace std;
using namespace System;
using namespace System::Drawing;
class Bonus
{
public:
	Bonus();
	~Bonus();
	void borrar();
	void dibujar();

	bool colision(Rectangle rectangulo);
	Rectangle getRectangulo();
private:
	int x, y, dx, dy, ancho, alto;
	char** figura;
};

Bonus::Bonus() {//100*23
	x = rand() % 100;//0-99
	y = rand() % 6 + 18;//18-23
	dx = 0; dy = 0;
	ancho = 1;
	alto = 1;
	figura = new char* [alto];
	figura[0] = new char[ancho];
	figura[0][0] = 16;
}
Bonus::~Bonus() {
	for (int i = 0; i < alto; i++)
	{
		delete[] figura[i];
	}
	delete[] figura;
}
void Bonus::borrar() {
	for (int i = 0; i < alto; i++) {
		for (int j = 0; j < ancho; j++) {
			Console::SetCursorPosition(x + j, y + i);
			cout << " ";
		}
	}
}

void Bonus::dibujar() {
	for (int i = 0; i < alto; i++)
	{
		for (int j = 0; j < ancho; j++)
		{
			Console::ForegroundColor = ConsoleColor::Blue;
			Console::SetCursorPosition(x + j, y + i);
			cout << figura[i][j];
		}
	}
}
bool Bonus::colision(Rectangle rectangulo) {
	return rectangulo.IntersectsWith(getRectangulo());
}
Rectangle Bonus::getRectangulo() { return Rectangle(x, y, ancho, alto); }

