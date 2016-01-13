#include "graphicsdisplay.h"
#define WS 700
using namespace std;
#define corner 20
#define block 60
#define botRightCorner 620
GraphicsDisplay::GraphicsDisplay(Xwindow &w, P *p, int numOfPlayers, string *allChars):numPlayers(numOfPlayers),playerChars(allChars),w(w),p(p) {
	for(int i=0; i<22; ++i) trackImprovement[i]=0;
	properties[0] = 1;
	properties[1] = 3;
	properties[2] = 6;
	properties[3] = 8;
	properties[4] = 9;
	properties[5] = 11;
	properties[6] = 13;
	properties[7] = 14;
	properties[8] = 16;
	properties[9] = 18;
	properties[10] = 19;
	properties[11] = 21;
	properties[12] = 23;
	properties[13] = 24;
	properties[14] = 26;
	properties[15] = 27;
	properties[16] = 29;
	properties[17] = 31;
	properties[18] = 32;
	properties[19] = 34;
	properties[20] = 37;
	properties[21] = 39;
	playerChars = new string[numOfPlayers];
	for (int i=0;i<numOfPlayers;++i) playerChars[i]=allChars[i];
}
GraphicsDisplay::~GraphicsDisplay() {
	delete[] playerChars;
}
BlockInfo::BlockInfo() {
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
int BlockInfo::X(int blockNum) const {return x[blockNum];}
int BlockInfo::Y(int blockNum) const {return y[blockNum];}
string BlockInfo::Name(int blockIndex) const {return name[blockIndex];}
int GraphicsDisplay::playerY(int y) {return y+30;}
int GraphicsDisplay::playerX(int x, int playerNum) {return x+7*playerNum;}
bool GraphicsDisplay::removeImprovement(int blockIndex) {
	for (int i=0; i<22; ++i) {
		if (properties[i] == blockIndex) {
			if (trackImprovement[i]>0&&trackImprovement[i]<6) {
				w.fillRectangle(bi.X(blockIndex)+(10*(trackImprovement[i]-1))+2,bi.Y(blockIndex)+40,10,10,Xwindow::White);
			} else return false;
			trackImprovement[i]--;
			return true;
		}
	}
	return false;
}

bool GraphicsDisplay::addImprovement(int blockIndex) {
	for (int i=0; i<22; ++i) {
		if (properties[i] == blockIndex) {
			if (trackImprovement[i]<=3) {
				w.fillRectangle(bi.X(blockIndex)+(10*trackImprovement[i])+3,bi.Y(blockIndex)+42,5,5,Xwindow::Red);
			} else if (trackImprovement[i]==4) {
				w.fillRectangle(bi.X(blockIndex)+10*(trackImprovement[i]),bi.Y(blockIndex)+40,10,9,Xwindow::Green);
			} else return false;
			trackImprovement[i]++;
			return true;
		}
	}
	return false;
}
void GraphicsDisplay::movePlayerTo(int move, P &player) {
	w.fillRectangle(playerX(bi.X(player.posn),player.number)+2,playerY(bi.Y(player.posn))-10, 7, 13, Xwindow::White);
	player.posn=move;
	w.drawString(playerX(bi.X(player.posn),player.number)+2,playerY(bi.Y(player.posn)), player.name, Xwindow::Black);
}
void GraphicsDisplay::showView() {
	w.load();
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
	for (int i=0; i<numPlayers; ++i) {
		p[i].number = i;
		p[i].name = playerChars[i];
		w.drawString(playerX(bi.X(p[i].posn), i)+2, playerY(bi.Y(p[i].posn)), p[i].name);
	}
}
