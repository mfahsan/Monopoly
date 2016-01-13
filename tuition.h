// tuition.h
#ifndef TUITION_H
#define TUITION_H
#include "player.h"
#include "block.h"

/*****************************************************************
	<<type>> Tuition
	
	Class represents the tuition block of the bb7k game and 
	has every functionality that a tutition block needs.
	
*****************************************************************/

class Tuition: public Block {
	public:
	/*
		getTuition(player, choice)
		purpose: applies the tuition to the player, given his choice.
		2 options for choice: 0 - the player chooses to pay 10% of their
								  total worth
							  1 - the player chooses to pay $300
	*/
	void applyTuition(Player& player, int choice);
};

#endif
