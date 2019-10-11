#pragma once
#include "Bid.h"

class Match
{
private:
	Bid* matches[2];

public:
	Match(Bid bid1, Bid bid2);
	~Match() {};
	String toString();

};

