#pragma once
#include <vector>
#include "Match.h"
#include <fstream>

using namespace std;

class Auctioneer
{
private:
	
	vector<Bid>* buyBids = new vector<Bid>;
	vector<Bid>* sellBids = new vector<Bid>;

	vector<Match>* matchedBids = new vector<Match>;
	
	bool isMatched(Bid buyBid, Bid sellBid);
	void matchingBids();
	

public:
	Auctioneer(vector<Bid>* buyBids, vector<Bid>* sellBids);
	~Auctioneer();

	void toFile();

};

