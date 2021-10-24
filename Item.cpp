#include "Item.h"

Item::Item(string name) {
	this->name = name;
}

string Item::getName() {
	return name;
}

string Item::displayDescription() {
	return "Generic description for item\n";
}