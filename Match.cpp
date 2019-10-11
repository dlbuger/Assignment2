#include "Match.h"
Match::Match(Bid bid1, Bid bid2)
{
	matches[0] = &bid1;
	matches[1] = &bid2;
}

String Match::toString()
{
	return matches[0]->toString() + " < = > " + matches[1]->toString();
}

