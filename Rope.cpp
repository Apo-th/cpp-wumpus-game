#include "Rope.h"

Rope::Rope() : Item("Rope") {}

string Rope::getName() {
	return name;
}

string Rope::displayDescription() {
	return "Survive falling down a pit once\n";
}