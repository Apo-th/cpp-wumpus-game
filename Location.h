/**************************************************
 Project: Assignment 2
 Author: Tyler Saito
 Purpose: Location Class HEADER File
**************************************************/

#ifndef LOCATION_H
#define LOCATION_H

// include all necessary libraries
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include "Hazard.h"

using namespace std;

// character class
class Location {
public:
	// constructor
	~Location() {}
	Location(string name, string description, int locID, vector<string> exits, vector<int> connections);
	// accessor methods
	string getName();
	string getDescription();
	int getLocID();
	vector<string> getExits();
	vector<int> getConnections();
	Hazard* getHazard();
	// mutator methods
	void setName(string name);
	void setDescription(string description);
	void setLocID(int id);
	void setExits(vector<string> exits);
	void setConnections(vector<int> connections);
	void setHazard(Hazard* newHazard);
	// display variables
	string displayInfo();
	string showExits();
private:
	// player variables
	string name;
	string description;
	int locID;
	vector<string> exits;
	vector<int> connections;
	Hazard* hazard;
};

#endif