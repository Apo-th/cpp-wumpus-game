/**************************************************
 Project: Assignment 3
 Author: Tyler Saito
 Purpose: HAZARD Class cpp File
**************************************************/

#include "Location.h"

Location::Location(string name, string description, int locID, vector<string> exits, vector<int> connections) {
	setName(name);
	setDescription(description);
	setLocID(locID);
	setExits(exits);
	setConnections(connections);
	setHazard(nullptr);
}
// accessor methods
string Location::getName() {
	return name;
}
string Location::getDescription() {
	return description;
}
int Location::getLocID() {
	return locID;
}
vector<string> Location::getExits() {
	return exits;
}
vector<int> Location::getConnections() {
	return connections;
}

// mutator methods
void Location::setName(string name) {
	this->name = name;
}
void Location::setDescription(string description) {
	this->description = description;
}
void Location::setLocID(int id) {
	locID = id;
}
void Location::setExits(vector<string> exits) {
	this->exits = exits;
}
void Location::setConnections(vector<int> connections) {
	this->connections = connections;
}
// display variables
string Location::displayInfo() {
	string info = "[" + to_string(locID) + "] " + name + "\n";
	info += description + "\n";
	info += "Visible exits: " + showExits();

	return info;
}
string Location::showExits() {
	string info = "";
	for (int i = 0; i != exits.size(); i++) {
		if (i == exits.size() - 1)
		{
			info += exits[i];
		}
		else {
			info += exits[i] + " ";
		}
	}
	info += "\n";

	return info;
}
void Location::setHazard(Hazard* newHazard) {
	hazard = newHazard;
}

Hazard* Location::getHazard() {
	return hazard;
}
