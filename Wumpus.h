/**************************************************
 Project: Assignment 2
 Author: Tyler Saito
 Purpose: Wumpus Class HEADER File
**************************************************/

#ifndef WUMPUS_H
#define WUMPUS_H

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
class Wumpus : public Hazard{
public:
	// constructor
	~Wumpus() {}
	Wumpus();
	// accessor methods
	void setPosition(int newPosition);
	// mutator methods
	int getPosition();
	// display variables
	string displayClue();
	string sameRoom();
private:
	// Wumpus variables
	//int position;
};

#endif