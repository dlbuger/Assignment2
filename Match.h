#pragma once
#include "Bid.h"

class Match
{
private:
	Bid* matches[2];
	double clearingPrice;
	int tradeQuantity;
	void sync(); // 同步匹配后的Bids的 price 和 quantity
	int findMin(); // 返回最小的quantity

public:
	Match(Bid buyBid, Bid sellBid);
	~Match() {};
	String getName();
	int getQuantity();

	String toString();

};

