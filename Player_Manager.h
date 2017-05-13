#ifndef PLAYER_MANAGER_H
#define PLAYER_MANAGER_H


# include <fstream>
# include <iostream>
# include <vector>
# include "RPSPlayer.h"
# include "Scheme_1.h"
# include "Scheme_2.h"
# include "Scheme_3.h"
# include "Scheme_AdvanceStats.h"
# include "Scheme_AdvanceStats2.h"
# include "History.h"
# include "Scheme_4.h"

class Player_Manager {
public:
	//Implementation and member description found below in this same h file
	Player_Manager();
	Player_Manager(bool player1, double beta = 0.25, double threshold = 45);
	// creates a player manager with the value parameters 
	int nextMove();
	// outputs the next move
	int findBestScheme();
	// finds the best individual schemes and returns the index of it
	void updatestat();
	// update states. Call upon each round
	void getOdds();

	
	std::vector<int> next;
	std::vector<double> OddsW;
	std::vector<double> OddsL;
	std::vector<double> OddsD;
	int consensusCounter;
	int individualSchemeCounter;

private:
	bool consensus;
	bool individualscheme;
	bool random;
	bool ahp;


	std::vector<RPSPlayer*> Schemes;
	History History;
	double lastmoveW;
	double lastmoveD;
	double lastmoveL;
	
	double beta;
	double threshold;
	int count;
	bool player1;
	int result = 0;
	double resultWinOdds;
	
	Scheme_1 S1;
	Scheme_2 S2;
	Scheme_Stats S3;
	Scheme_Stats S4;
	Scheme_Stats S5;
	Scheme_AStats S6;
	Scheme_AStats S7;
	Scheme_AStats S8;
	Scheme_AStats S9;
	Scheme_AStats S10;
	Scheme_AStats S11;
	Scheme_AStats S12;
	Scheme_AStats S13;
	Scheme_AStats S14;
	Scheme_4 S15;

	std::ofstream Result;
	std::ofstream Consensus;
	std::ofstream ConsensusNumber;
	std::ofstream IndividualScheme1;
	std::ofstream IndividualSchemeCounter;
	std::ofstream RandomScheme1;

};



//Implementation
Player_Manager::Player_Manager() : Player_Manager(true) {}
Player_Manager::Player_Manager(bool player1, double beta, double threshold) :
	player1(player1), count(0), consensusCounter(0), individualSchemeCounter(0), beta(beta), lastmoveW(33.333), threshold(threshold), S2(player1), S3(player1), S4(player1, 0.2), S5(player1, 0.15), S6(player1, 2, 45, 0.25, -2), S7(player1, 2, 40, 0.25, -2),
	S8(player1, 2, 50, 0.3, -2), S9(player1, 2, 45, 0.15, -3), S10(player1, 2, 40, 0.23, -3), S11(player1, 3, 45, 0.25, -2), S12(player1, 3, 45, 0.20, -3), S13(player1, 3, 45, 0.30, -4),
	S14(player1, 4, 45, 0.30, -2), S15(), ahp(false)


	//Player manager initializes all 15 schemes with different beta values, step backs, etc. It also initializes the win, loss and draw odds to 33.333% and the csv files for stat data outputting. 

{
	double initialOdds = 33.333;
	for (int i = 0; i < 16; i++) {
		OddsW.push_back(initialOdds);
		OddsL.push_back(initialOdds);
		OddsD.push_back(initialOdds);
	}
	for (int i = 0; i < 16; i++) {
		next.push_back(-10);
	}

	Schemes.push_back(&S1);
	Schemes.push_back(&S2);
	Schemes.push_back(&S3);
	Schemes.push_back(&S4);
	Schemes.push_back(&S5);
	Schemes.push_back(&S6);
	Schemes.push_back(&S7);
	Schemes.push_back(&S8);
	Schemes.push_back(&S9);
	Schemes.push_back(&S10);
	Schemes.push_back(&S11);
	Schemes.push_back(&S12);
	Schemes.push_back(&S13);
	Schemes.push_back(&S14);
	Schemes.push_back(&S15);

	Result.open("Result.csv");
	Consensus.open("Consensus.csv");
	ConsensusNumber.open("ConsensusCount.csv");

	IndividualScheme1.open("IndividualScheme.csv");
	IndividualSchemeCounter.open("IndividualSchemeCounter.csv");
	RandomScheme1.open("RandomScheme1.csv");

}

