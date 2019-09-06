#include <iostream>
#include <string>
#include "BSPlayer.hpp"
#include <vector>
using namespace std;

Player::Player(int numb) {
	
	playerNumber = numb;

}

void Player::addCard(Card c) {
	
	playerCards.push_back(c);

}

void Player::addCards(vector<Card> &v) {
	
	for (int i = 0; i < v.size(); i++) {
		
		playerCards.push_back(v[i]);
		
	}
	
}
