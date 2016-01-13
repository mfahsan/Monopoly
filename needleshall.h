// needleshall.h

#ifndef NEEDLESHALL_H
#define NEEDLESHALL_H
#include "chance.h"
class Board;
class Player;
class NeedlesHall: public Chance {
	public:
	NeedlesHall(Board*);
	~NeedlesHall();
	bool performAction(Player& player);
};

#endif
