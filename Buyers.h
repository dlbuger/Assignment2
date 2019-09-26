#pragma once
#include "Traders.h"
#include <vector>


// A类是买家， B类是卖家
// 
class Buyers : public Traders
{
private:
	const char TRADERTYPE = 'A';

	
public:
	~Buyers() {};
	void add();
};

