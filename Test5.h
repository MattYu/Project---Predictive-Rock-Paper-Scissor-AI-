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
void test5() {
	History History;
	Player_Manager A;
	for (int i = 0; i < A.next.size(); i++) {
		A.next[i] = 0;
	}
	History.newMove(0, 2);
	A.updatestat();
	A.getOdds();

}
