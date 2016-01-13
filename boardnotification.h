// .h
#ifndef BOARDNOTIFICATION_H
#define BOARDNOTIFICATION_H

/*******************************************************************
	<<Interface>> BoardNotification
	
	
********************************************************************/
class Player;

class BoardNotification {
	public:
	virtual ~BoardNotification();
	virtual void playerRemoval(char c);
	virtual void notifyMoveTo(Player&, int);
	virtual void notifyMoneyUpdate(Player&, int);
	
};

#endif
