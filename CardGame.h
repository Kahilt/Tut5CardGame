#pragma once
#include <string>

using namespace std;

class Card
{
private:
	int number;
	string colour;

public:
	Card();
	~Card();
	Card(int, string);
	string getColour();
	int getNumber();
	void print();
	
};
