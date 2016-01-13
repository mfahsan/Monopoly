#include <vector>
#include "board.h"
#include <iostream>
using namespace std;


void Board::init(int nPlayers) {
numPlayers = nPlayers;
players = new Player*[numPlayers];

for (int i=0; i<numPlayers; ++i) {
  Player *p = new Player("",0,1500);
  players[i] = p;
}

blocks = new Block*[40];


totalTimsCup = 4;

blocks[0] = new CollectOSAP; 

blocks[1] = new Academic("AL", "Arts1", 40, 50, 2, 10, 30 , 90, 160, 250);

blocks[2] = new SLC(this);

blocks[3] = new Academic("ML", "Arts1", 60, 50, 4, 20, 60 , 180, 320, 450);

blocks[4] = new Tuition();

blocks[5] = new Residence (200, "MKV");

blocks[6] = new Academic("ECH", "Arts2", 100, 50, 6, 30, 90 , 270, 400, 550);

blocks[7] = new NeedlesHall(this);

blocks[8] = new Academic("PAS", "Arts2", 100, 50, 6, 30, 90 , 270, 400, 550);

blocks[9] = new Academic("HH", "Arts2", 120, 50, 8, 40, 100 , 300, 450, 600);

blocks[11] = new Academic("RCH", "Eng", 140, 100, 10, 50, 150 , 450, 625, 750);

blocks[12] = new Gym(150, "PAC");

blocks[13] = new Academic("DWE", "Eng", 140, 100, 10, 50, 150 , 450, 625, 750);

blocks[14] = new Academic ("CPH", "Eng", 160, 100, 12, 60, 180 , 500, 700, 900);

blocks[16] = new Academic("LHI", "Health", 180, 100, 14, 70, 200 , 550, 750, 950);

blocks[15] = new SLC(this);

blocks[18] = new Academic("BMH", "Health", 200, 100, 14, 70, 200 , 550, 750, 950);

blocks[19] = new Academic("OPT", "Health", 200, 100, 16, 80, 220 , 600, 800, 1000);

blocks[21] = new Academic("EV1", "Env", 220, 150, 18, 90, 250 , 700, 875, 1050);

blocks[22] = new NeedlesHall(this);

blocks[23] = new Academic("EV2", "Env", 240, 150, 20, 100, 300 , 700, 875, 1050);

blocks[24] = new Academic("EV3", "Env", 240, 150, 20, 100, 300 , 750, 925, 1100);

blocks[25] = new Residence(200, "v1");

blocks[26] = new Academic("PHYS", "Sci1", 260, 150, 22, 110, 330 , 800, 975, 1150);

blocks[27] = new Academic("B1", "Sci1", 260, 150, 22, 110, 330 , 800, 975, 1150);

blocks[28] = new Gym(150, "CIF"); 

blocks[29] = new Academic("B2", "Sci1", 280, 150, 24, 120, 360 , 850, 1020, 1200);

blocks[31] = new Academic("EIT", "Arts1", 40, 50, 2, 10, 30 , 90, 160, 250);

blocks[32] = new Academic("ESC", "Arts1", 40, 50, 2, 10, 30 , 90, 160, 250);

blocks[33] = new SLC(this);

blocks[34] = new Academic("C2", "Arts1", 40, 50, 2, 10, 30 , 90, 160, 250);

blocks[35] = new Residence(200, "REV");

blocks[36]  = new NeedlesHall(this);

blocks[37] = new Academic("MC", "Math", 40, 50, 2, 10, 30 , 90, 160, 250);

blocks[38] = new CoopFee();

blocks[39] = new Academic("DC", "Math", 400, 200, 50, 200, 600 , 1400, 1700, 2000);

}

string Board::getOwner(int index) {
  Block *bp = blocks[index];
  Ownable *block = dynamic_cast<Ownable *> (bp);
  if (block != NULL) {
    Player *owner = (*block).getOwner();
  
  return (*owner).getName();
 }
 return "";
}

int Board::getImprovements(int index) {
  Block *bp = blocks[index];
  Academic *block = dynamic_cast<Academic *> (bp);

  if (block != NULL) {
  return (*block).getImprovementIndex();
  }
  return 0;
}

bool Board::inJail(Player& player) {
  if (player.getJailTurns() > 0) return true;
  else return false;
}

