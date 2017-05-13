#ifndef SCHEME_ADVANCESTATS2_H
#define SCHEME_ADVANCESTATS2_H

//******NOT USED BY PLAYER_MANAGER. SEE DOCUMENTATION.***********





# include <iostream>
# include "Global_Constants.h"
# include "history.h"
# include "Stat_Analysis.h"
# include "RPSPlayer.h"

class Scheme_AStats2 : public RPSPlayer, public Stat
{
public:
	Scheme_AStats2() :player1(true), minimumsteps(1), threshold(40), beta(0.2), Stat(1, 0.2), type("RPS") {};
	Scheme_AStats2(bool player1, int minimumsteps, double threshold, double beta) : Stat(minimumsteps, beta), player1(player1), minimumsteps(minimumsteps), threshold(threshold), beta(beta), type("RPS") {};
	int nextMove() {
		return getNext();
	}

	int getNext() {

		if (count >= minimumsteps) {
			char player = 'o';
			if (player1 == false) {
				player = 's';
			}
			int result = -10;
			Stat::updatestats(player1, type);
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

			result = History::H(player, compared_with, result);
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
	std::string type;

};

#endif
