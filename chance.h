// chance.h
#ifndef CHANCE_H
#define CHANCE_H
#include "block.h"

class Board;
class Player;

class Chance: public Block {
	protected:
	Board *board;
	public:
	Chance(Board*);
	virtual ~Chance();
	virtual bool performAction(Player& player);
};
#endif
