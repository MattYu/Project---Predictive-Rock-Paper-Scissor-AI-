#ifndef STAT_ANALYSIS_H
#define STAT_ANALYSIS_H

# include <vector>
# include <list>
# include <iostream>
# include <string>
# include <cmath>
#include <new>
#include <memory>
# include "Global_Constants.h"
# include "OutcomeGen.h"
# include "History.h"

class Stat : public History
	//Stat has access to outcomegen and history. It contains statistical tools that combines the two later classes and is used by several schemes.
{
public:
	Stat();
	Stat(int steps, double beta, int compare = -2);

	size_t getIndexO(int mode, bool player1 = 1, std::string type = "WLD");
	void updatestats(bool player1 = true, std::string type = "WLD");
	void getInfo();
	OutcomeGenerator outcomes;
private:
	double beta;
	int numberofsteps;
	int comparewith; 
};


//Implementations

Stat::Stat() : numberofsteps(1), outcomes(numberofsteps) {};
Stat::Stat(int steps, double value, int compare) : numberofsteps(steps), beta(value), outcomes(steps), comparewith(compare) {};

size_t Stat::getIndexO(int mode, bool player1, std::string type) // generate the index of the latest outcome string being played by opponent. When mode 1 is applied, the string is displaced by 1 position
{
	/*When this function is called, it returns the index of history::vector<DataStorage*> possibilitystorage that correctly correspond to the based on the win-loss-draw pattern of the opponent and numberofsteps. 
	See documentation for an example */
	size_t result = 0;
	for (int i = 0; i < numberofsteps; i++) {
		int index = movehistory.size() - i - 1;
		if (mode != 0) {
			index = movehistory.size() - 2 - i;
		}
		if (type != "WLD") {
			if (index < 0) {
				throw "Exception";
			}
			int move = movehistory[index][player1];
			result = result + (size_t)move*pow(3, i);
		}
		else {
			int move = statushistoryO[index];
			if (player1 != true) {
				move = statushistoryS[index];
			}
			if (move == 'W') {
				result = result + (size_t)0 * pow(3, i);
			}
			else if (move == 'L') {
				result = result + (size_t)1 * pow(3, i);
			}
			else {
				result = result + (size_t)2 * pow(3, i);
			}
		}
	}
	//Debugging code std::cout << "\NResult: " << result;
	return result;
}
void Stat::updatestats(bool player1, std::string type) {
	/*Takes at the move being played last,  
	compares it with the comparewith-th move played by the opponent (by default second last move) and apply by using function history::compare(player, -1, comparewith) discussed earlier. 
	Update the stats the -1, 0, +1 odds of outcomegen:: possibilitystorage vector. Uses the learning formula to find new odds,  
	size_t getIndexO() to find the appropriate index to update and outcomegen’s set function to modify the values of each -1,0, +1 odds.*/
	size_t indexlocation = getIndexO(1, player1, type);
	char player = 'o';
	if (player1 != true) {
		player = 's';
	}
	int status;
	if (type == "WLD") {
		int compare = History::compare(player, -1, comparewith);
		//std::cout << "\nIndex location: " << indexlocation;
		//std::cout << "\nComparewith: " << comparewith;
		if (compare == -1) {
			double oldm1 = outcomes.get('m', indexlocation);
			double newm1 = learningformulat(oldm1, beta);
			double difference = newm1 - oldm1;
			outcomes.set('m', indexlocation, newm1);
			outcomes.set('0', indexlocation, outcomes.get('0', indexlocation) - difference / 2);
			outcomes.set('1', indexlocation, outcomes.get('1', indexlocation) - difference / 2);
			outcomes.setdatasize(indexlocation, outcomes.getdatasize(indexlocation) + 1);
			//std::cout << "\n-1: : " << outcomes.get('m', indexlocation);

		}
		else if (compare == 0) {
			double old0 = outcomes.get('0', indexlocation);
			double new0 = learningformulat(old0, beta);
			double difference = new0 - old0;
			outcomes.set('0', indexlocation, new0);
			outcomes.set('m', indexlocation, outcomes.get('m', indexlocation) - difference / 2);
			outcomes.set('1', indexlocation, outcomes.get('1', indexlocation) - difference / 2);
			outcomes.setdatasize(indexlocation, outcomes.getdatasize(indexlocation) + 1);
			//std::cout << "\n0: : " << outcomes.get('0', indexlocation);

		}
		else {
			double old1 = outcomes.get('1', indexlocation);
			double new1 = learningformulat(old1, beta);
			double difference = new1 - old1;

			outcomes.set('1', indexlocation, new1);
			outcomes.set('0', indexlocation, outcomes.get('0', indexlocation) - difference / 2);
			outcomes.set('m', indexlocation, outcomes.get('m', indexlocation) - difference / 2);
			outcomes.setdatasize(indexlocation, outcomes.getdatasize(indexlocation) + 1);
			//std::cout << "\n1: : " << outcomes.get('1', indexlocation);

		}
	}
	else {
		int OpponentNewMove = H(player, -1, 0);
		if (OpponentNewMove == 0) {
			double oldm1 = outcomes.get('R', indexlocation);
			double newm1 = learningformulat(oldm1, beta);
			double difference = newm1 - oldm1;
			outcomes.set('R', indexlocation, newm1);
			outcomes.set('P', indexlocation, outcomes.get('0', indexlocation) - difference / 2);
			outcomes.set('S', indexlocation, outcomes.get('1', indexlocation) - difference / 2);
			outcomes.setdatasize(indexlocation, outcomes.getdatasize(indexlocation) + 1);
			//std::cout << "\n-1: : " << outcomes.get('m', indexlocation);

		}
		else if (OpponentNewMove == 1) {
			double old0 = outcomes.get('P', indexlocation);
			double new0 = learningformulat(old0, beta);
			double difference = new0 - old0;
			outcomes.set('P', indexlocation, new0);
			outcomes.set('m', indexlocation, outcomes.get('m', indexlocation) - difference / 2);
			outcomes.set('1', indexlocation, outcomes.get('1', indexlocation) - difference / 2);
			outcomes.setdatasize(indexlocation, outcomes.getdatasize(indexlocation) + 1);
			//std::cout << "\n0: : " << outcomes.get('0', indexlocation);

		}
		else {
			double old1 = outcomes.get('S', indexlocation);
			double new1 = learningformulat(old1, beta);
			double difference = new1 - old1;

			outcomes.set('S', indexlocation, new1);
			outcomes.set('0', indexlocation, outcomes.get('0', indexlocation) - difference / 2);
			outcomes.set('m', indexlocation, outcomes.get('m', indexlocation) - difference / 2);
			outcomes.setdatasize(indexlocation, outcomes.getdatasize(indexlocation) + 1);
			//std::cout << "\n1: : " << outcomes.get('1', indexlocation);
		}
	}
}
void Stat::getInfo() {
	outcomes.getInfo();
}

#endif // !STAT_ANALYSIS_H