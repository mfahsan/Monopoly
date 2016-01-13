#ifndef GYM_H
#define GYM_H
#include <random>
#include <string>
#include "ownable.h"

class Player;

class Gym: public Ownable {

int cost;
Player *owner;
std::string name; 


public: 

Gym(int cost, std::string name);

void setOwner(Player *); // sets the owner of the gymsubl re	

int getPurchaseCost();

int getFee();

int getFee(int move);  // gets the fee 
};
#endif
