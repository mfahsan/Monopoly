// ownable.h

#ifndef OWNABLE_H
#define OWNABLE_H
#include "block.h"
#include <string>

class Player;

class Ownable: public Block {
	int purchaseCost;
	bool mortgage;
	const std::string name;
	Player* owner;
        
          public:
	
        Ownable(int, bool, std::string);
	Player* getOwner();
        const std::string getName();
	int getPurchaseCost();
	bool isMortgaged();
	bool setMortgaged(bool);
	void setOwner(Player *p);
        virtual int getFee() = 0;
        virtual ~Ownable();
        
};

#endif
