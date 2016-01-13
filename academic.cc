#include "academic.h"
using namespace std;


void Academic::setOwner(Player *p) {
owner = p;
}

Player* Academic::getOwner() {
return owner;
}

string Academic::getDepartment() {
	return department;
}

Academic::Academic(string name, string department, int purchaseCost, int improvementCost, int tut0, int tut1, int tut2, int tut3, int tut4, int tut5):
Ownable(purchaseCost, false, name), improvementCost(improvementCost) {
owner = NULL;
tuitionImprovements[0] = tut0;
tuitionImprovements[1] = tut1;
tuitionImprovements[2] = tut2;
tuitionImprovements[3] = tut3;
tuitionImprovements[4] = tut4;
tuitionImprovements[5] = tut5;
improvementIndex = 0;

}
Academic::~Academic() {}

int Academic::getImprovementIndex() {

	return improvementIndex;
}

int Academic::getImprovementCost() {

return improvementCost;

}

int Academic::getFee() {
return tuitionImprovements[improvementIndex]; 

}

void Academic::setImprovement(int val) {improvementIndex=val;}

void Academic::incrImprovementIndex() {

improvementIndex++;

}
