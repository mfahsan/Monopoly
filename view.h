// View.h
#ifndef VIEW_H
#def VIEW_H

/*******************************************************************
	<<Interface>> View
	
	
********************************************************************/

class View {
	const int numBlocks;
	public:
	View();
	virtual PlayerRemoval(char c);
	virtual notifyMove(Playe&, int);
	virtual notifyMoneyUpdate(Player&, int);
	virtual notifyImprovement(Block&);
};

#endif
