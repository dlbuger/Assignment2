#pragma once
#include <iostream>

using namespace std;
typedef string String;

class Bid
{
private:
	String traderName;
	int bidId;
	char bitType;
	double price;
	int quantity;

public:
	Bid(String traderName, int bidId, char bidType, double price, int quantity);
	~Bid() {};
};

