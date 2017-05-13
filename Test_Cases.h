#ifndef TEST_CASES_H
#define TEST_CASES_H

# include <iostream>
# include "Scheme_1.h"
# include "Scheme_2.h"
# include "Scheme_3.h"
# include "Global_Constants.h"
# include "History.h"
# include "OutcomeGen.h"
# include "Stat_Analysis.h"
# include "Scheme_AdvanceStats.h"
# include "Player_Manager.h"
# include <random>
# include <cmath>
# include "Scheme_AdvanceStats2.h"

using namespace std;

void case1(bool value, int choice, bool cheat = false) {
	// contains all test cases
	int opp;
	if (choice == 1) {
		opp = rand() % 3;
	}
	
	Scheme_2 B(false);
	Scheme_1 C;
	Player_Manager D(false);
	Scheme_2 E(true);

	int win = 0;
	int loss = 0;
	int draw = 0;
	Player_Manager A;
	History History;

	bool print = value;
	if (choice == 11) {
		History.newMove(0, 0);
	}
	for (int i = 0; i < 1000; i++) {
		int self = 0;
		if (choice != 11) {
			self = A.nextMove();
		}
		if (cheat == true) {
			cout << "\nNext move AI will play: " << self;
		}
		if (choice == 2) {
			opp = (i*2+i*3) % 3;
		}
		if (choice == 3) {
			opp = B.nextMove();
		}
		if (choice == 4) {
			opp = C.nextMove();
		}
		if (choice == 5) {

			if (i % 3 == 0) {
				opp = (1000 - i) % 3;
			}
			else if (i % 3 == 1) {
				opp = i % 3;
			}
			else {
				opp = 0;
			}
		}
		if (choice == 6) {
			opp = D.nextMove();
		}
		if (choice == 10) {
			cout << "\nPlease enter your move [0 - Rock] [1 - Paper] [2- scissor] [-1 to Exit]: ";
			while (!(cin >> opp))
			{
				throw "exception";
			}
			while (opp > 2 || opp < -1) {
				cout << "\nPlease enter a valide move";
				cin >> opp;
			}
			std::cout << "\nD: " << draw << "\nW: " << win << "\nL: " << loss << std::endl;
		}

		if (choice == 11) {
			self = E.nextMove();
			cout << "\nPlease enter your move [0 - Rock] [1 - Paper] [2- scissor] [-1 to Exit]: ";
			while (!(cin >> opp))
			{
				throw "exception";
			}
			while (opp > 2 || opp < -1) {
				cout << "\nPlease enter a valide move";
				cin >> opp;
			}
			std::cout << "\nD: " << draw << "\nW: " << win << "\nL: " << loss << std::endl;
		}


		if (choice == 20) {
			opp = 0;

		}

		if (choice == 21) {
			if (i % 2 == 0) {
				opp = 0;
			}
			else {
				opp = 1;
			}
		}


		if (opp == -1) {
			break;
		}

		History.newMove(self, opp);
		if (print == true) {
			std::cout << "\n\nRound " << i;
		}
		if (self == 0 && print == true) {
			std::cout << "\nPlayer_Manager plays: Rock";
		}
		else if (self == 1 && print == true) {
			std::cout << "\nPlayer_Manager plays: Paper";
		}
		else if (print == true) {
			std::cout << "\nPlayer_Manager plays: Scissor";
		}

		if (opp == 0 && print == true) {
			std::cout << "\nOpponent plays: Rock";
		}
		else if (opp == 1 && print == true) {
			std::cout << "\nOpponent plays: Paper";
		}
		else if (print == true) {
			std::cout << "\nOpponent plays: Scissor";
		}

		if (History.statushistoryO[History.getSize() - 1] == 'D') {
			draw++;
			if (print == true) {
				std::cout << "\nIt's a draw!";
			}
		}
		else if (History.statushistoryO[History.getSize() - 1] == 'L') {
			win++;
			if (print == true) {
				std::cout << "\nPlayer_Manager won!";
			}
		}
		else if (History.statushistoryO[History.getSize() - 1] == 'W') {
			loss++;
			if (print == true) {
				std::cout << "\nPlayer_Manager lost!";
			}
		}

	}
	std::cout << "\nConsensus total: " << A.consensusCounter;
	std::cout << "\nIndividual schemes total: " << A.individualSchemeCounter;
	std::cout << "\nD: " << draw << "\nW: " << win << "\nL: " << loss << std::endl;

}


#endif // !TEST_CASES_H

