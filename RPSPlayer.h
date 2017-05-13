#ifndef RPSPlAYER_H
#define RPSPlAYER_H

#include <random>
#include <iostream>
# include "Global_Constants.h"

# include "History.h"

class RPSPlayer {
	// pure virtual class grouping all schemes
public:
	virtual int nextMove() = 0;

};


#endif // !SCHEME_1_H
