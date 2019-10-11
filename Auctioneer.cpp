#include "Auctioneer.h"

Auctioneer::Auctioneer()
{

}

bool Auctioneer::isMatched(Bid buyBid, Bid sellBid)
{
	if (buyBid.getPrice >= sellBid.getPrice)
		return true;
	else
		return false;
}

void Auctioneer::matchingBids()
{
	for (Bid i : buyBids)
		for (Bid j : sellBids)
			if (isMatched(i, j))
			{
				// ��ƥ���Bid ��ӽ�
				matchedBids.push_back(Match(i, j));
				// �޳���ƥ���Bid
				sellBids.erase(j);
			}
}