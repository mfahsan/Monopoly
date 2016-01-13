// tuition.cc
#include "tuition.h"

// for function details, see .h file
void Tuition::applyTuition(Player& player, int choice) {
	// (if) checks for choice, see .h file
	if (choice) {
		// 10%
		//int totWorth = player.getWorth();
		// TODO: apply -(0.10*totWorth) to player's wallet
		
	} else {
		// TODO: apply -300 to player's wallet
		player.changeMoney(-300);
		
	}
}
