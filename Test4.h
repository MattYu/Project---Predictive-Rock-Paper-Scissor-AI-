#pragma once
//Unit testing. Included in test_cases.h
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

using namespace std;
void test4() {
	int win = 0;
	int loss = 0;
	int draw = 0;
	int random = 0;
	Player_Manager A(true,0.30,50);
	History History;
	Scheme_Stats C(false);
	Scheme_2 B(true);
	for (int i = 0; i < 1000; i++) {
		int me = A.nextMove();
		int opp;
		if (i < 3) {
			opp = rand() % 3;
		}
		else {
			opp = C.nextMove();
		}
		if (opp < 0) {
			opp = rand() % 3;
			random++;
		}
		//cout << endl << endl;
		/*if (me == 0){
		cout << "S:Rock ";
		}
		else if (me == 1)
		cout << "S:Paper ";
		else {
		cout << "S:Scissor ";
		}
		if (opp == 0){
		cout << "S:Rock ";
		}
		else if (opp == 1)
		cout << "O:Paper ";
		else {
		cout << "O:Scissor ";
		}
		cout << endl;*/

		History.newMove(me, opp);
		//cout << "Consensus: " << A.next[0];
		//cout << "\nOddsWin: " << A.OddsW[0];
		//cout << "\nD: " << draw << "\nW: " << win << "\nL: " << loss;

		if (History.statushistoryO[History.getSize() - 1] == 'D') {
			draw++;
		}
		else if (History.statushistoryO[History.getSize() - 1] == 'L') {
			win++;
		}
		else if (History.statushistoryO[History.getSize() - 1] == 'W') {
			loss++;
		}

	}
	cout << "\nConsensus total: " << A.consensusCounter;
	cout << "\nIndividual schemes total: " << A.individualSchemeCounter;
	cout << "\nRandom: " << random;

	cout << "\nD: " << draw << "\nW: " << win << "\nL: " << loss << endl;


}
