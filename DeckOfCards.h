#pragma once
class DeckOfCards
{
private:	

public:
    DeckOfCards(); //default constructor
	~DeckOfCards(); //default destructor
	void reset();
	void shuffle();
	void draw();
	void peek();
	int numOfCards();
	
};
