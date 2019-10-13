#include "Simulator.h"

Simulator::Simulator()
{
	NUMSELLER = readInt("Number of Sellers");
	NUMBUYER = readInt("Number of Buyers");
	MINPRICE = readDouble("Min Price");
	MAXPRICE = readDouble("Max Price");
	MINQUANTITY = readInt("Min Quantity");
	MAXQUANTITY = readInt("Max Quantity");

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
	out << a1.toString() << endl;
	cout << "Auction outcomes have been output to file output.txt" << endl;

}

void Simulator::setupTraders()
{
	for (int i = 0; i < NUMSELLER; i++)
		sellers.push_back(Trader(_traderId++, "Seller" + to_string(++_sellerNum), 'A'));
	for (int i = 0; i < NUMBUYER; i++)
		buyers.push_back(Trader(_traderId++, "Buyer" + to_string(++_buyerNum), 'B'));
}

void Simulator::setupBids()
{
	srand((unsigned)time(NULL));
	for (Trader i : sellers)
		sells.push_back(i.generateBid(MINPRICE, MAXPRICE, MINQUANTITY, MAXQUANTITY));
	for (Trader i : buyers)
		buys.push_back(i.generateBid(MINPRICE, MAXPRICE, MINQUANTITY, MAXQUANTITY));
}
