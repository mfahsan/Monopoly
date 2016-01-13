#include "gym.h" 
#include "player.h"
using namespace std;

Gym::Gym(int cost, string name): Ownable(cost,false,name) {
	owner = NULL;
}

void Gym::setOwner(Player *p) {
	owner = p;
}

int Gym::getFee(int move) {
	if (owner) {
		int l = owner->getNumGym();
		if (l==1) {return move*4;}
		else if (l==2) {return move*10;}
		else return 0;
	} else return 0;
}

int Gym::getFee() {}

int Gym::getPurchaseCost() {

	return cost;
}
