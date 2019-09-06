#include <iostream>
#include <string>
#include "BSFunctions.hpp"
using namespace std;

int main() {
	
	cout << "Welcome to the card game BS! To start you must enter how many people will be playing." << endl;
	int numPlayers = getNumPlayers();
	Deck deck(numPlayers);
	deck.currentCard = 1;
	deck.pastCard = 13;
	deck.initDeck();
	deck.initAsciiPrints();	
	deck.initPlayers();
	shuffleDeck(&deck);
	parseCards(&deck);
	int startingPlayer = findWhoStarts(numPlayers);
	int printPlayer = startingPlayer;
	cout << "Player " << printPlayer+1 << ", you've been randomly selected to start!" << endl;
	int currPlayer = startingPlayer;
	firstMove(&deck, currPlayer);	
	deck.currentP = currPlayer;
	deck.pastP = currPlayer - 1;
	updateEverything(&deck);
	while (true) {
		if (gameFinished(&deck) == true) {
			break;
		}
		else {
		playerTurn(&deck);
		updateEverything(&deck);	
		}
	}
	
	return 0;
}
