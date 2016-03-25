#include "DeckOfCards.h"
#include "CardGame.h"
#include <cstdlib>
#include <iostream>
#include <ctime>


using namespace std;

Card *ptrArray[20];		//creates array of pointers 
Card cardArray[20] = { Card(1, "Red"), Card(2, "Red"), Card(3, "Red"), Card(4, "Red"), Card(5, "Red"), Card(6, "Red"), Card(7, "Red"), Card(8, "Red"), Card(9, "Red"), Card(10, "Red"), Card(1, "Black"), Card(2, "Black"), Card(3, "Black"), Card(4, "Black"), Card(5, "Black"), Card(6, "Black"), Card(7, "Black"), Card(8, "Black"), Card(9, "Black"), Card(10, "Black"), }; //creates card objects

DeckOfCards::DeckOfCards()
{
	int i;
	for (i = 0; i < 20; i++)//assigns default addresses to the pointers
	{
		ptrArray[i] = &cardArray[i];
	}
}

DeckOfCards::~DeckOfCards()
{

}

void DeckOfCards::reset()
{
	DeckOfCards();		//calls default constructor to reset the pack
}

void DeckOfCards::shuffle()
{
	Card *tmpPtr;
	srand(time(NULL));
	for (int i = 0; i < 50; i++)
	{
		int num1 = rand() % 20;		            //generates random number
		int num2 = rand() % 20;
		tmpPtr = ptrArray[num1];		          //swaps card order
		ptrArray[num1] = ptrArray[num2];
		ptrArray[num2] = tmpPtr;
	}
}

void DeckOfCards::draw()
{
	bool noCards = true;
	for (int i = 0; i < 20; i++)
	{
		if (ptrArray[i] != NULL)		//checks if current pointer is drawn already. Skips if it has been drawn previously
		{
			cout << "Card drawn is : ";
			ptrArray[i]->print();
			ptrArray[i] = NULL;			//deletes address stored in this pointer. This effectively removes a cardfrom the deck.
			noCards = false;
			break;
		}
	}

	if (noCards == true)
		cout << "No cards left in deck" << endl;
}


void DeckOfCards::peek()
{
	bool noCards = true;
	for (int i = 0; i < 20; i++)
	{
		if (ptrArray[i] != NULL)		//checks if current pointer is drawn already. Skips if it has been drawn previously
		{
			cout << "Next card is : ";
			ptrArray[i]->print();
			noCards = false;
			break;
		}
	}
	if (noCards == true)
		cout << "No cards left in deck" << endl;
}

int DeckOfCards::numOfCards()
{
	int count = 0;
	for (int i = 0; i < 20; i++)
	{
		if (ptrArray[i] != NULL)	//checks for pointers that have not been drawn. Increments counter if true
		{
			count++;
		}
	}
	return count;
}

