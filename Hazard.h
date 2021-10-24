/**************************************************
 Project: Assignment 2
 Author: Tyler Saito
 Purpose: Hazard Class HEADER File
**************************************************/

#ifndef HAZARD_H
#define HAZARD_H

// include all necessary libraries
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>

using namespace std;

// character class
class Hazard {
public:
	// constructor
	~Hazard() {}
	Hazard(string name);
	Hazard();
	// accessor methods
	string getName();
	// mutator methods
	
	// display variables
	virtual string displayClue();
	virtual string sameRoom();
protected:
	// player variables
	string name;
};

#endif