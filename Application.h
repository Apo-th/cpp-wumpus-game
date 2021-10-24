/**************************************************
 Project: Assignment 2
 Author: Tyler Saito
 Purpose: Application Class HEADER File
**************************************************/

#ifndef APPLICATION_H
#define APPLICATION_H

// include all necessary libraries
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include "Player.h"
#include "Location.h"
#include "Hazard.h"
#include "Pit.h"
#include "Wumpus.h"
#include "Bats.h"

using namespace std;

// global variables
int currentPos;
Player* player;
vector<Location*> gameLocs;
string direction;
int option = -1;
vector<Hazard*> hazards;
int score;
// methods
int runGame();
string askForString(string question, vector<string> valid);
int askForInt(string question, vector<int> valid);
string printLoc(Location *location);
void printAllLoc();
void setLocations();
void movePlayer(string move);
void displayTitle();
string readFromFile(string fileName);
string displayOptions();
int checkDirection(string direction, vector<string> currentExits);
void setHazards(string difficulty);

#endif