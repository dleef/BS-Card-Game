#include <iostream>
#include <string>
#include "BSCard.hpp"
using namespace std;
/*
** Author: Daniel Leef
*/

Card::Card() {
	type = "";
	number = 0;
}
Card::Card(string t, int numb) {

	type = t;
	number = numb;
}
