// controller.cc
//cout >> "TEST" >> endl;
#include "controller.h"
#include "player.h"
#include "board.h"
#include "graphicsdisplay.h"
#include <random>
#include <string>
#include <sstream>
#include <fstream>
#define OWNABLE_COUNT 28
using namespace std;

Controller::Controller(Board* b, GraphicsDisplay* gd, istream& s):board(b),gd(gd),source(s) {}
Controller::~Controller() {
	delete board;
	delete gd;
	delete[] players;
	delete[] playerChars;
}

int Controller::init(int numPlayers) {
	board->init(numPlayers);
	board->addBoardNotifier(this);
	return 0;
}

int Controller::play(bool loaded, bool test) {
	//cout << "TEST" << endl;
	string input;
	start:
	if (!loaded) {
		// initial load
		string playerName;
		char playerChar;
		bool charAvail[8];
		for (int i=0; i<8; ++i) charAvail[i] = true;
		source >> playerNum;
		init(playerNum);
		//cout << playerNum << endl;
		//cout << "TEST" << endl;
		players = new string[playerNum];
		playerChars = new string[playerNum];
		for (int i=0; i<playerNum; ++i) {
			//cout << i << endl;
			if (!(source >> playerName)) return 9;
			do {
				if (!(source >> playerChar)) return 9;
			} while (isspace(playerChar));
			if (playerChar == 'G' && charAvail[0]) {
				playerChars[i]="G";
				charAvail[0] = false;
				//cout << "TEST" << endl;
			} else if (playerChar == 'B' && charAvail[1]) {
				playerChars[i]="B";
				charAvail[1] = false;
				//cout << "TEST" << endl;
			} else if (playerChar == 'D' && charAvail[2]) {
				playerChars[i]="D";
				charAvail[2] = false;
				//cout << "TEST" << endl;
			} else if (playerChar == 'P' && charAvail[3]) {
				playerChars[i]="P";
				charAvail[3] = false;
			} else if (playerChar == 'S' && charAvail[4]) {
				playerChars[i]="S";
				charAvail[4] = false;
			} else if (playerChar == '$' && charAvail[5]) {
				playerChars[i]="$";
				charAvail[5] = false;
			} else if (playerChar == 'L' && charAvail[6]) {
				playerChars[i]="L";
				charAvail[6] = false;
				//cout << "TEST" << endl;
			} else if (playerChar == 'T' && charAvail[7]) {
				playerChars[i]="T";
				charAvail[7] = false;
			} else {
				cout << "a player's character is not valid. try again." << endl;
				goto start;
			}
			//cout << playerChar << endl;
			//cout << i << endl;
			//cout << playerName << endl;
			//cout << "TEST2" << endl;
			players[i]=playerName;
			board->loadPlayer(playerName, playerChar, 0, 1500, 0, i);

		}

	}
	//cout << "TEST3" << endl;
	// play
	Xwindow *window = new Xwindow;
	P *p = new P[playerNum];
	//cout << "TEST4" << endl;
	for (int i=0; i<playerNum; ++i) {
		p[i].number = i;
		p[i].name = playerChars[i];
		//cout << "TEST" << i << endl;
		p[i].posn = 0;
	}
	//cout << "TEST5" << endl;
	GraphicsDisplay *temp = new GraphicsDisplay(*window,p,playerNum,playerChars);
	gd = temp;
	//cout << "TEST6" << endl;
	gd->showView();
	for (int i=0; i<40; ++i) {
		//cout << "IMPROVEMENTS FOR " << i << ": " << board->getImprovements(i) << endl;
		for (int n=0; n<board->getImprovements(i);++n) gd->addImprovement(i);
	}

	default_random_engine gen;
	uniform_int_distribution<int> dist(1,6);
	int die1, die2;
	bool gameCont = true;
	
	for (int i=0, turn=0; source >> input && gameCont; ++i, turn=i%playerNum) {
		Player *plyr = board->getPlayer(players[turn]);
			if (input == "roll") {
				
				//cout << "TEST7" << endl;
				int totDie;
				if (test) source >> die1 >> die2;
				else {die1 = dist(gen); die2 = dist(gen);}
				totDie = die1+die2;
				//cout << "TEST8" << endl;
				//cout << totDie << endl;
				//cout << "TEST8" << endl;
				//cout << plyr->getChar() << endl;
				//cout << plyr->getName() << endl;
				//cout << "TEST8" << endl;
				board->notifyMove(*plyr, totDie);
				//cout << "TEST9" << endl;
				gd->movePlayerTo(plyr->getPosn(), p[turn]);
				//cout << "TEST10" << endl;
			}
			else if (input == "assets") {

			} else if (input == "buy") {
				board->notifyBuyProperty(*plyr,plyr->getPosn());
				turn--;
			}else if (input == "save") {
				source >> input;
				//cout << "TEST12" << endl;
				ofstream fileBuff;
				//cout << "TEST12" << endl;
				fileBuff.open(input.c_str());
				//cout << "TEST12" << endl;
				fileBuff << playerNum << endl;
				//cout << "TEST12" << endl;
				for (int i=0; i<playerNum; ++i) {
					Player *p = board->getPlayer(players[i]);
					fileBuff << players[i] << " " << p->getChar() << " "
					 << p->getTimsCup() << " " << p->getMoney() << " " << p->getPosn();
					if (p->getPosn() == 10) {
						if (board->inJail(*p)) fileBuff << board->inJail(*p) << " " << p->getJailTurns() << endl;
						else fileBuff << board->inJail(*p) << endl;
					} else fileBuff << endl;
				}
				//cout << "TEST12" << endl;
				for (int i=0; i<40; ++i) {
					string temp2 = board->getOwnableName(i);
					if (temp2 != "") {
						if (board->getOwner(board->getOwnableIndex(temp2)) != "") fileBuff << temp2 << " BANK " << board->getImprovements(board->getOwnableIndex(temp2)) << endl;
						else fileBuff << temp2 << " " << board->getOwner(board->getOwnableIndex(temp2)) << " " << board->getImprovements(board->getOwnableIndex(temp2)) << endl;
					}
				}
				//cout << "TEST12" << endl;
				fileBuff.close();
			}
			/*default: {
				
			}*/

			cout << "--------------------------------------------------------" << endl;
			cout << "- GAME SUMMARY -----------------------------------------" << endl;
			for (int i=0; i<playerNum; ++i) {
				cout << "-  " << players[i] << " (" << playerChars[i] << ") " << "$" << 
				(board->getPlayer(players[i]))->getMoney() << " Res:" << (board->getPlayer(players[i]))->getNumRes() <<
				" Gyms:" << (board->getPlayer(players[i]))->getNumGym() << " Pos:" << (board->getPlayer(players[i]))->getPosn() << "     -" << endl;
			}
			cout << "--------------------------------------------------------" << endl;
		
	}

	delete temp;
	delete gd;
	delete[] p;
	return 0;
}


