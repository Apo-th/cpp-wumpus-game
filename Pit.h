/**************************************************
 Project: Assignment 2
 Author: Tyler Saito
 Purpose: Pit Class HEADER File
**************************************************/

#ifndef PIT_H
#define PIT_H

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
class Pit : public Hazard{
public:
	// constructor
	~Pit() {}
	Pit();
	// accessor methods

	// mutator methods

	// display variables
	string displayClue();
	string sameRoom();
private:
	// player variables

};

#endif