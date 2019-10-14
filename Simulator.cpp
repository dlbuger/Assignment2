#include "Simulator.h"

Simulator::Simulator()
{
	/*
	NUMSELLER = readInt("Number of Sellers");
	NUMBUYER = readInt("Number of Buyers");
	MINPRICE = readDouble("Min Price");
	MAXPRICE = readDouble("Max Price");
	MINQUANTITY = readInt("Min Quantity");
	MAXQUANTITY = readInt("Max Quantity");
	*/

	NUMSELLER = 10;
	NUMBUYER = 10;
	MINPRICE = 50;
	MAXPRICE = 150;
	MINQUANTITY = 1;
	MAXQUANTITY = 50;


	setupTraders();
	setupBids();

	ofstream out("output.txt");

	out << "Generated bids: " << endl;
	out << "(traderName, bidId, bidType, price, quantity)" << endl;
	for (auto i : sells)
		out << i.toString() << endl;
	for (auto i : buys)
		out << i.toString() << endl;

	Auctioneer a1(buys, sells);

	cout << "Auction outcomes have been output to file output.txt" << endl;

}

void Simulator::setupTraders()
{
	for (int i = 0; i < NUMSELLER; i++)
		sellers.push_back(Trader(_traderId++, "Seller", 'A'));
	for (int i = 0; i < NUMBUYER; i++)
		buyers.push_back(Trader(_traderId++, "Buyer", 'B'));
	cout << sellers.size() << endl;
	cout << buyers.size() << endl;
}

void Simulator::setupBids()
{
	srand((unsigned)time(NULL));
	for (Trader i : sellers)
		sells.push_back(i.generateBid(MINPRICE, MAXPRICE, MINQUANTITY, MAXQUANTITY));
	for (Trader i : buyers)
		buys.push_back(i.generateBid(MINPRICE, MAXPRICE, MINQUANTITY, MAXQUANTITY));
}
