#ifndef SCHEME_1_H
#define SCHEME_1_H

#include <random>
#include <iostream>
# include "Global_Constants.h"
# include "RPSPlayer.h"


class Scheme_1: public RPSPlayer {
public:
	//uses a random engine and uniform distribution to ensure a closer to true random generator
	Scheme_1(){}
	int nextMove() {
		return getRandom();
	}
	int getRandom() {
		std::default_random_engine e1(r());
		std::uniform_int_distribution<int> uniform_dist(0, 2);
		int rand = uniform_dist(e1);
		if (rand == 0) {
			return 0;
		}
		else if (rand == 1) {
			return 1;
		}
		else {
			return 2;
		}
	}
protected:
	std::random_device r;
};


#endif // !SCHEME_1_H
