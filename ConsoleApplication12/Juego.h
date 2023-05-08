#pragma once
#include "ArrPacdots.h"
#include "ArrBonus.h"
#include "ArrFantasma.h"
#include "Pacman.h"
#include <time.h>
class Juego
{
public:
	Juego();
	~Juego();
	void setDireccion(int x, int dy);
	int jugar();
	void cambiarVelocidad(int);
	int getVelocidad();
	void setTiempoBonus(long);
	long getTiempoBonus();
	void setTiempoTotal(long);
	long getTiempoTotal();
	int getSizePacdots();

private:
	ArrPacdots* pacdots;
	ArrBonus* bonus;
	ArrFantasma* fantasmas;
	Pacman* pacman;
	int mulVelocidad;
	long tiempoBonus;
	long tiempoTotal;
	int contVida;
};

Juego::Juego()
{
	pacdots = new ArrPacdots();
	bonus = new ArrBonus();
	fantasmas = new ArrFantasma();
	pacman = new Pacman();
	mulVelocidad = 1;
	contVida = 3;
}

Juego::~Juego()
{
	delete pacdots;
	delete bonus;
	delete fantasmas;
	delete pacman;
}

void Juego::setDireccion(int dx, int dy) {
	pacman->setDX(dx);
	pacman->setDY(dy);
}

int Juego::jugar() {
	//--------MOVIMIENTOS

	for (int i = 0; i < pacdots->size(); i++)
	{
		pacdots->getObj(i)->dibujar();
	}

	for (int i = 0; i < bonus->size(); i++)
	{
		bonus->getObj(i)->dibujar();
	}

	for (int i = 0; i < fantasmas->size(); i++)
	{
		fantasmas->getObj(i)->borrar();
		if (fantasmas->getObj(i)->validarMovimiento())
		{
			fantasmas->getObj(i)->movimientoInvalido();
		}
		else
		{
			fantasmas->getObj(i)->mover();
		}
		fantasmas->getObj(i)->dibujar(i);
	}

	pacman->borrar();
	if (pacman->validarMovimiento())
	{
		pacman->movimientoInvalido();
	}
	else
	{
		pacman->mover();
	}
	pacman->dibujar();

	//colisiones

	for (int i = 0; i < pacdots->size(); i++)
	{
		if (pacman->colision(pacdots->getObj(i)->getRectangulo()))
		{
			pacdots->eliminar(i);
			i--;
		}
	}

	for (int i = 0; i < bonus->size(); i++)
	{
		if (pacman->colision(bonus->getObj(i)->getRectangulo()))
		{
			//falta aumento de velocidad en pacman
			bonus->eliminar(i);
			cambiarVelocidad(2);//x
			setTiempoBonus(clock());
			i--;
		}
	}

	if (pacdots->size() == 0)
	{
		return 1;//gano el juego
	}

	for (int i = 0; i < fantasmas->size(); i++)
	{
		if (pacman->colision(fantasmas->getObj(i)->getRectangulo()))
		{
			contVida--;
			if (contVida == 0)
			{
				return 2;//pierdo el juego
			}
			pacman->borrar();
			pacman->posInicial();
		}
	}
	if ((clock() - getTiempoTotal()) / CLOCKS_PER_SEC == 120)
	{
		return 2;
	}
	return 0;
}
void Juego::cambiarVelocidad(int multiplicador) {
	mulVelocidad = multiplicador;
}
int Juego::getVelocidad() {
	return mulVelocidad;
}
void Juego::setTiempoBonus(long tiempo) {
	tiempoBonus = tiempo;
}
long Juego::getTiempoBonus() {
	return tiempoBonus;
}
void Juego::setTiempoTotal(long tiempo) {
	tiempoTotal = tiempo;
}

long Juego::getTiempoTotal() {
	return tiempoTotal;
}
int Juego::getSizePacdots() {
	return pacdots->size();
}

