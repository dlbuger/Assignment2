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
				// 把匹配的Bid 添加进
				matchedBids.push_back(Match(i, j));
				// 剔除已匹配的Bid
				sellBids.erase(j);
			}
}