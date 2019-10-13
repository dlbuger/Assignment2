#include "Bid.h"

Bid::Bid(String traderName, int bidId, char bidType, double price, int quantity)
{
	this->traderName = traderName;
	this->bidId = bidId;
	this->bidType = bidType;
	this->price = price;
	this->quantity = quantity;
}

char Bid::getType()
{
	return bidType;
}
double Bid::getPrice()
{
	return price;
}
int Bid::getQuantity()
{
	return quantity;
}

void Bid::setQuantity(int quantity)
{
	this->quantity = quantity;
}

String Bid::toString()
{
	return "( " + traderName + ",   " + to_string(bidId) + ",   " + bidType + ",   " + to_string(price) + ",   " + to_string(quantity) + " )";
}
