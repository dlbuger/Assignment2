#include "Trader.h"


Trader::Trader(int id, String traderName, char traderType)
{
	this->id = id;
	this->traderName = traderName;
	this->traderType = traderType;
}

Bid Trader::generateBid()
{	
	double const MINPRICE = readDouble("Min Price");
	double const MAXPRICE = readDouble("Max Price");
	int const MINQUANTITY = readInt("Min Quantity");
	int const MAXQUANTITY = readInt("Max Quantity");

	double price = random<double>(MINPRICE, MAXPRICE);
	int quantity = random<int>(MINQUANTITY, MAXQUANTITY);

	return Bid(traderName, id, traderType, price, quantity);
}

Bid Trader::generateBid(int MINPRICE, int MAXPRICE, int MINQUANTITY, int MAXQUANTITY)
{
	int price = random<int>(MINPRICE, MAXPRICE);
	int quantity = random<int>(MINQUANTITY, MAXQUANTITY);
	
	return Bid(traderName, id, traderType, price, quantity);
}

int Trader::getId()
{
	return id;
}