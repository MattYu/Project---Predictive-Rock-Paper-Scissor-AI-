# pragma once

// This header files holds some values that can be used by the entire program

enum Move { Rock, Paper, Scisor };

double beta01 = 0.01;
double beta05 = 0.05;
double beta10 = 0.10;
double beta20 = 0.20;
double beta30 = 0.30;
double beta50 = 0.50;


double learningformulat(double value, double beta) {
	//takes a value and a beta, returns new value ajusted by beta as per definition of learning formula
	double result = value*(1 - beta) + 100 * beta;
	return result;
}

