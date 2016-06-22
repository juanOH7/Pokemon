#include "offensive.h"
#include "move.h"
#include <string>
#include <sstream>
#include <random>

using std::string;
using std::stringstream;
using std::bernoulli_distribution;
using std::random_device;
using std::mt19937;

Offensive::Offensive(string name, int typeM, int atktype,int pp, double base, double accu):Move(name, typeM, atktype, pp, base,accu){}

Offensive::Offensive(const Offensive& original){
	Offensive( original.name,original.typeM,original.atktype,original.pp,original.base,original.accu);
}


Offensive::~Offensive(){
}

string Offensive::toString(){
	stringstream ss;
	ss << name << " Accu:" << accu <<" PP:" << pp; 
	return ss.str();
}

double Offensive::use()const{
	random_device device;
	mt19937 gen(device());
	double decAccu = accu / 100;
	bernoulli_distribution prob(decAccu);
	if (prob(gen))
		return base;
	else
		return 0.0;
}
