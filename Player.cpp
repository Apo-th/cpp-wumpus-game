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
	gold = 0;
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
int Player::getGold() {
	return gold;
}
int Player::getMaxArrows() {
	return 5;
}
int Player::getMaxOil() {
	return 30;
}
vector<Item*> Player::getItems() {
	return items;
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
bool Player::useGold(int spent) {
	if (gold - spent >= 0) {
		gold -= spent;
		return true;
	}
	else
	{
		cout << "You only have " << to_string(getGold()) << " gold\n";
		cout << "You need more gold to perform this action\n";
		return false;
	}
}
bool Player::addArrows(int add) {
	if (arrows + add <= MAX_ARROWS)
	{
		arrows += add;
		return true;
	}
	else
	{
		arrows == MAX_ARROWS;
		return false;
	}
}
bool Player::addOil(int add) {
	if (oil + add <= MAX_OIL)
	{
		oil += add;
		return true;
	}
	else
	{
		oil == MAX_OIL;
		return false;
	}
}
void Player::findGold(int found){
	gold += found;
}
void Player::addItem(Item* item) {
	items.push_back(item);
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

string Player::displayItems() {
	string itemList = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	if (items.size() > 0)
	{
		for (int i = 0; i < items.size(); i++) {
			itemList += items[i]->getName() + "\n";
		}
	}
	else
	{
		itemList += "You have no items at the moment";
	}
	
	itemList += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return itemList;
}