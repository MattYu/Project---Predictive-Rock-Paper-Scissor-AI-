#ifndef SCHEME_3_H
#define SCHEME_3_H

# include <iostream>
# include "Global_Constants.h"
# include "history.h"
# include "Stat_Analysis.h"

class Scheme_Stats: public RPSPlayer, public Stat
{
public:
	Scheme_Stats():player1(true), minimumsteps(1), threshold(40), beta(0.1), Stat(1,0.2) {};
	Scheme_Stats(bool player, double beta = 0.1) :player1(player), minimumsteps(1), threshold(40), beta(beta), Stat(1, 0.2) {};
	int nextMove() {
		return getNext();
	}

	int getNext() {
		
		if ( count >= minimumsteps) {
			char player = 'o';
			if (player1 == false) {
				player = 's';
			}
			int result = -10;
			Stat::updatestats(player1);
			size_t outcome_position = getIndexO(0, player1);
			double Rm1 = outcomes.get('m', outcome_position);
			double P0 = outcomes.get('0', outcome_position);
			double S1 = outcomes.get('1', outcome_position);
			if (Rm1 >= threshold && Rm1 > P0 && Rm1 >S1) {
				result = -1;
			}
			else if (P0 >= threshold && P0 > Rm1 && P0 > S1) {
				result = 0;
			}
			else if (S1 >= threshold && S1 > Rm1 && S1 > P0) {
				result = 1;
			}
			else {
				return -30;
			}

			result = History::H(player, compared_with, result);
			result = result + 1;
			History::convert(result);
			count++;
			return result;
		}
		else {
			count++;
			return -20;
		}
	}
	void getInfo() {
		Stat::getInfo();
	}
private:
	int minimumsteps;
	int count = 0;
	double threshold;
	bool player1 = true;
	int compared_with = -1;
	double beta;

};

#endif
