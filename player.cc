#include "player.h"
#include <iostream>
using namespace std;


char Player::getChar() {return playerChar;}

Player::Player(string name, char c, int money) : playerChar(c), name(name) {

money = money;
posn = 0;
numRes = 0;
numGym = 0;
numTimsCup = 0;
jailTurns = 0;
}

void Player::changeMoney(int money) {
 money += money;
}

string Player::getName() {
   return name;
}

void Player::setPosn(int position) {
   posn = position;
}


void Player::incrNumRes() {
numRes++;
}

void Player::incrNumGym() {
numGym++;
}

int Player::getMoney() {return money;} 

int Player::getNumRes() {
return numRes;
}

int Player::getNumGym() {
return numGym;
}

void Player::move(int amount) {
 posn+= amount;
}
 
int Player::getPosn() {
	//cout << posn << endl;
return posn;
}

void Player::setTimsCup(int num) {
   numTimsCup = num;  

}

int Player::getTimsCup() {
  return numTimsCup;
}

void Player::setJailTurns(int turns) {
 jailTurns = turns;
 }

int Player::getJailTurns() {
return jailTurns;
}

void Player::setName(std::string n) {name=n;}

void Player::setChar(char c) {playerChar=c;}
void Player::setMoney(int val) {money=val;
}
