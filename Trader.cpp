#include "Trader.h"


Trader::Trader(String traderName, char traderType)
{
	this->traderName = traderName;
	this->traderType = traderType;
}

Bid Trader::generateBid()
{
	double const MINPRICE = readDobule("Min Price");
	double const MAXPRICE = readDobule("Max Price");
	int const MINQUANTITY = readInt("Min Quantity");
	int const MAXQUANTITY = readInt("Max Quantity");

	double price = random<double>(MINPRICE, MAXPRICE);
	int quantity = random<int>(MINQUANTITY, MAXQUANTITY);

	return Bid(traderName, ++id, traderType, price, quantity);
}

int Trader::getId()
{
	return id;
}