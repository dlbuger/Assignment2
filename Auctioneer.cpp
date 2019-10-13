#include "Auctioneer.h"

Auctioneer::Auctioneer(vector<Bid> buyBids, vector<Bid> sellBids)
{
	this->buyBids = buyBids;
	this->sellBids = sellBids;
	matchingBids();

	for (Match i : matchedBids)
		cout << i.toString() << endl;
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
	for (vector<Bid>::iterator i = buyBids.begin(); i != buyBids.end(); i++)
	{
		for (vector<Bid>::iterator j = sellBids.begin(); j != sellBids.end(); j++)
		{
			if (isMatched(*i, *j))
			{
				matchedBids.push_back(Match(*i, *j));
				if (j->getQuantity() - matchedBids.back().getQuantity() == 0)
				{
					sellBids.erase(j);
					buyBids.erase(i);
				}
				else {
					j->setQuantity(j->getQuantity() - matchedBids.back().getQuantity());
					i->setQuantity(j->getQuantity() - matchedBids.back().getQuantity());
				}
			}
		} // 内循环结束
	} // 外循环结束
	cout << "匹配完成！" << endl;
}

String Auctioneer::toString()
{
	String tmp = "Matched Bids: \n";
	for (Match i : matchedBids)
		tmp += i.toString();
	tmp += "Unmatched Ask Bids: \n";
	for (Bid i : sellBids)
		tmp += i.toString();
	tmp += "Unmatched Buy Bids: \n";
	for (Bid i : buyBids)
		tmp += i.toString();

	return tmp;
}

vector<Bid> Auctioneer::getBuyBids()
{
	return buyBids;
}

vector<Bid> Auctioneer::getSellBids()
{
	return sellBids;
}