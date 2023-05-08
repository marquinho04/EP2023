#include "pch.h"
#include "Juego.h"
#include <conio.h>
int main() {
	Console::SetWindowSize(150, 24);
	Console::CursorVisible = false;
	srand(time(0));
	Juego* juego = new Juego();
	int res = 0;
	juego->setTiempoTotal(clock());
	while (res == 0)
	{
		switch (juego->jugar()) {
		case 1:
			Console::SetCursorPosition(101, 4);
			cout << "Gano" << endl; res = 1;
			Console::SetCursorPosition(101, 6);
			cout << "Cantidad de Pacdots que fueron comidos: " << 100 - juego->getSizePacdots() << endl;
			break;
		case 2:
			Console::SetCursorPosition(101, 4);
			cout << "Perdio" << endl; res = 2;
			Console::SetCursorPosition(101, 6);
			cout << "Cantidad de Pacdots que fueron comidos: " << 100 - juego->getSizePacdots() << endl;
			break;
		default:
			Console::SetCursorPosition(101, 6);
			cout << "Cantidad de Pacdots que fueron comidos: " << 100 - juego->getSizePacdots() << endl;
		}

		//direcciones de pacman
		if (kbhit())
		{
			if (juego->getVelocidad() == 2) {
				if ((clock() - juego->getTiempoBonus()) / CLOCKS_PER_SEC >= 5) {
					juego->cambiarVelocidad(1);
				}
			}
			switch (toupper(getch()))
			{
			case 'A': juego->setDireccion(-1 * juego->getVelocidad(), 0); break;
			case 'D': juego->setDireccion(1 * juego->getVelocidad(), 0); break;
			case 'W': juego->setDireccion(0, -1 * juego->getVelocidad()); break;
			case 'S': juego->setDireccion(0, 1 * juego->getVelocidad()); break;
			}
		}
		else
		{
			juego->setDireccion(0, 0);
		}

		_sleep(50);
	}
	delete juego;
	_sleep(10000);
	cin.get();
	return 0;
}

