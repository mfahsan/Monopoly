#include "coopfee.h"
// coopfee.cc

void CoopFee::applyTuition(Player& player) {
	// TODO: apply -150 to player's wallet
	player.changeMoney(-150);
}
