#include "Bid.h"

Bid::Bid(String traderName, int bidId, char bidType, double price, int quantity)
{
	this->traderName = traderName;
	this->bidId = bidId;
	this->bitType = bidType;
	this->price = price;
	this->quantity = quantity;
}


