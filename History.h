#ifndef HISTORY_H
#define HISTORY_H
//this Header file contains class History which stores the moves, the opponent and self's win-loss-draw status. It also contains functions for memory housekeeping.  
#include "History.h"
# include "Global_Constants.h"
# include <vector>
# include <list>
# include <iostream>
# include <string>
# include <cmath>
#include <new>
#include <memory>

class History {
	//Stores each move from beginning of the round. Automatically calculates win loss and stores it as well. 
	//All values are stored as static. If player_manager plays against itself, self opponent will be inverted by other functions
public:
	//See below for member defintions file of the same name for function descriptions and/or documentation
	History() {}
	void newMove(int self, int opponent);
	//Inputs next new moves for self and opponent. Fnc stores it
	static void clear();
	//Clears entire history
	static void clearEverythingBut(int value);
	//Clears entire history except last "value" moves
	int getSize();
	//get the size of the storage vectors
	int compare(char x, int range2 = -1, int range = -2);
	//compare the rangeth element with the range2 element of the same vector opponent or self, determine by char x = 's'(self) or else (opponent)
	int H(char x, int range, int type);
	//goes to range "int range" of the self's move storage vector if char x = 's' else goes to opponent's storage vector. Finds the move that's of type compare to the selected move. 
	//(if rock, will return paper if type = +1, if rock, will return rock if type = 0; if rock, will return scissor if type = -1)
	void getInfo();
	void getLastWinStatus(char x = 's');
	void convert(int &value);

	static std::vector<std::vector<int>> movehistory;
	static std::vector<char> statushistoryS;
	static std::vector<char> statushistoryO;
	static int totalmoves;
	static int winsS;
	static int winsO;
	static int draw;


};



//Implementations
void History::newMove(int self, int opponent) {
	//Adds new entry to history & automatically calculates win loss draw status to be stored
	try {
		std::vector<int> newEntry = { self,opponent };
		this->movehistory.push_back(newEntry);
		int difference = self - opponent;
		if (self == 2 && opponent == 0) {
			statushistoryS.push_back('L');
			statushistoryO.push_back('W');
			totalmoves++;
			winsO++;
		}
		else if (self == 0 && opponent == 2) {
			statushistoryS.push_back('W');
			statushistoryO.push_back('L');
			totalmoves++;
			winsS++;
		}
		else if (difference == 0) {
			statushistoryS.push_back('D');
			statushistoryO.push_back('D');
			totalmoves++;
			draw++;
		}
		else if (difference > 0) {
			statushistoryS.push_back('W');
			statushistoryO.push_back('L');
			totalmoves++;
			winsS++;
		}
		else {
			statushistoryS.push_back('L');
			statushistoryO.push_back('W');
			totalmoves++;
			winsO++;
		}
	}
	catch (...) {
		std::cerr << "\nAn error occured\n";
	}
}

void History::clear() {
	// clears history
	movehistory.clear();
	statushistoryS.clear();
	statushistoryO.clear();
}

void History::clearEverythingBut(int value) {
	/*clears all memory except the lastest 'value' steps

	*/
	std::vector<std::vector<int>> movehistorytemp;
	std::vector<char> statushistorySTemp;
	std::vector<char> statushistoryOTemp;
	for (int i = movehistory.size() - value; i < movehistory.size(); i++)
	{
		movehistorytemp.push_back(movehistory[i]);
		statushistorySTemp.push_back(statushistoryS[i]);
		statushistoryOTemp.push_back(statushistoryO[i]);
	}
	clear();
	for (int i = 0; i < movehistorytemp.size(); i++)
	{
		movehistory.push_back(movehistorytemp[i]);
		statushistoryS.push_back(statushistorySTemp[i]);
		statushistoryO.push_back(statushistoryOTemp[i]);
	}
}

int History::getSize() {
	return statushistoryO.size(); // equal to size historySelf
}

int History::compare(char x, int range2, int range) {
	//Compare difference in move type between two index range2 and range1 of vector statushistoryS or statushistoryO, char x represent self if == 's', opponent if == 'o' and dictates which vector is picked. 
	int movehis1 = H(x, range, 0);
	int movehis2 = H(x, range2, 0);
	int difference = movehis2 - movehis1;
	// test code std::cout << H(x, range2, 0) << std::endl << H(x, range, 0);
	if (movehis1 == 0 && movehis2 == 2) {
		difference = -1;
	}
	if (movehis1 == 2 && movehis2 == 0) {
		difference = 1;
	}
	return difference;
}

int History::H(char x, int range, int type) {
	// As defined by project description
	try {
		int index = movehistory.size() + range; // range is a negative value
		if (index < 0) {
			throw "Exception";
		}
		if (index >= movehistory.size()) {
			std::cout << "\nIndex size = " << index << "\nMovehistory.size = " << movehistory.size();
			throw "Exception";
		}
		int index2 = 1;
		if (x == 's') {
			index2 = 0;
		}
		int move = movehistory[index][index2];
		move = move + type;
		convert(move);
		// converts changes 3 into 0, -1 into 2 etc. Ensures function returns a valid move (rock, paper or scissor)
		return move;
	}
	catch (...) {
		std::cerr << "\nAn error occured with H()\n";
	}
}

void History::getInfo() {
	// prints move history from beginning to end.
	for (int i = 0; i < (int)movehistory.size(); i++) {
		std::cout << movehistory[i][0] << movehistory[i][1] << " ";
		// print int representations of rock (0), paper (1), scissors (2)
	}
	std::cout << std::endl;
	for (int i = 0; i < (int)movehistory.size(); i++) {
		std::cout << " " << statushistoryS[i] << " ";
		//print win loss
	}
	std::cout << std::endl;
	for (int i = 0; i < (int)movehistory.size(); i++) {
		std::cout << " " << statushistoryO[i] << " ";
	}
}

void History::getLastWinStatus(char x) {
	// as fnc name indicates. 's' = self. Any other car = opponent
	if (x == 's') {
		std::cout << statushistoryS[statushistoryS.size() - 1];
	}
	else {
		std::cout << statushistoryO[statushistoryO.size() - 1];
	}
}

void History::convert(int &value) {
	//Rock paper scissor are associated with 0, 1, 2 respectively. If it gets out of bound  through predictable calculation done by other fncs, (value = below 0, or above 2), function converts it back to its intended move. 
	if (value < 0) {
		value = Scisor;
	}
	if (value > Scisor) {
		value = Rock;
	}
}

std::vector<std::vector<int>> History::movehistory;
std::vector<char> History::statushistoryS;
std::vector<char> History::statushistoryO;
int History::totalmoves = 0;
int History::winsS = 0;
int History::winsO = 0;
int History::draw = 0;

# endif


