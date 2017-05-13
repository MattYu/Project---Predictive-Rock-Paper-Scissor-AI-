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

using namespace std;

void test2() {
	Player_Manager A;
	History History;
	Scheme_2 C(false);
	Scheme_2 D(true);
	for (int i = 0; i < 50; i++) {
		cout << "\nMove: " << i << endl;
		History.newMove(D.nextMove(), C.nextMove());
	}
	/*int win = 0;
	int loss = 0;
	int draw = 0;
	History History;
	Scheme_2 C(false);
	Scheme_AStats B(true, 2, 45, 0.15, -3);
		for (int i = 0; i < 100000; i++) {
			if (i < 5)
			History.newMove(rand()%3, rand() % 3);
			else {
				int value = B.nextMove() % 3;
				if (value < 0) {
					value = value*-1;
				}
				History.newMove(value, C.nextMove());
			}
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
	cout << "\nD: " << draw << "\nW: " << win << "\nL: " << loss << endl;*/
	/*History A;
	Scheme_2 C(false);
	Scheme_2 D(true);
	Scheme_AStats2 B(true, 10, 45, 0.15);
	for (int i = 0; i < 50; i++) {
		cout << "\nMove: " << i << endl;
		A.newMove(D.nextMove(), C.nextMove());
		cout << B.nextMove();
	}*/
}