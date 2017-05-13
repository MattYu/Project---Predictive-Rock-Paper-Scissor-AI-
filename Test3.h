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
void test3(){
	int win = 0;
	int loss = 0;
	int draw = 0;
	Player_Manager A;
	//Scheme_Stats A;
	History History;
	Scheme_2 C(false);
	Scheme_2 B(true);
	History.newMove(0, 0);
	for (int i = 0; i < 10000; i++) {
		int me = A.nextMove();
		if (me < 0) {
			me = rand() % 3;
		}
		int j = i*i;
		int opp = C.nextMove();
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

		History.newMove(me, (i*i*i)%3);
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
cout << "\nD: " << draw << "\nW: " << win << "\nL: " << loss << endl; 


}