string Board::getOwnableName(int index) {
  Block *bp = blocks[index];
  Ownable *block = dynamic_cast<Ownable *> (bp);

  if (block != NULL) {
    return (*block).getName();
  }
  return "";
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

void Board::payFee(Player &p, Ownable &block) {
 int fee= block.getFee();
 p.changeMoney(-fee);
 }

 void Board::putInTimsLine(char playerChar, int jailT) {
  Player *p = getPlayer(playerChar);
  p->setPosn(10);
  p->setJailTurns(jailT);
 }

 void Board::putInTimsLine(char playerChar) {
  Player *p = getPlayer(playerChar);
  if (inJail(*p)) {return;}
  else {p->setPosn(10); p->setJailTurns(3);}
 }


bool Board::notifyMove(Player &p, int move) { // more to be done
  int newPosn = (p.getPosn()+move)%40;
  if (newPosn<0) {
    newPosn+=40;
  }
    if (inJail(p)) {
      p.setJailTurns(p.getJailTurns()-1);
      if (p.getJailTurns()==0) {
        if (p.getTimsCup() > 0) p.setTimsCup(p.getTimsCup()-1);
        else p.changeMoney(-50);
        p.setPosn(newPosn);
      }
      return true;
    } else if (p.getPosn()+move>=40) {
      p.changeMoney(200);
      p.setPosn(newPosn);
    } else {
      p.setPosn(newPosn);
      if (p.getPosn()==30) {putInTimsLine(p.getChar()); p.setPosn(10);}
      else {
        Block *currentBlock = blocks[p.getPosn()];
        Academic *own1 = dynamic_cast<Academic*>(currentBlock);
        Gym *own2 = dynamic_cast<Gym*>(currentBlock);
        Residence *own3 = dynamic_cast<Residence*>(currentBlock);
        SLC *slc = dynamic_cast<SLC*>(currentBlock);
        NeedlesHall *nh = dynamic_cast<NeedlesHall*>(currentBlock);
        CoopFee *cf = dynamic_cast<CoopFee*>(currentBlock);
        Tuition *t = dynamic_cast<Tuition*>(currentBlock);
        if (own1) {
          p.changeMoney(-(own1->getFee()));
          (own1->getOwner())->changeMoney(own1->getFee());
        } else if (own2) {
          p.changeMoney(-(own2->getFee(move)));
          (own2->getOwner())->changeMoney(own2->getFee(move));
        } else if (own3) {
          p.changeMoney(-(own3->getFee()));
          (own3->getOwner())->changeMoney(own3->getFee());
        } else if (slc) {
          slc->performAction(p);
          boardnotify->notifyMoveTo(p, p.getPosn());
        } else if (nh) {
          nh->performAction(p);
        } else if (cf) {
          cf->applyTuition(p);
        } else if (t) {
          t->applyTuition(p, 0);
        }
      }
    }
}

void Board::addBoardNotifier(BoardNotification *bn) {
  boardnotify = bn;
}

void Board::notifyBuyProperty(Player &p, int index) {
 Block *bp = blocks[index];
 Ownable *block = dynamic_cast<Ownable *> (bp);
 if (block != NULL) { 
  if (p.getMoney()>=block->getPurchaseCost()) {
    block->setOwner(&p);
    p.changeMoney(-(block->getPurchaseCost()));
    Gym *block1 = dynamic_cast<Gym *> (bp);
    Residence *block2 = dynamic_cast<Residence *> (bp);
    if (block1) {
      p.incrNumGym();
    } else if (block2) {
      p.incrNumRes();
    }
  } 
} 
}

Player* Board::getPlayer(char playerChar) {
    if (players) {
        //cout << "PASSED THIS U SHIT" << endl;
        //cout << numPlayers << endl;
        for (int i=0; i<numPlayers; ++i) {
          //cout << i << endl;
          Player *temp = players[i];
          //cout << temp->getName() << endl;
          char c = temp->getChar();
          //cout << c << endl;
          if (c == playerChar) {
              return temp;
          }
        }
        //cout << "END" << endl;
        return NULL;
    } else {return NULL;}
}

Player* Board::getPlayer(string playerName) {
  if (players) {
        //cout << "PASSED THIS U SHIT" << endl;
        //cout << numPlayers << endl;
        for (int i=0; i<numPlayers; ++i) {
          //cout << i << endl;
          Player *temp = players[i];
          //cout << temp->getChar() << endl;
          string c = temp->getName();
          //cout << c << endl;
          if (c == playerName) {
              return temp;
          }
        }
        //cout << "END" << endl;
        return NULL;
    } else {return NULL;}
}

 // initialize jailTurns to 0 or however you implemented jail (tims line)

void Board::loadOwnable(int blockIndex, Player* owner, int improvements) {
 Block *bp = blocks[blockIndex];
 Academic *block = dynamic_cast <Academic *> (bp);
 Ownable *block2 = dynamic_cast <Ownable *> (bp);
 if (block) {
  block->setOwner(owner);
  block->setImprovement(improvements);
 } else if (block2) {
  block->setOwner(owner);
 }
}

 void Board::loadPlayer(string playerName, char playerChar, int playerTimsCup, int playerMoney, int playerPosn)  // loads player with name char number of tims cup player money and posn
 {
    for (int i=0; i<numPlayers; ++i) {
      if (players[i]->getName()=="") {
        players[i]->setName(playerName);
        players[i]->setChar(playerChar);
        players[i]->setTimsCup(playerTimsCup);
        players[i]->setPosn(playerPosn);
        players[i]->setMoney(playerMoney);
      }

    }
 }

 void Board::loadPlayer(string playerName, char playerChar, int playerTimsCup, int playerMoney, int playerPosn, int i)  // loads player with name char number of tims cup player money and posn
 {
    
        players[i]->setName(playerName);
        players[i]->setChar(playerChar);
        players[i]->setTimsCup(playerTimsCup);
        players[i]->setPosn(playerPosn);
        players[i]->setMoney(playerMoney);

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

bool Board::notifyBuyImprovement(Player &p, Academic &a) {
 string currDepartment = a.getDepartment();
  
  if (checkMonopoly(p, currDepartment)) {
   int cost = a.getImprovementCost();
  	p.changeMoney(-cost); 
  	a.incrImprovementIndex();
  	}
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

bool Board::giveTimsCup (Player &p) {
  if (totalTimsCup == 0) return false;
  int cups = p.getTimsCup();
  cups++;
  p.setTimsCup(cups);
  totalTimsCup--;
  return true;
}


Board::~Board() {
for (int i = 0; i < 40; i++) {
delete blocks[i];
}
delete[] blocks;

for (int i = 0; i < numPlayers; i++) {
 delete players[i];
}
delete[] players;

}
