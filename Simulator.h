#pragma once
#include "Auctioneer.h"
#include <fstream>


class Simulator
{
private:
	vector<Trader> sellers;
	vector<Trader> buyers;

	vector<Bid> sells;
	vector<Bid> buys;

	int NUMSELLER;
	int NUMBUYER;
	double MINPRICE;
	double MAXPRICE;
	int MINQUANTITY;
	int MAXQUANTITY;

	int _traderId = 0;
	int _bidId = 0;
	int _sellerNum = 0;
	int _buyerNum = 0;

	void setupTraders();
	void setupBids();


public:
	Simulator();
	~Simulator() { };
};

