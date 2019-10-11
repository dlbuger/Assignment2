#pragma once
#include <iostream>
#include <string>

using namespace std;
typedef string String;

class Bid
{
private:
	String traderName;
	int bidId;
	char bidType;
	double price;
	int quantity;

public:
	Bid(String traderName, int bidId, char bidType, double price, int quantity);
	~Bid() {};

	char getType();
	double getPrice();
	int getQuantity();

	String toString();
};

