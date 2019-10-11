#pragma once
#include<iostream>
#include "Bid.h"
#include "Tools.h"


class Trader
{
private: 
	String traderName;
	char traderType;
	int id;
public: 
	Trader(int id, String traderName, char traderType);
	Bid generateBid();
	int getId();
};

