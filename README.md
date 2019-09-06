# BS-Card-Game
An implementation of the card game BS in C++!

I decided to make this card game since I had already made the ASCII art for the various cards already for a computer science class I had; it's also one of my favorite card games.
In order to play correctly, you have to pass the computer around in a circle when it's each person's turn!

## The Rules
In case you're not familiar, BS actually stands for bulls**t and you'll soon find out why.
First, you need at least three people to play. Second, every player gets an equal number of cards from a shuffled deck.
The game starts with a random person and with the Ace card. Each player at each turn has two options:
1) If they actually have the card they're on (for example, the first player having an Ace or multiple Aces) they will put
those down onto the deck and say "(number of cards being put down) (current card)" (for example: "Three Aces")
2) If they don't have the card, this is where the BSing comes in. They must put down a card, or cards, that aren't correct while
still saying "(number of cards being put down) (current card)" (for example: putting down two Threes and saying "Two Kings" since the
current card is a King). You must lie and keep a straight face well enough so that nobody calls BS on you.

Anybody can call "BS" after anyone's turn. Two things can happen when a person calls "BS" on someone:
1) The person who said "BS" is right and all the cards in the pile, not just those put down by the last person, are 
given to the person who was BSing
2) The person who said "BS" is wrong and all the cards in the pile go to them

You go in a circle and the current cards rotate in order (Queen, King, Ace, Two, Three, etc.)

The first person to get rid of all their cards is the winner.

# Instructions to Play
Download a zip of this repo, unzip once downloaded and navigate to it. Then follow the below steps!

## To compile:
make bs.exe

## To run:
./bs.exe
