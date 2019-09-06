#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <ctime>
#include <string>
#include <vector>
#include "BSFunctions.hpp"
using namespace std;

void printCurrentCard(Deck *deck) {
	cout << "Current Card: ";
	if (deck->currentCard == 1) {
		
		cout << "Ace" << endl;
	
	}
	else if (deck->currentCard == 11) {
		
		cout << "Jack" << endl;
		
	}
	else if (deck->currentCard == 12) {
	
		cout << "Queen" << endl;
	
	}
	else if (deck->currentCard == 13) {
	
		cout << "King" << endl;
	
	}
	else {
	
		cout << deck->currentCard << endl;
	
	}

}
void updatePastCard(Deck *deck) {
	deck->pastCard = deck->currentCard;
}
void updateCurrentCard(Deck *deck) {
	if (deck->currentCard == 13) {
		deck->currentCard = 1;
	
	}
	else {
		deck->currentCard += 1;
	}
}

void shuffleDeck(Deck *deck) {

	random_shuffle(deck->deck.begin(), deck->deck.end());

}

void parseCards(Deck *deck) {

	int change = 52 / deck->numPlayers;
	int playerNumb = 0;
	for (int i = 0; i < (change*deck->numPlayers); i++) {
		
		if (i % change == 0 && i != 0) {
			playerNumb++;
		}
	
		deck->players[playerNumb].addCard(deck->deck[i]);
	}
	//leftover cards needed to be dealt
	playerNumb = 0;
	for (int j = (change*deck->numPlayers); j < 52; j++) {
	
		deck->players[playerNumb].addCard(deck->deck[j]);
		playerNumb++;
	
	}
}


//copied from https://stackoverflow.com/questions/4654636/how-to-determine-if-a-string-is-a-number-with-c
bool isNumb(const string &s) {
	return !s.empty() && find_if(s.begin(), s.end(), [](char c) {
			return !isdigit(c);
			}) == s.end();
}

int getNumPlayers() {
	string numPlayers;
	cout << "Please enter how many players will be participating (3-10): ";
	getline(cin, numPlayers);
	while (!isNumb(numPlayers)) {
		cout << "Invalid input, please try again: ";
		getline(cin, numPlayers);		
	}
	int nP;
        nP = stoi(numPlayers);
	while (nP < 3 || nP > 10) {
		cout << "Invalid input, please try again: ";
		getline(cin, numPlayers);
		nP = stoi(numPlayers);
	
	}
	return nP;
}

int findWhoStarts(int numPlayers) {

	srand(time(NULL));
	return (int)(rand() % numPlayers);
	
}

void firstMove(Deck *deck, int playerNumber) {
	printCurrentCard(deck);
	int printPN = playerNumber;
	printPN++;
	cout << "Your cards (Player " << printPN << "): " << endl;
	map<int, Card> cardOptions;
        for (int i = 0; i < deck->players[playerNumber].playerCards.size(); i++) {
                if (deck->players[playerNumber].playerCards[i].number == 11) {               
		       	cout << (i+1) << ") Jack" << " " << deck->players[playerNumber].playerCards[i].type << endl;
                }
                else if (deck->players[playerNumber].playerCards[i].number == 1) {               
		       	cout << (i+1) << ") Ace" << " " << deck->players[playerNumber].playerCards[i].type << endl;
                }
                else if (deck->players[playerNumber].playerCards[i].number == 12) {               
		       	cout << (i+1) << ") Queen" << " " << deck->players[playerNumber].playerCards[i].type << endl;
                }
                else if (deck->players[playerNumber].playerCards[i].number == 13) {               
		       	cout << (i+1) << ") King" << " " << deck->players[playerNumber].playerCards[i].type << endl;
                }
                else {
                cout << (i+1) << ") " << deck->players[playerNumber].playerCards[i].number << " " << deck->players[playerNumber].playerCards[i].type << endl;
                }
                cardOptions[i+1] = deck->players[playerNumber].playerCards[i];
        }
        cout << "Enter the number corresponding to the card to place it on the pile." << endl;
        cout << "You can put multiple cards in, but enter each number corresponding to the card on a new line (4 cards max)." << endl;
        cout << "Type 'done' on a new line when finished." << endl;
	string userInput;
	int cardsIn = 0;
        while(true) {
		if (cardsIn == 4) {
			break;
		}
		getline(cin, userInput);
		if (userInput == "done") {
			if (cardsIn == 0) {
				cout << "You must put at least one card in the pile" << endl;
			}
			else {
				break;
			}
		}
		else if (!isNumb(userInput) && userInput != "done") {
			cout << "You must enter a number corresponding to a card or 'done'" << endl;
		}
		else {
                int uin = stoi(userInput);
		if (uin < 1 || uin > cardOptions.size()) {
			cout << "You must enter a number corresponding to a card or 'done'"<< endl;
		}
		else {
		cardsIn++;
                deck->pile.push_back(cardOptions[uin]);
                //supposedly erases the userInput position card in the playerCards vector
                deck->prevCards.push_back(cardOptions[uin]);
                cardOptions.erase(uin);
                deck->players[playerNumber].playerCards.erase(deck->players[playerNumber].playerCards.begin() + uin-1);
		}
		}
		
        }

}

bool gameFinished(Deck *deck) {

	for (int i = 0; i < deck->numPlayers; i++) {
		
		if (deck->players[i].playerCards.size() == 0) {
			
			cout << "Player " << (i+1) << " wins!" << endl;
			return true;
		
		}
			
	}	
	return false;

}

