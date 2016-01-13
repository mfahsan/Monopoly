#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include "window.h"
#include <string>

struct P {
	int posn;
	int number;
	std::string name;
	P() {posn=0;}
};
class GraphicsDisplay;
class BlockInfo {
	int x[40];
	int y[40];
	std::string name[40];
    public:
	BlockInfo();
	int X(int blockNum) const;
	int Y(int blockNum) const;
	std::string Name(int blockIndex) const;
};

class GraphicsDisplay{
	Xwindow &w;
	BlockInfo bi;
	P *p;
	int numPlayers;
	std::string *playerChars;
	int properties[22];
	int trackImprovement[22];
	int playerY(int y);
	int playerX(int x, int playerNum);
public:
	GraphicsDisplay(Xwindow &, P*, int numOfPlayers, std::string *allChars);
	~GraphicsDisplay();
	bool removeImprovement(int blockIndex);
	bool addImprovement(int blockIndex);
	void movePlayerTo(int move, P &p);
	//void removePlayer(P &player);
	void showView();
};




#endif
