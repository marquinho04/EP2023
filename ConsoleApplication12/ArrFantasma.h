#pragma once
#include "Fantasma.h"
#include <vector>

class ArrFantasma {
private:
	vector<Fantasma*> arr;
	int n;
public:
	ArrFantasma();
	~ArrFantasma();
	void moverTodos();
	int size();
	Fantasma* getObj(int pos);
};

ArrFantasma::ArrFantasma() {
	int posX;
	int posY;
	n = 4;
	for (int i = 0; i < n; i++) {
		posX = rand() % 91 + 5;
		posY = 0;
		arr.push_back(new Fantasma(posX, posY));
	}
}

ArrFantasma::~ArrFantasma() {
}

void ArrFantasma::moverTodos() {
	for (int i = 0; i < arr.size(); i++)
		arr[i]->mover();
}

int ArrFantasma::size() { return n; }

Fantasma* ArrFantasma::getObj(int pos) { return arr[pos]; }
