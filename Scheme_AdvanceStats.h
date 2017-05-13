#ifndef SCHEME_ADVANCESTATS_H
#define SCHEME_ADVANCESTATS_H

# include <iostream>
# include "Global_Constants.h"
# include "history.h"
# include "Stat_Analysis.h"

class Scheme_AStats : public RPSPlayer, public Stat
{
	//refer to documentation for more details
public:
	Scheme_AStats() :player1(true), minimumsteps(1), threshold(40), beta(0.2), Stat(1, 0.2) {};
	Scheme_AStats(bool player) :player1(player), minimumsteps(1), threshold(40), beta(0.2), Stat(1, 0.2), compared_with(-2) {};
	Scheme_AStats(bool player1, int minimumsteps, double threshold, double beta, int comparewith) : Stat(minimumsteps, beta, comparewith),player1(player1), minimumsteps(minimumsteps), threshold(threshold), beta(beta), compared_with(comparewith) {};

	int nextMove() {
		return getNext();
	}

	int getNext() {
		/*First checks whether its player1 playing or not. If not, history is reversed.
		If the number of round played is below the minimumsteps (= to total numbers of steps to look back, returns -10 since outcomegen requires more data to be used.
		Else{
		Calls updatestates described in section above to update the -1,0,+1 odds for the given outcome last played.
		Checks the odds for the current outcome. 
		Based on this, sees which outcome -1,0,+1 has the highest probability to be played next. Calls History::H(player1 or not, step to compare with, mostlikelyoutcome found) to get the moved most likely to be played by opponent next based on the most likely -1,0,+1. Returns the move that beats the last. 
		*/
		if (count >= minimumsteps) {
			char player = 'o';
			if (player1 == false) {
				player = 's';
			}
			int result = -10;
			Stat::updatestats(player1);
			size_t outcome_position = getIndexO(0, player1);
			//std::cout << "\nOutcome_position = " << outcome_position << std::endl;
			double Rm1 = outcomes.get('m', outcome_position);
			//std::cout << "Rm1 = " << Rm1 << std::endl;
			double P0 = outcomes.get('0', outcome_position);
			//std::cout << "P0 = " << P0 << std::endl;
			double S1 = outcomes.get('1', outcome_position);
			//std::cout << "S1 = " << S1 << std::endl;
			if (Rm1 >= threshold && Rm1 > P0 && Rm1 >S1) {
				//std::cout << "Rm1 chosen = " << Rm1 << std::endl;
				result = -1;
			}
			else if (P0 >= threshold && P0 > Rm1 && P0 > S1) {
				//std::cout << "P0 chosen= " << P0 << std::endl;
				result = 0;
			}
			else if (S1 >= threshold && S1 > Rm1 && S1 > P0) {
				//std::cout << "S1 chosen= " << S1 << std::endl;
				result = 1;
			}
			else {
				return -10;
			}

			result = History::H(player, compared_with+1, result);
			result = result + 1;
			History::convert(result);
			count++;
			return result;
		}
		else {
			count++;
			return -10;
		}
	}
	void getInfo() {
			Stat::getInfo();
	}
private:
	int minimumsteps;
	int count = 0;
	double threshold;
	bool player1;
	int compared_with;
	double beta;

};

#endif