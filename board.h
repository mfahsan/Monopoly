#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include "academic.h"
#include "slc.h"
#include "coopfee.h"
#include "needleshall.h"
#include "gym.h"
#include "tuition.h"
#include "residence.h"
#include "boardnotification.h"
#include "collectosap.h"


class Board {

int totalTimsCup;
BoardNotification *boardnotify;
Player **players;
Block **blocks;

int numPlayers;
bool checkMonopoly(Player &p, std::string department); 

void payFee(Player &p, Ownable &block);

public:

void addBoardNotifier(BoardNotification *bn);

std::string getOwnableName(int index);

void init(int numPlayers);

void notifyBankrupt(Player &p);

bool inJail(Player&);

std::string getOwner(int);

int getImprovements(int);

bool notifyMove(Player &p, int move);

void notifyBuyProperty(Player &p, int index);

void putInTimsLine(char playerChar);

void putInTimsLine(char playerChar, int);

void loadOwnable(int blockIndex, Player* owner, int improvements);

void loadPlayer(std::string playerName, char playerChar, int playerTimsCup, int playerMoney, int playerPosn); // loads player with name char number of tims cup player money and posn

int getOwnableIndex(std::string blockName); // returns the index of the ownable block

void loadPlayer(std::string playerName, char playerChar, int playerTimsCup, int playerMoney, int playerPosn, int i);

bool transferBlock(Player& from, Player& to, int index);

void notifyTrade(int aindex, int bindex, Player &a, Player &b); // tells the board about the trade between player a and player b with block a and block b 

void notifyTrade(Player &a, Player &b, int amount, int index); // tells the board about the trade between player a and player b with the amount and block

bool notifyBuyImprovement(Player &p, Academic &a); // tells the board the academic building that player p buys improvement of, and number of improvements

void mortgageProperty(int index);

void unMortgageProperty(int index);

bool giveTimsCup (Player &player);

Player* getPlayer(std::string playerName); // gets the player with the name playerName 

Player* getPlayer(char playerChar); // gets the player with the name playerName 

~Board();
} ;

#endif
