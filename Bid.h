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
	int price;
	int quantity;

public:
	Bid(String traderName, int bidId, char bidType, int price, int quantity);
	Bid() {};
	~Bid() {};

	char getType();
	int getPrice();
	int getQuantity();
	String getName();

	void setQuantity(int quantity);
	String toString();
};

