#include <iostream>
#include "window.h"
#include <string>
#define WS 700

using namespace std;

const int corner = 20, block = 60, botRightCorner = WS-corner-block, numPlayers = 6;
const string playerChars[numPlayers+1] = {"", "G","B","D","P","S","$"};
int properties[22] = {1,3,6,8,9,11,13,14,16,18,19,21,23,24,26,27,29,31,32,34,37,39};
int trackImprovement[22] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

class BlockInfo {
	int x[40];
	int y[40];
	string name[40];
    public:
	BlockInfo() {
		for (int x2=botRightCorner,y2=botRightCorner,i=0; i<40; ++i) {
			x[i]=x2;y[i]=y2;
			if (i<10) x2-=block;
			else if (i==10||i<20) y2-=block;
			else if (i==20||i<30) x2+=block;
			else if (i==30||i<39) y2+=block;
		}
		name[0]="OSAP"; name[1]="AL";
		name[2]="SLC"; name[3]="ML";
		name[4]="TUITION"; name[5]="MKV";
		name[6]="ECH"; name[7]="NEEDLES H.";
		name[8]="PAS"; name[9]="HH";
		name[10]="DC TL"; name[11]="RCH";
		name[12]="PAC"; name[13]="DWE";
		name[14]="CPH"; name[15]="UWP";
		name[16]="LHI"; name[17]="SLC";
		name[18]="BMH"; name[19]="OPT";
		name[20]="GOOSE NEST"; name[21]="EV1";
		name[22]="NEEDLES H."; name[23]="EV2";
		name[24]="EV3"; name[25]="V1";
		name[26]="PHYS"; name[27]="B1";
		name[28]="CIF"; name[29]="B2";
		name[30]="GO TO TL"; name[31]="EIT";
		name[32]="ESC"; name[33]="SLC";
		name[34]="C2"; name[35]="REV";
		name[36]="NEEDLES H."; name[37]="MC";
		name[38]="COOP FEE"; name[39]="DC";
	}
	int X(int blockNum) const {return x[blockNum];}
	int Y(int blockNum) const {return y[blockNum];}
	string Name(int blockIndex) const {return name[blockIndex];}
};

struct P {
	int posn;
	int number;
	string name;
};

int playerY(int y) {return y+30;}
int playerX(int x, int playerNum) {return x+7*playerNum;}

void movePlayerTo(BlockInfo &bi,Xwindow &w, int move, P &player) {
	w.fillRectangle(playerX(bi.X(player.posn),player.number),playerY(bi.Y(player.posn))-10, 7, 13, Xwindow::White);
	player.posn=move;
	w.drawString(playerX(bi.X(player.posn),player.number),playerY(bi.Y(player.posn)), player.name, Xwindow::Black);
}

bool addImprovement(Xwindow& w, BlockInfo &bi, int blockIndex) {
	for (int i=0; i<22; ++i) {
		if (properties[i] == blockIndex) {
			if (trackImprovement[i]<=3) {
				w.fillRectangle(bi.X(blockIndex)+(10*trackImprovement[i])+2,bi.Y(blockIndex)+42,5,5,Xwindow::Red);
			} else if (trackImprovement[i]==4) {
				w.fillRectangle(bi.X(blockIndex)+10*(trackImprovement[i]),bi.Y(blockIndex)+40,10,9,Xwindow::Green);
			} else return false;
			trackImprovement[i]++;
			return true;
		}
	}
	return false;
}

bool removeImprovement(Xwindow& w, BlockInfo &bi, int blockIndex) {
	for (int i=0; i<22; ++i) {
		if (properties[i] == blockIndex) {
			if (trackImprovement[i]>0&&trackImprovement[i]<6) {
				w.fillRectangle(bi.X(blockIndex)+(10*(trackImprovement[i]-1))+1,bi.Y(blockIndex)+40,10,10,Xwindow::White);
			} else return false;
			trackImprovement[i]--;
			return true;
		}
	}
	return false;
}

int main() {
	Xwindow w(WS, WS);
	BlockInfo bi;
	w.drawBigString(300,350,"BB7K",Xwindow::Black);
	w.drawMedString(350,400,"By:",Xwindow::Black);
	w.drawMedString(250,420,"Mubtasim Fuad Ahsan",Xwindow::Black);
	w.drawMedString(290,440,"Arnab Sarker",Xwindow::Black);
	for (int x=corner,y=corner,i=0; i<44; ++i) {
		w.drawRectangle(x,y,block,block);
		if (i <= 10) x+=block;
		else if (i <= 21) y+=block;
		else if (i <= 32) x-=block;
		else if (i <= 43) y-=block;
		if (i==10) x-=block;
		else if (i==21) y-=block;
		else if (i==32) x+=block;
	}
	
	for (int i=0; i<22; ++i) {
		int n = properties[i];
		int color;
		if (i<=1) {color=Xwindow::Brown;}
		else if (i<=4) {color=Xwindow::Cyan;}
		else if (i<=7) {color=Xwindow::Magenta;}
		else if (i<=10) {color=Xwindow::Orange;}
		else if (i<=13) {color=Xwindow::Red;}
		else if (i<=16) {color=Xwindow::Yellow;}
		else if (i<=19) {color=Xwindow::Green;}
		else if (i<=21) {color=Xwindow::Blue;}
		w.fillRectangle(bi.X(n)+1,bi.Y(n)+1,block-2,15,color);
	}

	for (int i=0; i<40; ++i) {
		w.drawString(bi.X(i)+2,bi.Y(i)+12,bi.Name(i));
	}
	P p[numPlayers+1];
	for (int i=1; i<=numPlayers; ++i) {
		p[i].number = i;
		p[i].posn = 0;
		p[i].name = playerChars[i];
		w.drawString(playerX(bi.X(0), i), playerY(bi.Y(0)), p[i].name);
	}
	char c; cin >> c;
}
