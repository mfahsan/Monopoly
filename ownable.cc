// ownable.cc
#include "ownable.h"
using namespace std;

Ownable::Ownable(int pc, bool m, string name):purchaseCost(pc),mortgage(m),name(name) {}

const string Ownable::getName() {return name;}
int Ownable::getPurchaseCost() {return purchaseCost;}
bool Ownable::isMortgaged() {return mortgage;}
bool Ownable::setMortgaged(bool val) {mortgage=val;}

Player* Ownable::getOwner() {return owner;} 
void Ownable::setOwner(Player *p) {owner = p;}

Ownable::~Ownable() {}