int Player_Manager::nextMove() {
	/*Each scheme, out of the 15 total schemes,
	generates 1 prediction per round (Rock, paper or scissor) and the most overwhelmingly common majority prediction is used as the next move to be played.
	In the absence of a majority consensus from the system or if previous swarm consensus did not result in sufficient victories, the most overwhelmingly successful individual scheme out of the 15 schemes
	is used to predict the next game move to be played. Lastly, in the absence of an overwhelmingly successful scheme, a random move is picked to be played.*/
	//stat tracking values are also added to their respective csv files here

	// if AHP scheme is very successful, will cout a message saying "I am playing against an average human" once
	consensus = false;
	individualscheme = false;
	random = true;
	if (OddsW[2] > 80 && (count > 30) && (count < 100) && ahp == false) {
		ahp = true;
		std::cout << "\nI am playing against an average human player!!!\n";
	}

	if (count > 0) {
		updatestat();
	}
	if (count > 20 && count % 100 == 0 && player1 == true) {
		History::clearEverythingBut(10);
		//performs memory housekeeping every 100 moves to clears all uncessary memory spaces except the last 10 moves.
		//only player1 can perform this.
	}
	count++;
	int rock1 = 0;
	int paper1 = 0;
	int scissor1 = 0;
	next[0] = -7;
	if (count < 2) {
		for (int i = 1; i < 2; i++) {
			int newmove = Schemes[i]->nextMove();
			next[i] = newmove;
		}
	}
	else {
		for (int i = 1; i <next.size(); i++) {
			int newmove = Schemes[i - 1]->nextMove();
			next[i] = newmove;
		}
	}

	int result = next[1]; //default newMove is random. If conditions described above are meet, it will be changed to a better move
	for (int i = 1; i < next.size(); i++) {
		if (next[i] == 0) {
			rock1++;
			//std::cout << "rock " << rock1;
		}
		else if (next[i] == 1) {
			paper1++;
		}
		else if (next[i] == 2) {
			scissor1++;
		}
	}
	if (rock1 > paper1 && rock1 > scissor1) {
		next[0] = 0;
		//std::cout << "n0";
	}
	else if (paper1 > rock1 && paper1 > scissor1) {
		next[0] = 1;
		//std::cout << "n1";
	}
	else if (scissor1 > rock1 && scissor1 > paper1) {
		next[0] = 2;
		//std::cout << "n2";

	}

	if ((rock1 > 8 || paper1 > 8 || scissor1 > 8) && OddsW[0] > threshold && lastmoveW > threshold) {
		result = next[0];
		individualscheme = false;
		//std::cout << "Consensus being played";
		consensusCounter++;
		random = false;
		consensus = true;
		Consensus << 1 << ",";

		for (int i = 1; i < 16; i++) {
			if (next[i] == next[0]) {
				ConsensusNumber << i << ",";
			}
		}
	}
	else if (OddsW[findBestScheme()] > threshold && lastmoveW >threshold) {
		individualscheme = true;
		random = false;
		IndividualScheme1 << 1 << ",";
		IndividualSchemeCounter << findBestScheme() << ",";
		result = next[findBestScheme()];
		std::cout << "\nIndividual scheme picked: " << findBestScheme();
		individualSchemeCounter++;
	}

	if (consensus == false) {
		Consensus << ",";
		for (int i = 1; i < 16; i++) {
			ConsensusNumber << -10 << ",";
		}
	}
	if (individualscheme == false) {
		IndividualScheme1 << ",";
		IndividualSchemeCounter << -10 << ",";
	}
	if (random == true) {
		RandomScheme1 << 1 << ",";
	}
	else if (random !=true) {
		RandomScheme1 << ",";
	}
	if (result < 0) {
		result = S1.getRandom();
		RandomScheme1 << 1 << ",";
	}

	return result;
}

int Player_Manager::findBestScheme() {
	//returns the index of the best performing scheme for next vector. The simplest, best performing scheme is return first. (vector next stores schemes in order of increasing complexity)
	double highest_WinOdds = 0;
	double highest_Index = 1; // default value is the index of random
	for (int i = 1; i < OddsW.size(); i++) {
		if (OddsW[i] > highest_WinOdds) {
			highest_WinOdds = OddsW[i];
			highest_Index = i;
		}
	}

	return highest_Index;
}

