#include "residence.h"
#include <cmath>
#include "player.h"
using namespace std;

Residence::Residence(int cost, string name): Ownable(cost,false,name) {
  owner = NULL;
  rent = 0;
}

void Residence::setOwner(Player *p) {
	owner = p;
}

int Residence::getFee() {
	if (isMortgaged()) {
		return 0;
	} else if (owner) {
		int l = owner->getNumRes();
		rent = 25 * pow (2, l);
		return rent;
	}
	return 0;
}



