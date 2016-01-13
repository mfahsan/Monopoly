#ifndef ACADEMIC_H
#define ACADEMIC_H
#include "ownable.h"
#include <iostream>

class Player;

class Academic : public Ownable {

 


int improvementIndex;
    // cost of purchasing the building
int improvementCost;  // cost of improvements

int tuitionImprovements[6];  // array of the improvement costs
    
const std::string department;  // name of the block

Player *owner;



public:
Academic(std::string name, std::string department, int purchaseCost, int improvementCost, int tut0, int tut1, int tut2, int tut3, int tut4, int tut5); // constructor for Academic block

void setOwner(Player *p);

Player* getOwner();   // points to the player that owns it, NULL otherwise
  // getter for the purchase cost
int getImprovementCost(); // getter for the improvement cost
int getFee();
std::string getDepartment();  // getter for the tuition fees
int getImprovementIndex();
void incrImprovementIndex();
void setImprovement(int val);
~Academic(); 
};

#endif
