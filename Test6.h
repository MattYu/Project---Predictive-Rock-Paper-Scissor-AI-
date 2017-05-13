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
# include "Scheme_AdvanceStats2.h"

using namespace std;
void test6(bool value) {
	int win = 0;
	int loss = 0;
	int draw = 0;
	Player_Manager A;
	//Scheme_Stats A;
	History History;
	History.newMove(0, 0);
	int opp2 = 0;
	bool print = value;
	for (int i = 0; i < 10000; i++) {
		int self = A.nextMove();
		if (self < 0) {
			self = rand() % 3;
		}
		int opp = 0;
		if (i % 3 == 0) {
			opp = (i-1)%3;
		}
		else if (i % 2 == 0) {
			opp = (1000 - i) % 3;
		}
		else {
			opp = i % 3;
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
		else if (print == true){
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
	std::cout << "\nD: " << draw << "\nW: " << win << "\nL: " << loss << endl;


}


void test7() {
	int win = 0;
	int loss = 0;
	int draw = 0;
	int random = 0;
	Player_Manager A;
	History History;
	//Scheme_Stats C(false, 0.6);
	History.newMove(0, 0);
	for (int i = 0; i < 1000; i++) {
		int opp = A.nextMove();
		int me;
		cout << "\nPlay your move: ";
		cin >> me;
		if (opp == 0) {
			cout << "\nOpponent plays rock";
		}
		else if (opp == 1) {
			cout << "\nOpponent plays paper";
		}
		else {
			cout << "\nOpponent plays scissor";
		}

		if (me == 0) {
			cout << "\nYou played rock";
		}
		else if (me == 1) {
			cout << "\nYou played paper";
		}
		else if (me == 2){
			cout << "\nYou played scissor";
		}
	else {
		cout << "\nInvalid move. Try again: ";
		cin >> me;
	}
		History.newMove(opp, me);

		if (History.statushistoryO[History.getSize() - 1] == 'D') {
			draw++;
		}
		else if (History.statushistoryO[History.getSize() - 1] == 'L') {
			win++;
		}
		else if (History.statushistoryO[History.getSize() - 1] == 'W') {
			loss++;
		}
		cout << "\nAI Draws: " << draw << "\nAI Wins: " << win << "\nAI Losses: " << loss << endl;

	}
	cout << "RANDOM: " << random;
	cout << "\nConsensus total: " << A.consensusCounter;
	cout << "\nIndividual schemes total: " << A.individualSchemeCounter;
	cout << "\nD: " << draw << "\nW: " << win << "\nL: " << loss << endl;


}