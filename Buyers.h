#pragma once
#include "Traders.h"
#include <vector>


// A������ң� B��������
// 
class Buyers : public Traders
{
private:
	const char TRADERTYPE = 'A';

	
public:
	~Buyers() {};
	void add();
};

