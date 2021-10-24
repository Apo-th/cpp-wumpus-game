#include "SuperSuit.h"

SuperSuit::SuperSuit() : Item("Rope") {}

string SuperSuit::getName() {
	return name;
}

string SuperSuit::displayDescription() {
	return "A 1 in 1000 chance of getting this item\nSurvive the Wumpus' attack once";
}