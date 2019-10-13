#include "Match.h"
Match::Match(Bid buyBid, Bid sellBid)
{
	matches[0] =  &buyBid;
	matches[1] = &sellBid;
	sync();
}

String Match::toString()
{
	return matches[0]->toString() + " < = > " + matches[1]->toString() + " With clearingPrice: " + to_string(clearingPrice) + "\n";
}

void Match::sync()
{
	clearingPrice = (matches[0]->getPrice() + matches[1]->getPrice()) / 2; // clear price = (a + b) / 2
	tradeQuantity = findMin();
	matches[0]->setQuantity(tradeQuantity);
	matches[1]->setQuantity(tradeQuantity);
}

int Match::findMin()
{
	if (matches[0]->getQuantity() < matches[1]->getQuantity())
		return matches[0]->getQuantity();
	else
		return matches[1]->getQuantity();
}

int Match::getQuantity()
{
	return tradeQuantity;
}