int Controller::load(fstream& file) {
	//cout << "TEST12" << endl;
	string playerName, input;
	char playerChar;
	int playerTimsCup, playerPosn, playerMoney, imprNum;
	stringstream buffer;
	//cout << "TEST12" << endl;
	if (!(file >> playerNum)) return 2;
	init(playerNum);
	players = new string[playerNum];
	playerChars = new string[playerNum];
	for (int i=0; i<playerNum; ++i) {
		if (getline(file, input)) return 3;
		buffer.str(input);
		if (!(buffer >> playerName >> playerChar >> playerTimsCup >> playerMoney >> playerPosn)) return 4;
		board->loadPlayer(playerName, playerChar, playerTimsCup, playerMoney, playerPosn, i);
		players[i]=playerName;
		string temp(1, playerChar);
		playerChars[i]=temp;
		cout << temp << endl;
		if (playerPosn == 10) {
			int jail, jailTurns;
			if (!(buffer >> jail)) return 7;
			if (jail) {
				if (!(buffer >> jailTurns)) return 8;
				board->putInTimsLine(playerChar, jailTurns);
			}
		}
	}
	//cout << "TEST12" << endl;
	for (int i=0; i<OWNABLE_COUNT;++i) {
		if (!(file >> input >> playerName >> imprNum)) return 5;
		int index = board->getOwnableIndex(input);
		if (index==-1) return 6;
		if (playerName == "BANK") board->loadOwnable(index, NULL, imprNum);
		else board->loadOwnable(index, board->getPlayer(playerName), imprNum);
	}
	//cout << "TEST12" << endl;
	return 0;
}

void Controller::playerRemoval(char c) {}
void Controller::notifyMoveTo(Player& p, int move) {}
void Controller::notifyMoneyUpdate(Player& p, int money) {}
