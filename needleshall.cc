// needleshall.cc
#include "needleshall.h"
#include "player.h"
#include <random>
using namespace std;

NeedlesHall::NeedlesHall(Board *board):Chance(board) {}
NeedlesHall::~NeedlesHall() {}
bool NeedlesHall::performAction(Player& player) {
	default_random_engine gen;
	uniform_int_distribution<int> dist2(1,18);
	int randNum = dist2(gen);
	if (Chance::performAction(player)) {
		// roll up the tims cup
		return true;
	} else {	
		// (if) checks for chances
		if (randNum == 1) {
			// -$200
			player.changeMoney(-200);
		} else if (randNum == 2) {
			// +$200
			player.changeMoney(200);
		} else if (randNum >= 3 && randNum <= 4) {
			// -$100
			player.changeMoney(-100);
		} else if (randNum >= 5 && randNum <= 7) {
			// -$50
			player.changeMoney(-50);
		} else if (randNum >= 8 && randNum <= 13) {
			// +$25
			player.changeMoney(25);
		} else if (randNum >= 14 && randNum <= 16) {
			// +$50
			player.changeMoney(50);
		} else {
			// +$100
			player.changeMoney(100);
		}// if
	}
	return false;
}
