#ifndef SCHEME_4_H
#define SCHEME_4_H

# include <iostream>
# include "Global_Constants.h"
# include "history.h"
# include "Stat_Analysis.h"
# include "RPSPlayer.h"

class Scheme_4 : public RPSPlayer
{
	// effective against some scheme (e.g. scheme stats with random gen). Added to swarm mind in case it might be needed when playing against another AI
public:
	Scheme_4() {};
	int nextMove() {
		i++;
		return (i*i)%3;
	}

private:
	int i = 0;

};

#endif
