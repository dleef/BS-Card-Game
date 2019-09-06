#ifndef DECK_H
#define DECK_H
#include "BSPlayer.hpp"
#include <vector>
using namespace std;	
class Deck {

	public:
		Deck(int n);
		vector<Card> deck;
		vector<Card> pile; //the actual pile of cards in the middle that constantly gets updated
		void initDeck();
		void initAsciiPrints();	
		void initPlayers();
		vector<Card> prevCards;
		vector<Player> players;	
		int currentCard;
		int pastCard;
		int numPlayers;
		int currentP;
		int pastP;
		
};
#endif
