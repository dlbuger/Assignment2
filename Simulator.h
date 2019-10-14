#pragma once
#include "Auctioneer.h"
#include "Trader.h"
#include <fstream>


class Simulator
{
private:
	vector<Trader>* sellers = new vector<Trader>;
	vector<Trader>* buyers =  new vector<Trader>;

	vector<Bid>* sells = new vector<Bid>;
	vector<Bid>* buys = new vector<Bid>;

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
	~Simulator();
};

