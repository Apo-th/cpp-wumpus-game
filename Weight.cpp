#include "Weight.h"

Weight::Weight() : Item("Weight"){}

string Weight::getName() {
	return name;
}

string Weight::displayDescription() {
	return "Become to heavy to be picked up by bats once\n";
}