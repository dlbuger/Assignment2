#pragma once
#include "Bid.h"

class Match
{
private:
	Bid* matches[2];
	double clearingPrice;
	int tradeQuantity;
	void sync(); // ͬ��ƥ����Bids�� price �� quantity
	int findMin(); // ������С��quantity

public:
	Match(Bid buyBid, Bid sellBid);
	~Match() {};
	String getName();
	int getQuantity();

	String toString();

};

