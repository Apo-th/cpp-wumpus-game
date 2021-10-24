/**************************************************
 Project: Assignment 2
 Author: Tyler Saito
 Purpose: Player Class HEADER File
**************************************************/

#ifndef PLAYER_H
#define PLAYER_H

// include all necessary libraries
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>

using namespace std;

// player class
class Player {
public:
	// constructor
	~Player() {}
	Player(string name);
	// accessor methods
	string getName();
	int getOil();
	int getArrows();
	// mutator methods
	void setName(string name);
	void setArrows(int arrows);
	void setOil(int oil);
	void useOil();
	void useArrow();
	// display variables
	string displayInfo();
private:
	// player variables
	string name;
	int oil;
	int arrows;
	int MAX_OIL = 30;
	int MAX_ARROWS = 5;
};

#endif