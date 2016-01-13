#include <vector>
#include "board.h"
using namespace std;


void Board::init(int numPlayers) {

players = new Player*[numPlayers];

blocks = new Block*[40];

numPlayers = numPlayers;
totalTimsCup = 4;

blocks[0] = new CollectOSAP; 

blocks[1] = new Academic("AL", "Arts1", 40, 50, 2, 10, 30 , 90, 160, 250);

blocks[2] = new SLC(*this);

blocks[3] = new Academic("ML", "Arts1", 60, 50, 4, 20, 60 , 180, 320, 450);

blocks[4] = new Tuition();

blocks[5] = new Residence (200, "MKV");

blocks[6] = new Academic("ECH", "Arts2", 100, 50, 6, 30, 90 , 270, 400, 550);

blocks[7] = new NeedlesHall(*this);

blocks[8] = new Academic("PAS", "Arts2", 100, 50, 6, 30, 90 , 270, 400, 550);

blocks[9] = new Academic("HH", "Arts2", 120, 50, 8, 40, 100 , 300, 450, 600);

blocks[11] = new Academic("RCH", "Eng", 140, 100, 10, 50, 150 , 450, 625, 750);

blocks[12] = new Gym(150, "PAC");

blocks[13] = new Academic("DWE", "Eng", 140, 100, 10, 50, 150 , 450, 625, 750);

blocks[14] = new Academic ("CPH", "Eng", 160, 100, 12, 60, 180 , 500, 700, 900);

blocks[16] = new Academic("LHI", "Health", 180, 100, 14, 70, 200 , 550, 750, 950);

blocks[15] = new SLC(*this);

blocks[18] = new Academic("BMH", "Health", 200, 100, 14, 70, 200 , 550, 750, 950);

blocks[19] = new Academic("OPT", "Health", 200, 100, 16, 80, 220 , 600, 800, 1000);

blocks[21] = new Academic("EV1", "Env", 220, 150, 18, 90, 250 , 700, 875, 1050);

blocks[22] = new NeedlesHall(*this);

blocks[23] = new Academic("EV2", "Env", 240, 150, 20, 100, 300 , 700, 875, 1050);

blocks[24] = new Academic("EV3", "Env", 240, 150, 20, 100, 300 , 750, 925, 1100);

blocks[25] = new Residence(200, "v1");

blocks[26] = new Academic("PHYS", "Sci1", 260, 150, 22, 110, 330 , 800, 975, 1150);

blocks[27] = new Academic("B1", "Sci1", 260, 150, 22, 110, 330 , 800, 975, 1150);

blocks[28] = new Gym(150, "CIF"); 

blocks[29] = new Academic("B2", "Sci1", 280, 150, 24, 120, 360 , 850, 1020, 1200);

blocks[31] = new Academic("EIT", "Arts1", 40, 50, 2, 10, 30 , 90, 160, 250);

blocks[32] = new Academic("ESC", "Arts1", 40, 50, 2, 10, 30 , 90, 160, 250);

blocks[33] = new SLC(*this);

blocks[34] = new Academic("C2", "Arts1", 40, 50, 2, 10, 30 , 90, 160, 250);

blocks[35] = new Residence(200, "REV");

blocks[36]  = new NeedlesHall(*this);

blocks[37] = new Academic("MC", "Math", 40, 50, 2, 10, 30 , 90, 160, 250);

blocks[38] = new CoopFee();

blocks[39] = new Academic("DC", "Math", 400, 200, 50, 200, 600 , 1400, 1700, 2000);

}

int Board::getOwnableIndex(string blockName) {
	if (blockName == "AL") return 1;
	else if (blockName == "ML") return 3;
	else if (blockName == "MKV") return 5;
	else if (blockName == "ECH") return 6;
	else if (blockName == "PAS") return 8;
	else if (blockName == "HH") return 9;
	else if (blockName == "RCH") return 11;
	else if (blockName == "PAC") return 12;
	else if (blockName == "DWE") return 13;
	else if (blockName == "CPH") return 14;
	else if (blockName == "UWP") return 15;
	else if (blockName == "LHI") return 16;
	else if (blockName == "BMH") return 18;
	else if (blockName == "OPT") return 19;
	else if (blockName == "EV1") return 21;
	else if (blockName == "EV2") return 23;
	else if (blockName == "EV3") return 24;
	else if (blockName == "V1") return 25;
	else if (blockName == "PHYS") return 26;
	else if (blockName == "B1") return 27;
	else if (blockName == "CIF") return 28;
	else if (blockName == "B2") return 29;
	else if (blockName == "EIT") return 31;
	else if (blockName == "ESC") return 32;
	else if (blockName == "C2") return 34;
	else if (blockName == "REV") return 35;
	else if (blockName == "MC") return 37;
	else if (blockName == "DC") return 39;
	else return -1;
}

