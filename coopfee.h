// coopfee.h
#ifndef COOPFEE_H
#define COOPFEE_H
#include "block.h"
#include "player.h"
/*****************************************************************
	<<type>> CoopFee
	
	Class represents the coopfee block of the bb7k game and 
	has every functionality that this block needs.
	
*****************************************************************/

class CoopFee: public Block {
	public:
	/*
		getTuition(player)
		purpose: applies the tuition to player
	*/
	void applyTuition(Player& player);
};

#endif
