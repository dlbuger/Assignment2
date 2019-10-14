#include "Auctioneer.h"

Auctioneer::Auctioneer(vector<Bid> buyBids, vector<Bid> sellBids)
{
	this->buyBids = buyBids;
	this->sellBids = sellBids;
	matchingBids();
	toFile();
	
	cout << matchedBids[0].toString() << endl;
}

bool Auctioneer::isMatched(Bid buyBid, Bid sellBid)
{
	if (buyBid.getPrice() >= sellBid.getPrice())
		return true;
	else
		return false;
}

void Auctioneer::matchingBids()
{
	int _tmp = 0;
	for (vector<Bid>::iterator i = buyBids.begin(); i != buyBids.end(); i++)
	{
		for (vector<Bid>::iterator j = sellBids.begin(); j != sellBids.end(); j++)
		{
			if (isMatched(*i, *j))
			{
				matchedBids.push_back(Match(*i, *j));
				cout << matchedBids.size() << endl;
				
				if (j->getQuantity() - matchedBids.back().getQuantity() == 0)
				{
					j = sellBids.erase(j);
					i = buyBids.erase(i);
				}
				else 
				{
					j->setQuantity(j->getQuantity() - matchedBids.back().getQuantity());
					i->setQuantity(j->getQuantity() - matchedBids.back().getQuantity());
				}
			}
			if (j == sellBids.end()) break;
		} // 内循环结束
		if (i == buyBids.end()) break;
	} // 外循环结束
	cout << "匹配完成！" << endl;
}



void Auctioneer::toFile()
{
	ofstream out("output.txt", ios::app);
	out << "Matched Bids: \n";

	for (Match i : matchedBids)
		out << i.getName() + "\n";

	out << "Unmatched Ask Bids: \n";
	for (Bid i : sellBids)
		out << i.toString() + "\n";
	out << "Unmatched Buy Bids: \n";
	for (Bid i : buyBids)
		out << i.toString() + "\n";
	out.close();

}

vector<Bid> Auctioneer::getBuyBids()
{
	return buyBids;
}

vector<Bid> Auctioneer::getSellBids()
{
	return sellBids;
}