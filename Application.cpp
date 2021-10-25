#include "Application.h"

/*
The main method to run
*/
int main() {
	displayTitle();
	while (option != 0)
	{
		cout << "0: QUIT\n";
		cout << "1: PLAY\n";
		option = askForInt("What do you want to do? ", { 0, 1 });
		if (option == 0)
		{
			return 1;
		}
		int success = runGame();
		if (success == 1)
		{
			cout << "Congratulations! You have defeated the\nWumpus and saved the town\n";
			cout << "Your final score was:\n";
			cout << to_string(score) << " points!\n";
		}
		else if (success == 0)
		{
			cout << "Better luck next time\n";
			cout << "Your final score was:\n";
			cout << to_string(score) << " points!\n";
		}
		cout << "Thank you for playing!\n";
	}
	
	return 1;
}

/*
Has most of the functionality for actually running the game
*/
int runGame() {
	// dsiplay how to play
	cout << readFromFile("How-to-Play");
	player = new Player(askForString("Please input your character name: ", {}));
	cout << player->displayInfo();
	setLocations();
	srand(time(NULL));
	currentPos = rand() % 20 + 1;
	vector<string> currentExits;
	currentExits = gameLocs[currentPos]->getExits();
	bool cont = true;
	vector<string> options = {"S", "M", "H", "Q", "B", "V"};
	string difficulty = askForString("What difficulty would you like to play?\n      [E]asy     [H]ard\n", {"E", "H"});
	setHazards(difficulty);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	win = 2;
	while (cont) {
		// check is you are in or next to hazard room
		if (gameLocs[currentPos]->getHazard() != nullptr)
		{
			cout << gameLocs[currentPos]->getHazard()->sameRoom() << endl;
			// if wumpus or pit end the game
			if (gameLocs[currentPos]->getHazard()->getName() == "Wumpus")
			{
				// check if you have super suit
				bool live = false;
				for (int i = 0; i < player->getItems().size(); i++)
				{
					if (player->getItems()[i]->getName() == "SuperSuit")
					{
						live = true;
						player->getItems().erase(player->getItems().begin() + i);
						break;
					}
				}
				if (!live)
				{
					score = calculateScore(difficulty) / 2;
					return 0;
				}
				else
				{
					cout << "You have been saved by the super suit you found\n";
				}
				
			}
			// if bats move to random room
			else if (gameLocs[currentPos]->getHazard()->getName() == "Bats")
			{
				bool safe = false;
				for (int i = 0; i < player->getItems().size(); i++)
				{
					if (player->getItems()[i]->getName() == "Weight")
					{
						safe = true;
						player->getItems().erase(player->getItems().begin() + i);
					}
				}
				if (!safe)
				{
					currentPos = rand() % 20;
					currentExits = gameLocs[currentPos]->getExits();
					// check if new room will kill you
					if (gameLocs[currentPos]->getHazard() != nullptr) {
						cout << gameLocs[currentPos]->getHazard()->sameRoom() << endl;
						// if wumpus or pit end the game
						if (gameLocs[currentPos]->getHazard()->getName() == "Wumpus" || gameLocs[currentPos]->getHazard()->getName() == "Pit")
						{
							score = calculateScore(difficulty) / 2;
							return 0;
						}
					}
				}
				else
				{
					cout << "You were saved by the weights,\nyou were too heavy for the bats to carry";
				}
				
			}
			else if (gameLocs[currentPos]->getHazard()->getName() == "Pit")
			{
				bool safe = false;
				for (int i = 0; i < player->getItems().size(); i++)
				{
					if (player->getItems()[i]->getName() == "Rope")
					{
						safe = true;
						player->getItems().erase(player->getItems().begin() + i);
					}
				}
				if (!safe)
				{
					score = calculateScore(difficulty) / 2;
					return 0;
				}
				else
				{
					"You were saved by the rope. You\nmanaged to hook the ledge and climb out";
				}
			}
		}
		// give warning hazards if nearby
			for (int i = 0; i < gameLocs[currentPos]->getConnections().size(); i++) {
				if (gameLocs[gameLocs[currentPos]->getConnections()[i]]->getHazard() != nullptr)
				{
					cout << gameLocs[gameLocs[currentPos]->getConnections()[i]]->getHazard()->displayClue();
				}
			}
		// checks if player is out of time or arrows
		if (player->getArrows() == 0)
		{
			cout << "You ran out of arrows\n";
			score = calculateScore(difficulty) / 2;
			return 0;
		} 
		else if (player->getOil() == 0)
		{
			cout << "You ran out of time\n";
			score = calculateScore(difficulty) / 2;
			return 0;
		}
		cout << printLoc(gameLocs[currentPos]) << endl;
		// Print number of turns left
		// display options to player
		cout << displayOptions() << endl;
		// get what player wants to do
		string action = askForString("What would you like to do?\n", options);
		if (action == "S")
		{
			string shoot = askForString("Please input the direction you wish to shoot\n" + gameLocs[currentPos]->showExits(), currentExits);
			if (gameLocs[checkDirection(shoot, currentExits)]->getHazard())
			{
				cout << gameLocs[checkDirection(shoot, currentExits)]->getHazard()->getName() << endl;
				if (gameLocs[checkDirection(shoot, currentExits)]->getHazard()->getName() == "Wumpus")
				{
					win = 1;
					cont = false;
					score = calculateScore(difficulty);
				}
				else
				{
					cout << "Unfortunately you missed the target,\you flinch at the sound of the clattering arrow\n";
					if (rand() % 10 > 2)
					{
						// move wumpus
						int position = rand() % 3;
						gameLocs[hazards[0]->getPosition()]->setHazard(nullptr);
						int newPos = gameLocs[hazards[0]->getPosition()]->getConnections()[position];
						gameLocs[newPos]->setHazard(hazards[0]);
						hazards[0]->setPosition(position);
						cout << "Unluckily, the Wumpus has awoken at the sound of a wild arrow.\nIt is moving to a new place\n" << endl;
						if (gameLocs[newPos]->getHazard() != nullptr)
						{
							if (gameLocs[newPos]->getHazard()->getName() == "Wumpus");
							{
								// check if you have super suit
								bool live = false;
								for (int i = 0; i < player->getItems().size(); i++)
								{
									if (player->getItems()[i]->getName() == "SuperSuit")
									{
										live = true;
										player->getItems().erase(player->getItems().begin() + i);
										break;
									}
								}
								if (!live)
								{
									score = calculateScore(difficulty) / 2;
									return 0;
								}
								else
								{
									cout << "You have been saved by the super suit you found\n";
								}
							}
						}
						
					}
				}
			}
			player->useArrow();
			player->useOil();			
		}
		else if (action == "M")
		{
			direction = askForString("Please input the direction you wish to travel out of\n" + gameLocs[currentPos]->showExits(), currentExits);
			int exitPos = 0;
			for (exitPos; exitPos < 2; exitPos++)
			{
				if (currentExits[exitPos] == direction) {
					break;
				}
			}
			currentPos = gameLocs[currentPos]->getConnections()[exitPos];
			currentExits = gameLocs[currentPos]->getExits();
			player->useOil();

			// player gets 0-9 gold each turn
			player->findGold(rand() % 10);
			// 1/1000 chance of finding a super suit
			if (rand() % 1000 == 0)
			{
				player->getItems().push_back(new SuperSuit);
				cout << "Congratulations, you have just picked up a super suit";
				cout << player->getItems()[player->getItems().size() - 1]->displayDescription();
			}
		}
		else if (action == "Q")
		{
			cont = false;
			score = 0;
		}
		else if (action == "H")
		{
			cout << readFromFile("How-to-Play");
		}
		else if (action == "B")
		{
			shop();
		}
		else if (action == "V")
		{
			cout << player->displayItems();
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	}
	return win;
}

void setLocations() {
	gameLocs.push_back(new Location("Cave entrance", "This is the entrance of a cave", 0, {"S", "SE", "E"},  { 1, 2, 3 }));
	gameLocs.push_back(new Location("Small cave", "This is a small cave", 1, {"N", "E", "SE"}, { 0, 4, 5 }));
	gameLocs.push_back(new Location("Poisonous bog", "This bog is poisonous", 2, {"NW", "NE", "SE"}, { 0, 3, 4 }));
	gameLocs.push_back(new Location("Overgrown path", "This path is full of weeds", 3, {"W", "SW", "E" }, { 0, 2, 6 }));
	gameLocs.push_back(new Location("Hidden ravine", "This ravine is hard to see", 4, { "E", "NE", "S" }, { 1, 2, 9 }));
	gameLocs.push_back(new Location("Square", "This room is incredibly square", 5, { "NW", "E", "SW" }, { 1, 9, 12 }));
	gameLocs.push_back(new Location("Dry heat", "It's very dry here", 6, { "W", "SW", "E" }, { 3, 7, 18 }));
	gameLocs.push_back(new Location("Damp cave", "It's very damp here", 7, { "NE", "SE", "S" }, { 6, 8, 10 }));
	gameLocs.push_back(new Location("Treasure room", "There's a lot of treasure in here", 8, { "NW", "SE", "E" }, {7, 11, 19}));
	gameLocs.push_back(new Location("Skeleton bones", "There are skeletons of past humans", 9, { "N", "NE", "W" }, {4, 10, 5}));
	gameLocs.push_back(new Location("Rotting room", "This room smells rotten", 10, { "S", "SW", "E" }, {7, 9, 11}));
	gameLocs.push_back(new Location("Ominous tunnel", "This tunnel makes you feel uneasy", 11, { "NW", "W", "SE" }, {8, 10, 17}));
	gameLocs.push_back(new Location("Dripping cave", "A lot of liquid is dripping from the ceiling", 12, { "NE", "E", "SE" }, {5, 13, 15}));
	gameLocs.push_back(new Location("Large room", "This room is very large", 13, { "W", "NE", "E" }, {12, 14, 15}));
	gameLocs.push_back(new Location("Straight tunnel", "This tunnel is long and straight", 14, { "SW", "W", "SE" }, {13, 15, 16}));
	gameLocs.push_back(new Location("Scratched walls", "The walls are oddly scratched", 15, { "NW", "W", "E" }, {12, 13, 14}));
	gameLocs.push_back(new Location("Oval room", "This is an oval shaped room", 16, { "NW", "NE", "N" }, {14, 17, 18}));
	gameLocs.push_back(new Location("Large statues", "There are 2 large statues in the room", 17, { "NW", "SW", "N" }, {11, 16, 19}));
	gameLocs.push_back(new Location("Dark spikes", "This is a dark room, but you can feel the spikes", 18, { "W", "S", "SE" }, {6, 16, 19}));
	gameLocs.push_back(new Location("Bright room", "This room is very bright", 19, { "W", "S", "NW" }, {8, 17, 18}));
}

void setHazards(string difficulty) {
	// seed rand
	srand(time(NULL));
	// set hazards, more with higher difficulty
	int random = rand() % 20;
	// set wumpus position and the room it is in
	hazards.push_back(new Wumpus());
	gameLocs[random]->setHazard(hazards[0]);
	hazards[0]->setPosition(random);
	if (difficulty == "E")
	{
		hazards.push_back(new Pit());
		hazards.push_back(new Pit());
		hazards.push_back(new Bats());
		hazards.push_back(new Bats());
		for (int i = 1; i < hazards.size(); i++)
		{
			bool flag = true;
			while (flag)
			{
				random = rand() % 20;
				if (gameLocs[random]->getHazard() == nullptr)
				{
					gameLocs[random]->setHazard(hazards[i]);
					//cout << gameLocs[random]->displayInfo() << endl;
					flag = false;
				}
			}
		}
	}
	else if (difficulty == "H")
	{
		hazards.push_back(new Pit());
		hazards.push_back(new Pit());
		hazards.push_back(new Pit());
		hazards.push_back(new Bats());
		hazards.push_back(new Bats());
		hazards.push_back(new Bats());
		player->setOil(20);
		for (int i = 0; i < hazards.size(); i++)
		{
			bool flag = true;
			while (flag)
			{
				random = rand() % 20;
				if (gameLocs[random]->getHazard() == nullptr)
				{
					gameLocs[random]->setHazard(hazards[i]);
					//cout << gameLocs[random]->displayInfo() << endl;
					flag = false;
				}
			}
		}
	}
}


// get the inpit from the user and check it against an vector of valid inputs
// input: question you want to ask the user, a list of valid responses
// output: The user's response
string askForString(string question, vector<string> valid) {
	string userInput = "";
	bool flag = true;
	cin.ignore();
	if (valid.size() > 0) {
		string displayValid = "";
		for (int i = 0; i < valid.size(); i++) {
			displayValid += valid[i] + " ";
		}
		while (flag)
		{
			cout << "\n" + question;
			userInput = "";
			getline(cin, userInput);
			for (int i = 0; i < valid.size(); i++) {
				if (valid[i].compare(userInput) == 0)
				{
					flag = false;
				}
			}
			if (flag)
			{
				cout << "Please input one of: " << displayValid << endl;
			}
		}
	}
	else
	{
		cin.ignore();
		cout << "\n" + question;
		getline(cin, userInput);
	}
	return userInput;
}

void printAllLoc() {
	if (gameLocs.empty())
	{
		cout << "Please start the game\n";
	}
	else
	{
		vector<Location*>::const_iterator whichLocation;
		for (whichLocation = gameLocs.begin(); whichLocation != gameLocs.end();
			++whichLocation) {
			Location* myLocation = *whichLocation;
			cout << myLocation->displayInfo();
		}
	}
}

// get the input from the user and check it against an vector of valid inputs
// input: question you want to ask the user, a list of valid responses
// output: The user's response
int askForInt(string question, vector<int> valid) {
	int userInput = 0;
	bool flag = true;
	if (valid.size() > 0) {
		while (flag)
		{
			cout << "\n" + question;
			cin >> userInput;
			for (int i = 0; i < valid.size(); i++) {
				if (valid[i] == userInput)
				{
					flag = false;
				}
			}
		}
	}
	return userInput;
}

void movePlayer(string move) {
	gameLocs[currentPos]->getExits();
}

string printLoc(Location *location) {
	return location->displayInfo();
}

// display the title of the game
void displayTitle() {
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
	cout << "         Hunt the Wumpus" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

string readFromFile(string fileName) {
	// load responses from file
	ifstream fileToRead(fileName);
	if (fileToRead.is_open()) {
		string line = "";
		string fileInfo = "";
		while (!fileToRead.eof()) {
			getline(fileToRead, line, ';');
			fileInfo += line + "\n";
		}
	}
	else {
		return "\n File, " + fileName + " not found!\n";
	}
	fileToRead.close();
}

string displayOptions() {
	string retVal = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	retVal += "[S]hoot   [H]elp   [Q]uit   [M]ove   [B]uy   [V]iew Items\n";
	retVal += "Arrows: " + to_string(player->getArrows()) + "      Oil: " + to_string(player->getOil());
	retVal += "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return retVal;
}

int checkDirection(string direction, vector<string> currentExits) {
	int exitPos = 0;
	for (exitPos; exitPos < 3; exitPos++)
	{
		if (currentExits[exitPos] == direction) {
			return exitPos;
		}
	}
	return -1;
}

int calculateScore(string difficulty) {
	if (difficulty == "E")
	{
		return (player->getArrows() + player->getOil()) * 300;
	}
	else
	{
		return (player->getArrows() + player->getOil()) * 500;
	}
}

void shop() {
	// let player shop with gold they have
	bool shop = true;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << " Welcome to the shop, buy what you \n  want with the gold you find\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	vector<string> shoptions = {"E", "O", "A", "R", "W"};
	string shoptionsString = "[E]xit   [O]il   [A]rrows   [R]ope   [W}eights";
	while (shop)
	{
		string view = askForString("What would you like to view:\n" + shoptionsString + "\n", shoptions);
		if (view == "E")
		{
			break;
		}
		else if (view == "O")
		{
			cout << "Increase your chance of winning with more move\n";
			cout << "The price is 5 gold per oil\n";
			int originOil = player->getOil();
			int boughtOil = askForInt("How much oil do you wish to buy,\nup to 10 at a time?\n", {0,1,2,3,4,5,6,7,8,9,10});
			if (player->useGold(5*boughtOil))
			{
				if (player->addOil(boughtOil))
				{
					cout << to_string(boughtOil) << " added\n";
				}
				else
				{
					string confirm = askForString("You can only have a max of " + to_string(player->getMaxOil()) + " oil\n, do you wish to confirm [Y]  [N]", { "Y", "N" });
					if (confirm == "N")
					{
						player->setOil(originOil);
					}
				}
			}
			
		}
		else if (view == "A")
		{
			cout << "Increase your chance of hitting the Wumpus, by buying more arrows\n";
			cout << "The price is 10 gold per arrow\n";
			int originArrows = player->getArrows();
			int boughtArrows = askForInt("How many arrows do you wish to buy,\nup to 10 at a time?\n", { 0,1,2,3,4,5,6,7,8,9,10 });
			if (player->useGold(10*boughtArrows))
			{
				if (player->addArrows(boughtArrows))
				{
					cout << to_string(boughtArrows) << " added\n";
				}
				else
				{
					string confirm = askForString("You can only have a max of " + to_string(player->getMaxArrows()) + " oil\n, do you wish to confirm [Y]  [N]", { "Y", "N" });
						if (confirm == "N")
						{
							player->setOil(originArrows);
						}
				}
			}
			
		}
		else if (view == "R")
		{
			Rope* rope = new Rope();
			cout << rope->displayDescription();
			cout << "The price for a rope is 30 gold\n";
			string buyRope = askForString("Would you like to buy a rope? [Y]   [N]", { "Y", "N" });
			if (buyRope == "Y")
			{
				if (player->useGold(30))
				{
					player->getItems().push_back(rope);
				}
			}
		}
		else if (view == "W")
		{
			Weight* weight = new Weight();
			cout << weight->displayDescription();
			cout << "The price for a rope is 30 gold\n";
			string buyWeight = askForString("Would you like to buy a weight? [Y]   [N]", { "Y", "N" });
			if (buyWeight == "Y")
			{
				if (player->useGold(30))
				{
					player->getItems().push_back(weight);
				}
			}
		}
	}
}

