// controller.h
#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "boardnotification.h"
#include <iostream>
#include <string>
#include <fstream>

class GraphicsDisplay;
class Board;
class Controller: public BoardNotification {
	std::istream& source;
	Board* board;
	GraphicsDisplay* gd;
	int playerNum;
	std::string *players;
	std::string *playerChars;
	public:
	int play(bool, bool);
	int init(int);
	int load(std::fstream& file);
	void playerRemoval(char c);
	void notifyMoveTo(Player&, int);
	void notifyMoneyUpdate(Player&, int);
	Controller(Board* b, GraphicsDisplay* gd, std::istream&);
	~Controller();
};

#endif
