#pragma once
#include "Traders.h"
#include <vector>


// A类是卖家， B类是买家

class Buyers : public Traders
{
private:
	const char TRADERTYPE = 'B';

	
public:
	~Buyers() {};
	void add();
};

