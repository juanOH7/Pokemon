#include "status.h"
#include "offensive.h"
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using std::stringstream;

Status::Status(string name, int typeM, int atktype, int pp,double base, double accu):Move(name, typeM, atktype, pp, base,accu){}

Status::Status(const Status& original){
	Status( original.name,original.typeM,original.atktype,original.pp,original.base,original.accu);
}

Status::~Status(){
}

string Status::toString(){
	stringstream ss;
	ss << "Status"<< name << " PP:" << pp; 
	return ss.str();
}

double Status::use() const{
	return Move::base;
}
