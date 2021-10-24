/**************************************************
 Project: Assignment 2
 Author: Tyler Saito
 Purpose: Bats Class HEADER File
**************************************************/

#ifndef BATS_H
#define BATS_H

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
class Bats : public Hazard{
public:
	// constructor
	~Bats() {}
	Bats();
	// accessor methods

	// mutator methods

	// display variables
	string displayClue();
	string sameRoom();
private:
	// player variables

};

#endif