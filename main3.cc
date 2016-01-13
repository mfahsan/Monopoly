#include <iostream>
#include "graphicsdisplay.h"
#include <string>
using namespace std;


int main() {
	Xwindow w;
	int input;
	string sInput;	
	cin >> input;
	int numP = input;
	P *p = new P[numP];
	string *temp = new string[numP];
	for (int i=0;i<numP;++i) {cin >> sInput; temp[i]=sInput; p[i].name=sInput; p[i].number=i;}
	GraphicsDisplay gd = GraphicsDisplay(w, p, numP, temp);
	gd.showView();
	while (cin >> sInput) {
		if (sInput == "move") {
			cin >> sInput;
			string player = sInput;
			cin >> input;
			int move = input;
			for (int i=0; i<numP; ++i) {
				if (player==temp[i]) {
					gd.movePlayerTo(move,p[i]);
				}
			}
		} else if (sInput == "ai") {
			cin >> input;
			gd.addImprovement(input);
		} else if (sInput == "ri") {
			cin >> input;
			gd.removeImprovement(input);
		}
	}
	delete[] temp;
	delete[] p;
}

