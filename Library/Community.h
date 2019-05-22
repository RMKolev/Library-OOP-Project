#pragma once
#include"Set.h"
#include"ReadingRankable.h"
#include"Reader.h"
class Community : public Set<Reader>, public ReadingRankable {
private:

public:
	virtual int getReadingRank();
};
