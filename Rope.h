/**************************************************
 Project: Assignment 2
 Author: Tyler Saito
 Purpose: Rope Class HEADER File
**************************************************/

#ifndef ROPE_H
#define ROPE_H

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
class Rope : public Item {
public:
	// constructor
	~Rope() {}
	Rope();
	// accessor methods
	string getName();

	// mutator methods

	// display variables
	string displayDescription();

protected:
	// player variables
};

#endif