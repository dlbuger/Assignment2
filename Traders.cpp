#include "Traders.h"

void Traders::add(char type)
{
	traders.push_back(Trader(id++, readString("Name"), type));
}

Trader* Traders::find(int id)
{
	for (Trader c : traders)
		if (c.getId() == id)
			return &c;
	return NULL;
}

int Traders::numberOfTraders()
{
	return traders.size();
}