void Player_Manager::updatestat() {
	/*Compares the last move made by each scheme and the move played by the opponent to find if it's a loss-win-or-loss and then Update the Win-Loss-Draw odds of the respective scheme in vector "next" based on the learning formula*/
	/*Note1: if a scheme could not return the best next move (confidence level of the scheme below given threshold, insuffisiant data acquired, etc. -10 is return as the next move
	In this case: The move is arbitrarily consider a Draw but updated with a small beta of 0.02. This is because I want to discourage the system from using a successful but rarely used scheme
	Note2: the first index of next ([0]) always correspond to the move of the swarm consensus and is not associated with an individual scheme*/

	char lastresult = History.statushistoryS[History.statushistoryS.size() - 1];
	if (player1 != true) {
		lastresult = History.statushistoryO[History.statushistoryO.size() - 1];
	}
	if (lastresult == 'W') {
		result++;
		Result << result << ",";
		double oldOddsW = lastmoveW;
		double newOddsW = learningformulat(oldOddsW, 0.35);
		double difference = newOddsW - oldOddsW;
		lastmoveW = newOddsW;
		lastmoveD = lastmoveD - difference / 2;
		lastmoveL = lastmoveL - difference / 2;
	}
	else if (lastresult == 'D') {
		Result << result << ",";
		double oldOddsD = lastmoveD;
		double newOddsD = learningformulat(oldOddsD, 0.35);
		double difference = newOddsD - oldOddsD;
		lastmoveD = newOddsD;
		lastmoveW = lastmoveW - difference / 2;
		lastmoveL = lastmoveL - difference / 2;
	}
	else {
		result--;
		Result << result << ",";
		double oldOddsL = lastmoveL;
		double newOddsL = learningformulat(oldOddsL, 0.35);
		double difference = newOddsL - oldOddsL;
		lastmoveL = newOddsL;
		lastmoveW = lastmoveW - difference / 2;
		lastmoveD = lastmoveD - difference / 2;
	}

	int opponent = History.H(player1, -1, 0);
	for (int i = 0; i < next.size(); i++) {
		int self = next[i];
		int difference = self - opponent;
		if (self < 0) {
			double oldOddsD = OddsD[i];
			double newOddsD = learningformulat(oldOddsD, 0.02);
			double difference = newOddsD - oldOddsD;
			OddsD[i] = newOddsD;
			OddsW[i] = OddsW[i] - difference / 2;
			OddsL[i] = OddsL[i] - difference / 2;
		}
		else if (self == 2 && opponent == 0) {
			double oldOddsL = OddsL[i];
			double newOddsL = learningformulat(oldOddsL, beta);
			double difference = newOddsL - oldOddsL;
			OddsL[i] = newOddsL;
			OddsW[i] = OddsW[i] - difference / 2;
			OddsD[i] = OddsL[i] - difference / 2;
		}
		else if (self == 0 && opponent == 2) {
			double oldOddsW = OddsW[i];
			double newOddsW = learningformulat(oldOddsW, beta);
			double difference = newOddsW - oldOddsW;
			OddsW[i] = newOddsW;
			OddsL[i] = OddsL[i] - difference / 2;
			OddsD[i] = OddsD[i] - difference / 2;
		}
		else if (difference == 0) {
			double oldOddsD = OddsD[i];
			double newOddsD = learningformulat(oldOddsD, beta);
			double difference = newOddsD - oldOddsD;
			OddsD[i] = newOddsD;
			OddsW[i] = OddsW[i] - difference / 2;
			OddsL[i] = OddsL[i] - difference / 2;
		}
		else if (difference > 0) {
			double oldOddsW = OddsW[i];
			double newOddsW = learningformulat(oldOddsW, beta);
			double difference = newOddsW - oldOddsW;
			OddsW[i] = newOddsW;
			OddsL[i] = OddsL[i] - difference / 2;
			OddsD[i] = OddsD[i] - difference / 2;
		}
		else {
			double oldOddsL = OddsL[i];
			double newOddsL = learningformulat(oldOddsL, beta);
			double difference = newOddsL - oldOddsL;
			OddsL[i] = newOddsL;
			OddsW[i] = OddsW[i] - difference / 2;
			OddsD[i] = OddsD[i] - difference / 2;
		}
	}
}
void Player_Manager::getOdds() {
	for (int i = 0; i < OddsW.size(); i++) {
		std::cout << "\nScheme #: " << i;
		std::cout << "\nWins: " << OddsW[i] << "\tLoss: " << OddsL[i] << "\tDraw: " << OddsD[i] << std::endl;
	}
}

#endif // !PLAYER_MANAGER_H
