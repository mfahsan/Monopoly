#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Player {

// the amount of money the player has
int numRes; // the number of residences the player owns 
int numGym; // the number of gyms the player owns
int numTimsCup;
int jailTurns;

std::string name;
char playerChar;

int money;

int posn; // returns the index of the array the player is in

public: 



Player(std::string name, char c, int amount); // takes in the name, character used to represent, and the amount of money it starts with. All other fields set to 0.

std::string getName();

void move(int amount); // moves the player to the new position by amount

int getPosn();

void setPosn(int position); 

void incrNumRes(); // increments the number of residences a player owns by 1

void incrNumGym(); // increments the number of gyms a player owns by 1

int getNumRes(); // getter for the number of residences a player owns

int getNumGym(); // getter for the number of gyms a player owns

char getChar();

void changeMoney(int amount); // increases or decreases money by amount
int getMoney(); 
void setTimsCup(int num);

int getTimsCup();

void setJailTurns(int turns);

void setChar(char);

void setMoney(int);

void setName(std::string);

int getJailTurns();
};

#endif
