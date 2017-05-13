#ifndef SCHEME_2_H
#define SCHEME_2_H

#include <iostream>
# include "Global_Constants.h"
# include "History.h"
# include "OutcomeGen.h"
# include "Scheme_1.h"


class Scheme_2: public RPSPlayer
{
public:
	//scheme 2 is selfsufficient and can be used on its own. 
	Scheme_2(): player1(true) {};
	Scheme_2(bool player) : player1(player) {};
	int nextMove() {
		char player = 'o';
		// when player1 is playing, opponent is 'o'. When player2 is playing, using the same code and history, opponent is mirrored 's' 
		
		if (History.statushistoryS.size() == 0 || History.statushistoryS[History.statushistoryS.size() - 1] == 'D') {
			return randomscheme.getRandom();
			//as indicated. In case of a draw in the last move. plays random next
		}
		else if (player1 == true) {
			int opponentNext;
			if (History.statushistoryO[History.statushistoryS.size() - 1] == 'L') {
				opponentNext = History.H(player, -1, -1);
			}
			else if (History.statushistoryO[History.statushistoryS.size() - 1] == 'W'){
				opponentNext = History.H(player, -1, 1);
			}
			int next = opponentNext + 1;
			History.convert(next);
			return next;
		}
		else {
				player = 's';
				int opponentNext;
				if (History.statushistoryS[History.statushistoryS.size() - 1] == 'L') {
					opponentNext = History.H(player, -1, -1);
				}
				else if (History.statushistoryS[History.statushistoryS.size() - 1] == 'W') {
					opponentNext = History.H(player, -1, 1);
				}
				int next = opponentNext + 1;
				History.convert(next);
				return next;
		}

	}
	History History;
	Scheme_1 randomscheme;
	int minimum_moves = 1;
	bool player1;
};


#endif // !SCHEME_1_H
