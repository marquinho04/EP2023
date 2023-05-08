#pragma once
#include "PacDots.h"
#include <vector>

class ArrPacdots {
public:
	ArrPacdots();
	~ArrPacdots();
	int size();
	PacDots* getObj(int pos);
	void eliminar(int pos);
private:
	vector<PacDots*> arr;
	int n;
};

ArrPacdots::ArrPacdots() {
	n = 100;
	for (int i = 0; i < n; i++) {
		arr.push_back(new PacDots());
	}
}

ArrPacdots::~ArrPacdots() {}

PacDots* ArrPacdots::getObj(int pos) { return arr[pos]; }

int ArrPacdots::size() { return n; }

void ArrPacdots::eliminar(int pos) {
	arr.erase(arr.begin() + pos);
	n = arr.size();
}
