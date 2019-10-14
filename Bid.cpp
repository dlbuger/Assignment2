#include "Bid.h"

Bid::Bid(String traderName, int bidId, char bidType, int price, int quantity)
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
int Bid::getPrice()
{
	return price;
}
int Bid::getQuantity()
{
	return quantity;
}

String Bid::getName()
{
	return traderName;
}

void Bid::setQuantity(int quantity)
{
	this->quantity = quantity;
}

String Bid::toString()
{
	return "( " + traderName + ",   " + to_string(bidId) + ",   " + bidType + ",   " + to_string(price) + ",   " + to_string(quantity) + " )";
}
