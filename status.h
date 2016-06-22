#pragma once
#include "move.h"
#include <string>

using std::string;

class Status:public Move{
	friend class Pokemon;
public:
	Status(string, int, int, int, double, double);
	Status(const Status&);
	~Status();
	virtual string toString();
	double use()const;
};
