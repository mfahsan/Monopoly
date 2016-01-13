#ifndef RESIDENCE_H
#define RESIDENCE_H
#include "ownable.h"

class Player;

class Residence: public Ownable{

Player *owner; // points to the owner
int rent;

public: 

Residence(int cost, std::string name);

void setOwner(Player *a); // sets the owner of the residence as player a

void setFee(); // sets the rent according to the number of residences a player owns

int getFee();  // gets the rent

};

#endif
