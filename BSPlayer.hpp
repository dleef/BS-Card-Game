#ifndef PLAYER_H
#define PLAYER_H
#include "BSCard.hpp"
#include <vector>
class Player {
	
	public:
		Player(int numb);
		void addCard(Card c);
		void addCards(vector<Card> &v);
		int playerNumber;
		//player's specific set of cards
		vector<Card> playerCards;
};

#endif

