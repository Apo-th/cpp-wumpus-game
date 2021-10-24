#include "Hazard.h"

Hazard::Hazard(string name){
	this->name = name;
}

Hazard::Hazard(){}

string Hazard::displayClue() {
	return "You notice something seems off about\nthe room next to you";
}

string Hazard::sameRoom() {
	return "You are in the same room as a hazard, something\nbad will happen...";
}

string Hazard::getName() {
	return name;
}