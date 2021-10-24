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
		}
		else if (success == 0)
		{
			cout << "Better luck next time\n";
		}
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
	vector<string> options = {"S", "M", "H", "Q", "C"};
	string difficulty = askForString("What difficulty would you like to play?\n      [E]asy     [H]ard\n", {"E", "H"});
	setHazards(difficulty);

	while (cont) {
		// check is you are in or next to hazard room
		if (gameLocs[currentPos]->getHazard() != nullptr)
		{
			cout << gameLocs[currentPos]->getHazard()->sameRoom() << endl;
			// if wumpus or pit end the game
			if (gameLocs[currentPos]->getHazard()->getName() == "Wumpus" || gameLocs[currentPos]->getHazard()->getName() == "Pit")
			{
				return 0;
			}
			// if bats move to random room
			else if (gameLocs[currentPos]->getHazard()->getName() == "Bats")
			{
				currentPos = rand() % 20;
				currentExits = gameLocs[currentPos]->getExits();
			}
		}
		else
		{
			for (int i = 0; i < gameLocs[currentPos]->getConnections().size(); i++) {
				if (gameLocs[gameLocs[currentPos]->getConnections()[i]]->getHazard() != nullptr)
				{
					cout << gameLocs[gameLocs[currentPos]->getConnections()[i]]->getHazard()->displayClue();
				}
			}
		}
		// checks if player is out of time or arrows
		if (player->getArrows() == 0)
		{
			cout << "You ran out of arrows\n";
			return 0;
		} 
		else if (player->getOil() == 0)
		{
			cout << "You ran out of time\n";
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
			if (gameLocs[checkDirection(shoot, currentExits)]->getHazard() != nullptr)
			{
				if (gameLocs[checkDirection(shoot, currentExits)]->getHazard()->getName() == "Wumpus")
				{
					return 1;
					player->useArrow();
				}
			}
			
		}
		if (action == "C")
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
		}
		else if (action == "Q")
		{
			return 2;
		}
		// update oil
		player->useOil();
		
	}
	return 1;
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
	if (difficulty == "E")
	{
		hazards.push_back(new Wumpus());
		hazards.push_back(new Pit());
		hazards.push_back(new Pit());
		hazards.push_back(new Bats());
		hazards.push_back(new Bats());
		for (int i = 0; i < hazards.size(); i++)
		{
			bool flag = true;
			while (flag)
			{
				int random = rand() % 20;
				if (gameLocs[random]->getHazard() == nullptr)
				{
					gameLocs[random]->setHazard(hazards[i]);
					cout << gameLocs[random]->displayInfo() << endl;
					flag = false;
				}
			}
		}
	}
	else if (difficulty == "H")
	{
		hazards.push_back(new Wumpus());
		hazards.push_back(new Pit());
		hazards.push_back(new Pit());
		hazards.push_back(new Pit());
		hazards.push_back(new Bats());
		hazards.push_back(new Bats());
		hazards.push_back(new Bats());
		for (int i = 0; i < hazards.size(); i++)
		{
			bool flag = true;
			while (flag)
			{
				int random = rand() % 20;
				if (gameLocs[random]->getHazard() == nullptr)
				{
					gameLocs[random]->setHazard(hazards[i]);
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
	retVal += "[S]hoot   [M]ap   [H]elp   [Q]uit   [C]hange location\n";
	retVal += "Arrows: " + to_string(player->getArrows()) + "      Oil: " + to_string(player->getOil());
	return retVal;
}

int checkDirection(string direction, vector<string> currentExits) {
	int exitPos = 0;
	for (exitPos; exitPos < 2; exitPos++)
	{
		if (currentExits[exitPos] == direction) {
			return exitPos;
		}
	}
	return -1;
}
