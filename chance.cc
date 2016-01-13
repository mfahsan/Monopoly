//chance.cc
#include "chance.h"
#include "board.h"
using namespace std;

Chance::Chance(Board* b):board(b) {}
Chance::~Chance() {}
bool Chance::performAction(Player& player) {
	default_random_engine gen;
	uniform_int_distribution<int> dist(1,100);
	int randNum = dist(gen);
	// (if) checks for 1 percent chance
	if (randNum == 69) {
		board->giveTimsCup(player);
		return true;
	}//if
	return false;
}
