#include "Wumpus.h"

Wumpus::Wumpus() : Hazard("Wumpus") {}

string Wumpus::displayClue() {
	return "You hear a loud snoring, you\nfigure there must be a wumpus nearby\n";
}

string Wumpus::sameRoom() {
	return "You see a Wumpus in front of you and\nit all fades to black as it opens it's eyes\n";
}

void Wumpus::setPosition(int newPosition) {
	position = newPosition;
}

int Wumpus::getPosition() {
	return position;
}