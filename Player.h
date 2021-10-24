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
#include "Item.h"

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
	int getGold();
	int getMaxOil();
	int getMaxArrows();
	vector<Item*> getItems();

	// mutator methods
	void setName(string name);
	void setArrows(int arrows);
	void setOil(int oil);
	void useOil();
	void useArrow();
	bool useGold(int spent);
	void findGold(int found);
	bool addArrows(int add);
	bool addOil(int add);
	void addItem(Item* item);
	// display variables
	string displayInfo();
	string displayItems();
private:
	// player variables
	string name;
	int oil;
	int arrows;
	int MAX_OIL = 30;
	int MAX_ARROWS = 5;
	int gold;
	vector<Item*> items;
};

#endif