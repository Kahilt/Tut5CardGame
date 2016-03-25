#include "CardGame.h"
#include <iostream>


Card::Card(int num, string col)
{
	number = num;
	colour = col;
}

string Card::getColour() //for each suit
{
	return colour;
}

int Card::getNumber() //for each number
{
	return number;
}

void Card::print() //output
{
	cout << colour << " " << number << endl;
}


Card::~Card() // default destructor
{
}