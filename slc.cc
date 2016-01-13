// slc.cc
#include "slc.h"
#include "board.h"
#include <random>
using namespace std;

SLC::SLC(Board *board):Chance(board) {}
SLC::~SLC(){}

bool SLC::performAction(Player& player) {
	default_random_engine gen;
	uniform_int_distribution<int> dist2(1,24);
	int randNum = dist2(gen);
	
	if (Chance::performAction(player)) {
		return true;
	} else {
		// (if) checks for chances
		if (randNum >= 1 && randNum <= 3) {
			// back 3
			board->notifyMove(player, -3);
		} else if (randNum >= 4 && randNum <= 7) {
			// back 2
			board->notifyMove(player, -2);
		} else if (randNum >= 8 && randNum <= 11) {
			// back 1
			board->notifyMove(player, -1);
		} else if (randNum >= 12 && randNum <= 14) {
			// forward 1
			board->notifyMove(player, 1);
		} else if (randNum >= 15 && randNum <= 18) {
			// forward 2
			board->notifyMove(player, 2);
		} else if (randNum >= 19 && randNum <= 22) {
			// forward 3
			board->notifyMove(player, 3);
		} else if (randNum == 23) {
			// dc tims line
			board->putInTimsLine(player.getChar());
		} else {
			// collect osap
		}// if
	}
	return false;
}
