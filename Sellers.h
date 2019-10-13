#pragma once
#include "Traders.h"

class Sellers : public Traders
{
private:
	const char TRADERTYPE = 'A';

public:
	~Sellers() {};
	void add();
};