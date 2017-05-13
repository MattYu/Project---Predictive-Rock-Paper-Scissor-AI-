#ifndef  OUTCOMEGEN_H
#define OUTCOMEGEN_H
# include <vector>
# include <list>
# include <iostream>
# include <string>
# include <cmath>
#include <new>
#include <memory>
# include "Global_Constants.h"
# include "History.h"
# include <iomanip>

class DataStorage {
	//stores statistic data for a given outcome such chances of playing a -1, 0, or 1
protected:
	std::string id;
	double Rm1{ 33.33333 };
	double P0{ 33.33333 };
	double S1{ 33.33333 };
	int datasize = 0;
public:
	DataStorage(std::string id) {
		this->id = id;
	}
	DataStorage() {}
	void getInfo() {
		std::cout << std::setprecision(4) << std::endl<< id << "\t-1/R: " << Rm1 << "  0/P: " << P0 << "  1/S: " << S1;
	}
	void changeIDChar(int index, char character) {
		id[id.size() - 1 - index] = character;
	}
	void setRm1(double value) {
		Rm1 = value;
	}
	double getRm1()const {
		return Rm1;
	}
	void setP0(double value) {
		P0 = value;
	}
	double getP0()const {
		return P0;
	}
	void setS1(double value) {
		S1 = value;
	}
	double getS1()const {
		return S1;
	}
	void setdatasize(int value) {
		datasize = value;
	}
	int getdatasize()const {
		return datasize;
	}
	std::string getId() {
		return id;
	}
};

class OutcomeGenerator: public DataStorage
{

public:
	OutcomeGenerator();
	OutcomeGenerator(int a);
	// generates the total set of all outcomes a steps back. Sets the default odds to 33.333% for all. 
	~OutcomeGenerator();
	// deletes all dynamically generated 
	void generate(int numberofsteps);

	void getInfo();
	void setwR(size_t index, double wR);
	// set the odds values for -1 at the specified index 
	double getwR(size_t index)const;
	void setlP(size_t index, double value);
	double getlP(size_t index)const;
	// set the odds value for 0 at the specified index 
	void setdS(size_t index, double value);
	double getdS(size_t index)const;
	// set the odds value for +1 at the specified index 
	void setdatasize(size_t index, int value);
	int getdatasize(size_t index)const;
	void set(char type, size_t index, double value);
	// combines all the set fnc together with char type to control which one
	double get(char type, size_t index);
	// combines all the get fnc together with char type to control which one


private:
	std::vector<DataStorage*> possibilitystorage;
};



//Implementations

OutcomeGenerator::OutcomeGenerator() {

}
OutcomeGenerator::OutcomeGenerator(int a) {
	generate(a);
}
OutcomeGenerator::~OutcomeGenerator() {
	std::cout << "Destructor runs" << std::endl;
	for (int i = 0; i < (int)possibilitystorage.size(); i++) {
		delete possibilitystorage[i];
	}
	possibilitystorage.clear();
}
void  OutcomeGenerator::generate(int numberofsteps) {
	try {
		if (numberofsteps > 11) {
			throw "CPUoverload";
		}
		std::cout << "\n\t[Please wait. System is generating possible outcome combinations up to " << numberofsteps << " steps ...]" << std::endl;
		std::string w = "w";
		for (int i = 0; i < numberofsteps - 1; i++) {
			w = w + "w";
		}
		for (int j = 0; j < pow(3.0, numberofsteps); j++) {
			possibilitystorage.push_back(new DataStorage(w));
		}
		int counter3 = 0;
		for (int k = 0; k < numberofsteps; k++) {
			for (int i = 0; i < (int)possibilitystorage.size(); i++) {
				if (counter3 < pow(3, k)) {
					counter3++;
				}
				else if (counter3 < pow(3, k) * 2) {
					counter3++;
					possibilitystorage[i]->changeIDChar(k, 'l');
				}
				else if (counter3 < pow(3, k) * 3 - 1) {
					counter3++;
					possibilitystorage[i]->changeIDChar(k, 'd');

				}
				else {
					counter3 = 0;
					possibilitystorage[i]->changeIDChar(k, 'd');
				}
			}
		}

		std::cout << "\t[Outcomes storage generated.]" << std::endl;
	}
	catch (...) {
		std::cerr << "Unexpected error occured";
	}
}

void  OutcomeGenerator::getInfo() {
	for (int i = 0; i < (int)possibilitystorage.size(); i++) {
		possibilitystorage[i]->getInfo();
		//std::cout << std::endl;
	}
}
void  OutcomeGenerator::setwR(size_t index, double wR) {
	possibilitystorage[index]->setRm1(wR);
}
double  OutcomeGenerator::getwR(size_t index)const {
	return possibilitystorage[index]->getRm1();
}
void  OutcomeGenerator::setlP(size_t index, double value) {
	possibilitystorage[index]->setP0(value);
}
double  OutcomeGenerator::getlP(size_t index)const {
	return possibilitystorage[index]->getP0();
}
void  OutcomeGenerator::setdS(size_t index, double value) {
	possibilitystorage[index]->setS1(value);
}
double  OutcomeGenerator::getdS(size_t index)const {
	return possibilitystorage[index]->getS1();
}
void  OutcomeGenerator::setdatasize(size_t index, int value) {
	possibilitystorage[index]->setdatasize(value);
}
int  OutcomeGenerator::getdatasize(size_t index)const {
	return possibilitystorage[index]->getdatasize();
}
void  OutcomeGenerator::set(char type, size_t index, double value) {
	if (type == '0' || type == 'p' || type == 'L' || type == 'P') {
		possibilitystorage[index]->setP0(value);
	}
	else if (type == '1' || type == 's' || type == 'S') {
		possibilitystorage[index]->setS1(value);
	}
	else {
		possibilitystorage[index]->setRm1(value);
	}
}
double  OutcomeGenerator::get(char type, size_t index) {
	if (type == '0' || type == 'p' || type == 'L' || type == 'P') {
		return possibilitystorage[index]->getP0();
	}
	else if (type == '1' || type == 's' || type == 'S') {
		return possibilitystorage[index]->getS1();
	}
	else {
		return possibilitystorage[index]->getRm1();
	}
}

#endif // ! OUTCOMEGEN_H

