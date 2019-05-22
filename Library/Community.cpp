#include "stdafx.h"
#include "Community.h"
int Community::getReadingRank()
{
	int rank = 0;
	for (int i = 0; i < getSize(); i++) {
		rank+=(*this)[i].getReadingRank();
	}
	return rank;
}
