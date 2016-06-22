#pragma once
#include "move.h"
#include <string>

using std::string;

class Offensive:public Move{
	friend class Pokemon;
public:
	Offensive(string, int, int, int, double, double);
	Offensive(const Offensive&);
	~Offensive();
	virtual string toString();
	double use()const;
};
