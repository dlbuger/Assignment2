#pragma once
#include "Trader.h"
#include <vector>

class Traders
{
protected:
	vector<Trader> traders;
	int id = 1;
	
public: 
	~Traders() {};
	void add(char type);
	Trader* find(int id);
	int numberOfTraders();
};