void Board::notifyBankrupt(Player &p) {
  numPlayers--;
 
  Player **newplayers = new Player *[numPlayers];
   int i = 0; 
   int k = 0;
  while (i < numPlayers) {
   if ((players[i]) == &p) {
    i += 1;
   }
    players[i] = newplayers[k];
    i++;
    k++;
   }

  delete &p;
  delete[] players;
  players = newplayers; 
}

void Board::notifyMove(Player &p, int move) { // more to be done 
  int position = p.getPosn();
  position += move;
  p.setPosn(position);

}

void Board::notifyBuyProperty(Player &p, int index) {
 Block *bp = blocks[index];
 Ownable *block = dynamic_cast<Ownable *> (bp);
 if (block != NULL) { 
 block->setOwner(&p);
} 
}


void Board::putInTimsLine(char playerChar) {
   
     for (int i = 0; i < numPlayers; i++) {
    
     if ((*players[i]).getChar == playerChar) {
   	(*players[i]).setPosn(10);
     }
   }

 }

 // initialize jailTurns to 0 or however you implemented jail (tims line)

void Board::loadOwnable(int blockIndex, Player& owner, int improvements) {
 Block *bp = blocks[blockIndex];
 Academic *block = dynamic_cast <Academic *> (bp);
 if (block != NULL) {
 (*block).setOwner(&owner);

 for (int i = improvements; i > 0; i--) {
    (*block).incrImprovementIndex();
   }
 }
}

 void Board::loadPlayer(string playerName, char playerChar, int playerTimsCup, int playerMoney, int playerPosn)  // loads player with name char number of tims cup player money and posn
 {

  for (int i = 0; i < numPlayers; i++) {
   if (!players[i]) {
   players[i] = new Player(playerName, playerChar, playerMoney);
   }
  }
      
 }


Player& Board::getPlayer(string playerName) {
for (int i = 0; i < numPlayers; i++ ) {
 
 if (players[i]->getName() == playerName) {
   return *players[i];
    }
 } 


}
 

bool Board::transferBlock(Player& from, Player& to, int index) {
      Block *bp = blocks[index];
      Ownable *block = dynamic_cast<Ownable *> (bp);
  
      if (block != NULL) {
           if ((*block).getOwner() == &from)
	       	(*block).setOwner(&to);
	    return true;
	    }
        return false;

}

void Board::notifyTrade(int aindex, int bindex, Player &a, Player &b) {
   transferBlock(a ,b, aindex); 
   transferBlock(b, a, bindex);

} // tells the board about the trade between player a and player b with block a and block b 

void Board::notifyTrade(Player &a, Player &b, int amount, int index) {

a.changeMoney(-amount);
transferBlock(b, a, index);
b.changeMoney(amount);


}// tells the board about the trade between player a and player b with the amount and block

bool Board::checkMonopoly(Player &p, string department) {
   for(int index=0; index < 40; index++) { 
     Block *bp = blocks[index];
     Academic *block = dynamic_cast<Academic *> (bp);
       if (block != NULL) {	
        if ((*block).getDepartment() == department) {
           	if ((*block).getOwner() != &p) {
              return false;
               }
	 }
     }
 }
    return true; 
} 

void Board::notifyBuyImprovement(Player &p, Academic &a, int improve) {
 int cost = a.getImprovementCost();
  	p.changeMoney(-cost); 
  	a.incrImprovementIndex();
  	}
  

void Board::mortgageProperty(int index) {
   Block *bp = blocks[index];
   Ownable *block = dynamic_cast<Ownable *> (bp); 
 if (block != NULL) {
  (*block).setMortgaged(true);
  } 

}

void Board::unMortgageProperty(int index) {
   Block *bp = blocks[index];
   Ownable *block = dynamic_cast<Ownable *> (bp);    
   if (block != NULL) {
  (*block).setMortgaged(false);
   }
}

bool Board::giveTimsCup (Player &player) {
  if (totalTimsCup == 0) return false;
  int cups = p.getTimsCup();
  cups++;
  p.setTimsCup(cups);
  totalTimsCup--;
  return true;
}




