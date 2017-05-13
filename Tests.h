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

using namespace std;

void test() {
	/*OutcomeGenerator A(2);
	A.getInfo();
	A.set('m', 0, 0);

	cout << endl;
	A.getInfo();

	cout << endl << "Get: ";
	cout << A.get('m', 0);

	A.set('0', 1, 1);

	cout << endl;
	A.getInfo();
	cout << endl << "Get: ";
	cout << A.get('0', 1);


	A.set('1', 8, 2);

	cout << endl;
	A.getInfo();
	cout << endl << "Get: ";
	cout << A.get('1', 8);*/


	History A;
	Scheme_AStats B(true, 1, 40, 0.15, -2);
	B.getInfo();

	cout << "\n****************Move1\n";
	A.newMove(0, 2);
	cout << endl;
	A.getInfo();
	cout << "\nNext: " << B.getNext() << endl;
	B.getInfo();


	cout << "\n****************Move2\n";
	A.newMove(2, 1);
	cout << endl;
	A.getInfo();
	cout << "\nNext: " << B.getNext() << endl;
	B.getInfo();

	cout << "\n****************Move3\n";
	A.newMove(1, 0);
	cout << endl;
	A.getInfo();
	cout << "\nNext: " << B.getNext() << endl;
	B.getInfo();

	cout << "\n****************Move4\n";
	A.newMove(0, 2);
	cout << endl;
	A.getInfo();
	cout << "\nNext: " << B.getNext() << endl;
	B.getInfo();



	cout << "\n****************Move1\n";
	A.newMove(0, 0);
	cout << endl;
	A.getInfo();
	cout << "\nNext: " << B.getNext() << endl;
	B.getInfo();


	cout << "\n****************Move1\n";
	A.newMove(2, 2);
	cout << endl;
	A.getInfo();
	cout << "\nNext: " << B.getNext() << endl;
	B.getInfo();

	cout << "\n****************Move1\n";
	A.newMove(1, 1);
	cout << endl;
	A.getInfo();
	cout << "\nNext: " << B.getNext() << endl;
	B.getInfo();


	cout << "\n****************Move1\n";
	A.newMove(0, 0);
	cout << endl;
	A.getInfo();
	cout << "\nNext: " << B.getNext() << endl;
	B.getInfo();
}