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
	Trader(String traderName, char traderType);
	Bid generateBid();
	int getId();
	
};
