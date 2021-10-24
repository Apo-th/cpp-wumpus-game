#include "Pit.h"

Pit::Pit() : Hazard("Pit") {}

string Pit::displayClue() {
	return "Your footsteps echo, reminding you\nof the time you went near that deep hole";
}

string Pit::sameRoom() {
	return "You tumble down the edge, failing\nto catch the ledge and fall to your death";
}