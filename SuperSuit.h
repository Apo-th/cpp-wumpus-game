/**************************************************
 Project: Assignment 2
 Author: Tyler Saito
 Purpose: SuperSuit Class HEADER File
**************************************************/

#ifndef SUPERSUIT_H
#define SUPERSUIT_H

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
class SuperSuit : public Item {
public:
	// constructor
	~SuperSuit() {}
	SuperSuit();
	// accessor methods
	string getName();

	// mutator methods

	// display variables
	string displayDescription();

protected:
	// player variables
};

#endif