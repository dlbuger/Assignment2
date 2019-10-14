#include "Auctioneer.h"

Auctioneer::Auctioneer(vector<Bid>* buyBids, vector<Bid>* sellBids)
{
	this->buyBids = buyBids;
	this->sellBids = sellBids;
	matchingBids();
	toFile();
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
	for (vector<Bid>::iterator i = buyBids->begin(); i != buyBids->end(); i++)
	{
		for (vector<Bid>::iterator j = sellBids->begin(); j != sellBids->end(); j++)
		{
			// 1. �ж��Ƿ�ƥ��
			if (isMatched(*i, *j))
			{
				// 2. ��ƥ�����ӽ�vector
				matchedBids->push_back(Match(*i, * j));
				// 3. �޸�ƥ�������� Match ==> tradeQuantity
				int _tradeQuantity = matchedBids->back().getQuantity();
				// 4. �޸�ƥ�������� Bids
				i->setQuantity(i->getQuantity() - _tradeQuantity);
				j->setQuantity(j->getQuantity() - _tradeQuantity);
				// 5. �жϣ�

				//		1��buyBid ������ - tradeQuantity �Ƿ�С�� ����0
				//			1: erase
				if (j->getQuantity() == 0)
					j = sellBids->erase(j);
		
				//		2) sellBid ������ - tradeQuantity �Ƿ�С�� ����0
				//			1: erase
				if (i->getQuantity() == 0)
					i = buyBids->erase(i);
		
			}

			/* 
			if (isMatched(*i, *j))
			{
				
				matchedBids->push_back(Match(*i, *j));
				if (j->getQuantity() - matchedBids->back().getQuantity() == 0)
				{
					j = sellBids->erase(j);
					i = buyBids->erase(i);
				}
				else 
				{
					j->setQuantity(j->getQuantity() - matchedBids->back().getQuantity());
					i->setQuantity(j->getQuantity() - matchedBids->back().getQuantity());
				}
			}
			*/
			if (j == sellBids->end()) break;
		} // ��ѭ������
		if (i == buyBids->end()) break;
	} // ��ѭ������
	cout << "Match Complete��" << endl;
}



void Auctioneer::toFile()
{
	ofstream out("output.txt", ios::app);
	out << "Matched Bids: " << endl;
	
	for (Match i : *matchedBids)
		out << i.toString()  << endl;

	out << "Unmatched Ask Bids: \n";
	for (Bid i : *sellBids)
		out << i.toString() + "\n";
	out << "Unmatched Buy Bids: \n";
	for (Bid i : *buyBids)
		out << i.toString() + "\n";
	out.close();
}

Auctioneer::~Auctioneer()
{
	delete buyBids, sellBids;
}