void callBS(Deck *deck, int player, int pastPlayer) {
	bool BS = false;
	for (int i = 0; i < deck->prevCards.size(); i++) {
		if (deck->prevCards[i].number != deck->pastCard) {
			
			cout << "BS IS CORRECT! Player " << (pastPlayer+1) << " gets all the cards!" << endl;
			deck->players[pastPlayer].addCards(deck->pile);
			BS = true;
			break;
		}
			
	}
	if (BS == false) {
		cout << "BS IS INCORRECT! Player " << (player+1) << " gets all the cards!" << endl;

	deck->players[player].addCards(deck->pile);	
	
	}
	cout << "*****THE PREVIOUS CARDS*****" << endl;
	printAllAscii(deck);
	deck->prevCards.clear();
	deck->pile.clear();

}

void printCard(Card card) {
	switch(card.number) {
		case 11: 
			cout << "Jack, " << card.type << endl;
			break;
		case 12:
			cout << "Queen, " << card.type << endl;
			break;
		case 13:
			cout << "King, " << card.type << endl;
			break;
		default:
			cout << card.number << ", " << card.type << endl;
			break;
	}

}

void printAscii(string input) {

	for (int i = 0; i < 15; i++) {
		for (int j = i*11; j < i*11 + 11; j++) {
			cout << input[j];
		}
		cout << endl;
	}
}

void printAllAscii(Deck *deck) {

	for (int i = 0; i < deck->prevCards.size(); i++) {
		printCard(deck->prevCards[i]);
		printAscii(deck->prevCards[i].asciiPrint);
	}

}
void updatePastPlayer(Deck *deck) {
	int numP = deck->numPlayers;
	numP--;	
	if (deck->pastP == numP) {
		deck->pastP = 0;
	}
	else {
		deck->pastP++;
	}
}
void updateCurrentPlayer(Deck *deck) {	
	int numP = deck->numPlayers;
	numP--;
	if (deck->currentP == numP) {
		deck->currentP = 0;
	}
	else {
		deck->currentP++;
	}
}

void updateEverything(Deck *deck) {	
	updatePastPlayer(deck);
	updateCurrentPlayer(deck);
	updatePastCard(deck);
	updateCurrentCard(deck);
}
void playerTurn(Deck *deck) {
	int pastPlayer = deck->pastP;
	int playerNumber = deck->currentP;
	int printPastPN = pastPlayer;
	printPastPN++;
	cout << "PLAYER " << printPastPN << " PUT DOWN " << deck->prevCards.size() << " CARD(S)" << endl;
	int printPN = playerNumber;
	printPN++;
	cout << "Player " << printPN << endl;
	cout << "Do you want to call BS on the previous player? (Y / N): ";
	string bs;
	getline(cin, bs);
	while (bs != "N" && bs != "Y") {
		cout << "Invalid input. Please try again: ";
		getline(cin, bs);
	}
	if (bs == "Y") {
		callBS(deck, playerNumber, pastPlayer);
	}
	else {
		deck->prevCards.clear();
	}

	printCurrentCard(deck);
	cout << "Your cards (Player " << printPN << "): " << endl;
	map<int, Card> cardOptions;
	for (int i = 0; i < deck->players[playerNumber].playerCards.size(); i++) {
		if (deck->players[playerNumber].playerCards[i].number == 11) {		
		cout << (i+1) << ") Jack" << " " << deck->players[playerNumber].playerCards[i].type << endl;
		}	
                else if (deck->players[playerNumber].playerCards[i].number == 1) {               
		       	cout << (i+1) << ") Ace" << " " << deck->players[playerNumber].playerCards[i].type << endl;
                }
		else if (deck->players[playerNumber].playerCards[i].number == 12) {	
		cout << (i+1) << ") Queen" << " " << deck->players[playerNumber].playerCards[i].type << endl;
		}
		else if (deck->players[playerNumber].playerCards[i].number == 13) {	
		cout << (i+1) << ") King" << " " << deck->players[playerNumber].playerCards[i].type << endl;
		}
		else {
		cout << (i+1) << ") " << deck->players[playerNumber].playerCards[i].number << " " << deck->players[playerNumber].playerCards[i].type << endl;
		}
		cardOptions[i+1] = deck->players[playerNumber].playerCards[i];
	}
	cout << "Enter the number corresponding to the card to place it on the pile." << endl;
	cout << "You can put multiple cards in, but enter each number corresponding to the card on a new line (4 cards max)." << endl;
	cout << "Type 'done' on a new line when finished" << endl;
	string userInput;
	int cardsIn = 0;
	while(true) {
		if (cardsIn == 4) {
                        break;
                }
                getline(cin, userInput);
                if (userInput == "done") {
                        if (cardsIn == 0) {
                                cout << "You must put at least one card in the pile" << endl;
                        }
                        else {
                                break;
                        }
                }
		else if (!isNumb(userInput) && userInput != "done") {
                        cout << "You must enter a number corresponding to a card or 'done'" << endl;
                }
                else {
                int uin = stoi(userInput);
                if (uin < 1 || uin > cardOptions.size()) {
                        cout << "You must enter a number corresponding to a card or 'done'"<< endl;
                }
                else {
                cardsIn++;
                deck->pile.push_back(cardOptions[uin]);
                //supposedly erases the userInput position card in the playerCards vector
                deck->prevCards.push_back(cardOptions[uin]);
                cardOptions.erase(uin);
                deck->players[playerNumber].playerCards.erase(deck->players[playerNumber].playerCards.begin() + uin-1);
                }
                }
	}
}
