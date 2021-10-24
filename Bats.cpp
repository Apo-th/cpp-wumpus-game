#include "Bats.h"

Bats::Bats() : Hazard("Bats") {}

string Bats::displayClue() {
	return "You sense movement nearby, a slight\nshuffle of wings, almost like bats";
}

string Bats::sameRoom() {
	return "Your vision is blocked as you see bats\n fly at you. You open your eyes in another room";
}