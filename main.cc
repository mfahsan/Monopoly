// main.cc
#include <iostream>
#include "controller.h"
#include "board.h"
#include <sstream>
//#include "graphicsdisplay.h"


using namespace std;

int error = 0;

int main (int argc, char* argv[]) {
	bool testMode = false;
	bool loaded = false;
	Board* board = new Board;
	Controller* c = new Controller(board, NULL, cin);
	stringstream buffer;
	string input;
	for (int i=1; i<argc; ++i) {
		//cout << argv[i] << endl;
		buffer.str(argv[i]);
		buffer >> input;
		//cout << input << endl;
		if (input=="-load") {
			if (i==argc) {
				error=1;
				cout << "loading failed" << endl;
				return error;
			} else {
				fstream file(argv[i+1], fstream::in);
				error = c->load(file);
				if (!error) return error;
				loaded = true;
			}
		} else if (input=="-testing") {
			testMode = true;
			//cout << testMode << endl;
		}
	}
	//cout << loaded << endl;
	//cout << testMode << endl;
	error = c->play(loaded, testMode);
	delete c;
	delete board;
	return error;
}
