#pragma once
#include <string>

using std::string;

class Move{
	friend class Pokemon;
protected:
	int typeM;
	int atktype;//Special/Physical
	string name;
	int pp;
	double base;
	double accu;
public:
	Move(string, int, int, int, double, double);
	~Move();
	Move();
    virtual string toString();
    virtual double use()const=0;
};