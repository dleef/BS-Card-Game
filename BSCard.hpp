#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;	
class Card {

	public:
		Card();
		Card(string type, int number);
		string type;
		int number;
		string asciiPrint;

};
	
#endif
