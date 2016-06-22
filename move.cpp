#include "move.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Move::Move(string name, int typeM, int atktype,int pp, double base, double accu):name(name), typeM(typeM), atktype(atktype), pp(pp), base(base), accu(accu){}

Move::Move():name("namehere"), typeM(0), atktype(0), pp(0), base(0), accu(0){
}

Move::~Move(){}

string Move::toString(){
	stringstream ss;
	ss << "Move";
	return ss.str();
}