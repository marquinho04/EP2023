#pragma once
#include "Bonus.h"
#include <vector>

class ArrBonus {
public:
	ArrBonus();
	~ArrBonus();
	int size();
	Bonus* getObj(int pos);
	void eliminar(int pos);
private:
	vector<Bonus*> arr;
	int n;
};

ArrBonus::ArrBonus() {
	n = 10;
	for (int i = 0; i < n; i++) {
		arr.push_back(new Bonus());
	}
}

ArrBonus::~ArrBonus() {}

Bonus* ArrBonus::getObj(int pos) { return arr[pos]; }

int ArrBonus::size() { return n; }

void ArrBonus::eliminar(int pos) {
	arr.erase(arr.begin() + pos);
	n = arr.size();
}

