/**************************************************
 Project: RPG World
 Lab Num: Week 6
 Author: Tyler Saito
 Purpose: CHARACTER Class cpp File
**************************************************/

#include "Player.h"

Player::Player(string name) {
	setName(name);
	setArrows(MAX_ARROWS);
	setOil(MAX_OIL);
}
// accessor methods
string Player::getName() {
	return name;
}
int Player::getOil() {
	return oil;
}
int Player::getArrows() {
	return arrows;
}
// mutator methods
void Player::setName(string name){
	this->name = name;
}
void Player::setArrows(int arrows){
	this->arrows = arrows;
}
void Player::setOil(int oil){
	this->oil = oil;
}
void Player::useOil(){
	oil--;
}
void Player::useArrow(){
	arrows--;
}
// display variables
string Player::displayInfo(){
	string info = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	info += "Hi " + name + "\n";
	info += "You have " + to_string(oil) + " oil left\n";
	info += "You have " + to_string(arrows) + " arrows left\n";
	info += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return info;
}