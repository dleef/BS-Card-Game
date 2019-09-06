#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
#include "BSDeck.hpp"
/*
** Author: Daniel Leef
*/
void playerTurn(Deck *deck);

void shuffleDeck(Deck *deck);

void parseCards(Deck *deck);

int getNumPlayers();

void firstMove(Deck *deck, int playerNumber);

bool isNumb(const string &s);

int findWhoStarts(int numPlayers);

bool gameFinished(Deck *deck);

void callBS(Deck *deck, Player *p);

void updatePastCard(Deck *deck);

void updateCurrentCard(Deck *deck);

void updateCurrentPlayer(Deck *deck);

void updatePastPlayer(Deck *deck);

void updateEverything(Deck *deck);

void printCurrentCard(Deck *deck);

void printAllAscii(Deck *deck);

void printAscii(string input);

void printCard(Card card);

#endif
