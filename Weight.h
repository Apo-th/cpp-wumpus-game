/**************************************************
 Project: Assignment 2
 Author: Tyler Saito
 Purpose: Weight Class HEADER File
**************************************************/

#ifndef WEIGHT_H
#define WEIGHT_H

// include all necessary libraries
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include "Item.h"

using namespace std;

// character class
class Weight : public Item {
public:
	// constructor
	~Weight() {}
	Weight();
	// accessor methods
	string getName();

	// mutator methods

	// display variables
	string displayDescription();

protected:
	// player variables
};

#endif