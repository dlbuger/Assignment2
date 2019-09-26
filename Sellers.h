#pragma once
#include "Traders.h"

class Sellers : public Traders
{
private:
	const char TRADERTYPE = 'B';

public:
	void add();
};