#pragma once
#include <vector>
#include "Buyers.h"
#include "Sellers.h"
#include "Match.h"

using namespace std;

class Auctioneer
{
private:
	

	vector<Bid> buyBids;
	vector<Bid> sellBids;

	vector<Match> matchedBids;
	vector<Bid> unmatchedBids;
	bool isMatched(Bid buyBid, Bid sellBid);
	void matchingBids();

public:
	Auctioneer();
	~Auctioneer() {};

	

};

