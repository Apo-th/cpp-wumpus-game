/**************************************************
 Project: Assignment 2
 Author: Tyler Saito
 Purpose: Item Class HEADER File
**************************************************/

#ifndef ITEM_H
#define ITEM_H

// include all necessary libraries
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>

using namespace std;

// character class
class Item {
public:
	// constructor
	~Item() {}
	Item(string name);
	// accessor methods
	string getName();
	
	// mutator methods
	
	// display variables
	virtual string displayDescription();

protected:
	// player variables
	string name;
};

#endif