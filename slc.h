// slc.h
#ifndef SLC_H
#define SLC_H
#include "chance.h"

class Board;
class Player;
class SLC: public Chance {
	public:
	SLC(Board*);
	bool performAction(Player& player);
	~SLC();
};

#endif
