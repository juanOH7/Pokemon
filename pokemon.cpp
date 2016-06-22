#include "pokemon.h"
#include "offensive.h"
#include "status.h"
#include <random>
#include <typeinfo>
#include "ncurses.h"
#include <iostream>

using std::string;
using std::stringstream;
using std::uniform_int_distribution;
using std::random_device;
using std::mt19937;
using std::bernoulli_distribution;

int ivRand(){
	random_device seed;
	mt19937 rng(seed());
	uniform_int_distribution<int> ran(0,31);
	return ran(rng);
}
int evRand(){
	random_device seed;
	mt19937 rng(seed());
	uniform_int_distribution<int> ran(0,255);
	return ran(rng);
}
int baseRand(){
	random_device seed;
	mt19937 rng(seed());
	uniform_int_distribution<int> ran(1,255);
	return ran(rng);
}
Pokemon::Pokemon(const Pokemon& original){
	name = original.name;
	type = original.type;
	level = original.level;
	xp = original.xp;
	froZSlee = original.xp;
	state = original.state;
	GamHP = original.stats[0];
	iv = new int[6];
	for (int i = 0; i < 6; ++i){
		iv[i] = original.iv[i];
	}
	ev = new int[6];
	for (int i = 0; i < 6; ++i){
		ev[i] = original.ev[i];
	}
	basestats = new double[6];
	for (int i = 0; i < 6; ++i){
		basestats[i] = original.basestats[i];
	}
	stats = new double[6];
	for (int i = 0; i < 6; ++i){
		stats[i] = original.stats[i];
	}
	stats[0] = 0;
	moves = new Move*[4];
	for (int i = 0; i < 4; ++i){
		moves[i] = original.moves[i];
	}
}

Pokemon::Pokemon(string name, int type ,int level): name(name), type(type) ,level(level),xp(0),froZSlee(0),state(0){
	iv = new int[6];
	for (int i = 0; i < 6; ++i){
		iv[i] = ivRand();
	}
	ev = new int[6];
	for (int i = 0; i < 6; ++i){
		ev[i] = evRand();
	}
	basestats = new double[6];
	for (int i = 0; i < 6; ++i){
		basestats[i] = baseRand();
	}
	stats = new double[6];
	for (int i = 0; i < 6; ++i){
		if (i == 0){
			stats[i] = 50;
		}else{
			stats[i] = (((2 * basestats[i] + iv[i] + (ev[i]/4)) * level)/100) + 5;
		}
	}
	GamHP = stats[0];
	moves = new Move*[4];
	moves[0] = NULL;
	moves[1] = NULL;
	moves[2] = NULL;
	moves[3] = NULL;
} //name, type, level

Pokemon::~Pokemon(){
	delete[] iv;
	delete[] ev;
	delete[] stats;
	delete[] basestats;
	for (int i = 0; i < 4; ++i){
		delete moves[i];
	}
	delete[] moves;
}

bool Pokemon::canAttack(){
	random_device device;
	mt19937 gen(device());
	if (state == 0 || state == -4){
		return true;
	}else if ((state == -1 || state == -2) && froZSlee != 0){
		froZSlee -= 1;
		return false;
	}else if (state == -3){
		bernoulli_distribution prob(0.75);
		if (prob(gen)){
			return true;
		}else{
			return false;
		}
	}
}

string Pokemon::toString(){}

void Pokemon::defend(Pokemon& attacker, int positionMv){
	double inDmg =attacker.useMove(positionMv);
	int tyDmg = attacker.moves[positionMv]->atktype;
	int typeDmg = attacker.moves[positionMv]->typeM;
	int levelOut = attacker.level;
	double Satk = attacker.stats[3];
	double atk = attacker.stats[1];
	int atkType = attacker.type;
	if (inDmg < 0){
		setState(inDmg);
	}else if (inDmg > 0){
		if (tyDmg == 0){//Physical
			if (effectiveness(typeDmg) == 1){
				if (typeDmg == atkType){//STAB
					GamHP -= ( ((2 * levelOut + 10)/250) * (atk/stats[2]) * inDmg + 2) * 2 * 1.5;
				}else{
					GamHP-= ( ((2 * levelOut + 10)/250) * (atk/stats[2]) * inDmg + 2) * 2;
				}
			}else if (effectiveness(typeDmg) == 2){
				if (typeDmg == atkType){//STAB
					GamHP -= 1.5 * 0.5 * ( ((2 * levelOut + 10)/250) * (atk/stats[2]) * inDmg + 2);
				}else{
					GamHP -= 0.5 * ( ((2 * levelOut + 10)/250) * (atk/stats[2]) * inDmg + 2);
				}
			}else if (effectiveness(typeDmg) == 3){
			}else if (effectiveness(typeDmg) == 4){
				if (typeDmg == atkType){//STAB
					GamHP -= 1.5 * ( ((2 * levelOut + 10)/250) * (atk/stats[2]) * inDmg + 2);
				}else{
					GamHP -= ( ((2 * levelOut + 10)/250) * (atk/stats[2]) * inDmg + 2);
				}
			}
		}else{//Special
			if (effectiveness(typeDmg) == 1){
				if (typeDmg == atkType){//STAB
					GamHP -= ( ((2 * levelOut + 10)/250) * (Satk/stats[4]) * inDmg + 2) * 2 * 1.5;
				}else{
					GamHP -= ( ((2 * levelOut + 10)/250) * (Satk/stats[4]) * inDmg + 2) * 2;
				}
			}else if (effectiveness(typeDmg) == 2){
				if (typeDmg == atkType){//STAB
					GamHP -= 1.5 * 0.5 * ( ((2 * levelOut + 10)/250) * (Satk/stats[4]) * inDmg + 2);
				}else{
					GamHP -= 0.5 * ( ((2 * levelOut + 10)/250) * (Satk/stats[4]) * inDmg + 2);
				}
			}else if (effectiveness(typeDmg) == 3){
			}else if (effectiveness(typeDmg) == 4){
				if (typeDmg == atkType){//STAB
					GamHP -= 1.5 * ( ((2 * levelOut + 10)/250) * (Satk/stats[4]) * inDmg + 2);
				}else{
					GamHP -= ( ((2 * levelOut + 10)/250) * (Satk/stats[4]) * inDmg + 2);
				}
			}	
		}
	}else{
		//MISS HIT
	}
}

int Pokemon::ATKDMGT(int pos){
	return moves[pos]->typeM;
}

int Pokemon::GamHP1(){
	return GamHP;
}


int Pokemon::effectiveness(int typeDmg){
	if (type == 0 && (typeDmg == 1)){
		return 1;
	}else if (type == 0 && (typeDmg == 7)){
		return 3;
	}else if (type == 1 && (typeDmg == 2 || typeDmg == 13 || typeDmg == 17)){
		return 1;			
	}else if (type == 1 && (typeDmg == 5 || typeDmg == 6 || typeDmg == 16)){
		return 2;			
	}else if (type == 2 && (typeDmg == 5 || typeDmg == 14 || typeDmg == 12)){
		return 1;
	}else if (type == 2 && (typeDmg == 1 || typeDmg == 6 || typeDmg == 11)){
		return 2;
	}else if (type == 2 && typeDmg == 4){
		return 3;
	}else if (type == 3 && (typeDmg == 4 || typeDmg == 13)){
		return 1;
	}else if (type == 3 && (typeDmg == 1 || typeDmg == 3 || typeDmg == 6 || typeDmg == 11 || typeDmg == 17)){
		return 2;
	}else if (type == 4 && (typeDmg == 10 || typeDmg == 11 || typeDmg == 14)){
		return 1;
	}else if (type == 4 && (typeDmg == 3 || typeDmg == 5)){
		return 2;
	}else if (type == 4 && typeDmg == 12){
		return 3;
	}else if (type == 5 && (typeDmg == 1 || typeDmg == 4 || typeDmg == 8 || typeDmg == 10 || typeDmg == 11)){
		return 1;
	}else if (type == 5 && (typeDmg == 0 || typeDmg == 2 || typeDmg == 3 || typeDmg == 9)){
		return 2;
	}else if (type == 6 && (typeDmg == 2 || typeDmg == 5 || typeDmg == 9)){
		return 1;
	}else if (type == 6 && (typeDmg == 1 || typeDmg == 4 || typeDmg == 11)){
		return 2;
	}else if (type == 7 && (typeDmg == 7 || typeDmg == 16)){
		return 1;
	}else if (type == 7 && (typeDmg == 3 || typeDmg == 6)){
		return 2;
	}else if (type == 2 && (typeDmg == 0 || typeDmg == 1)){
		return 3;
	}else if (type == 8 && (typeDmg == 1 || typeDmg == 4 || typeDmg == 9)){
		return 1;
	}else if (type == 8 && (typeDmg == 0 || typeDmg == 2 || typeDmg == 5 || typeDmg == 6 || typeDmg == 8 || typeDmg == 11 || typeDmg == 13 || typeDmg == 14 || typeDmg == 15 || typeDmg == 17)){
		return 2;
	}else if (type == 8 && typeDmg == 3){
		return 3;
	}else if (type == 9 && (typeDmg == 5 || typeDmg == 4 || typeDmg == 10)){
		return 1;
	}else if (type == 9 && (typeDmg == 6 || typeDmg == 8 || typeDmg == 9 || typeDmg == 11 || typeDmg == 14 || typeDmg == 17)){
		return 2;
	}else if (type == 10 && (typeDmg == 11 || typeDmg == 12 )){
		return 1;
	}else if (type == 10 && (typeDmg == 8 || typeDmg == 10 || typeDmg == 9 || typeDmg == 11 || typeDmg == 14)){
		return 2;
	}else if (type == 11 && (typeDmg == 2 || typeDmg == 3 || typeDmg == 6 || typeDmg == 9 || typeDmg == 14)){
		return 1;
	}else if (type == 11 && (typeDmg == 4 || typeDmg == 11 || typeDmg == 12 || typeDmg == 10 )){
		return 2;
	}else if (type == 12 && typeDmg == 4){
		return 1;
	}else if (type == 12 && (typeDmg == 2 || typeDmg == 8 || typeDmg == 12)){
		return 2;
	}else if (type == 13 && (typeDmg == 6 || typeDmg == 7 || typeDmg == 16)){
		return 1;
	}else if (type == 13 && (typeDmg == 1 || typeDmg == 13)){
		return 2;
	}else if (type == 14 && (typeDmg == 5 || typeDmg == 1 || typeDmg == 9 || typeDmg == 8)){
		return 1;
	}else if (type == 14 && typeDmg == 14){
		return 2;
	}else if (type == 15 && (typeDmg == 14 || typeDmg == 15 || typeDmg == 17)){
		return 1;
	}else if (type == 15 && (typeDmg == 9 || typeDmg == 10 || typeDmg == 11 || typeDmg == 12)){
		return 2;
	}else if (type == 16 && (typeDmg == 1 || typeDmg == 6 || typeDmg == 17)){
		return 1;
	}else if (type == 16 && (typeDmg == 7 || typeDmg == 16)){
		return 2;
	}else if (type == 16 && typeDmg == 13){
		return 3;
	}else if (type == 17 && (typeDmg == 3 || typeDmg == 8)){
		return 1;
	}else if (type == 17 && (typeDmg == 1 || typeDmg == 6 || typeDmg == 16)){
		return 2;
	}else if (type ==17 && typeDmg == 15){
		return 3;
	}else{
		return 4;
	}
}

void Pokemon::setState(int inSta){
	if (inSta == -1 || inSta == -2){
		random_device seed;
		mt19937 rng(seed());
		uniform_int_distribution<int> ran(1,2);
		froZSlee = ran(rng);
		state = inSta;
	}else{
		state = inSta;
	}
}

double Pokemon::useMove(int positionMv){//return base of move
	if (moves[positionMv] == NULL){
		return 0;
	}else{
		std::cout << moves[positionMv]->toString();
		return moves[positionMv]->use();
	}
}//4 tot
void Pokemon::setMove(int positionMv, Move& mov){
	if (typeid(mov) == typeid(Offensive)){
		moves[positionMv] = NULL;
		moves[positionMv] = new Offensive(mov.name,mov.typeM,mov.atktype,mov.pp,mov.base,mov.accu);
	}else{
		moves[positionMv] = NULL;
		moves[positionMv] = new Status(mov.name,mov.typeM,mov.atktype,mov.pp,mov.base,mov.accu);
	}
}// pos move
void Pokemon::levelUp(){
	for (int i = 0; i < 6; ++i){
		if (i == 0){
			stats[i] += (((2 * basestats[i] + iv[i] + (ev[i]/4)) * level)/100) + level + 10;
		}else{
			stats[i] += (((2 * basestats[i] + iv[i] + (ev[i]/4)) * level)/100) + 5;
		}
	}
}
int Pokemon::Speed(){
	return stats[5];
}

int Pokemon::HP(){
	return stats[0];
}

void Pokemon::drawMoves(){
	int desplasarHor = 50,desplasarVert =12;
	refresh();
	attron(COLOR_PAIR(2));
	int posLastY = 36, posLastX = 10;
	int xMess = desplasarHor + 9 , yMess = desplasarVert + 2 ;
	for (int i = 0 , j = 0; j < posLastY; ++j){
		mvprintw((i+desplasarVert),(j+desplasarHor)," ");
	}
	for (int i = 0 , j = 0; i < posLastX; ++i){
		mvprintw((i+desplasarVert),(j+desplasarHor),"  ");
	}	
	for (int i = 0 , j = posLastY; i < posLastX; ++i){
		mvprintw((i+desplasarVert),(j+desplasarHor),"  ");
	}
	for (int i = posLastX , j = 0; j < posLastY + 1; ++j){
		mvprintw((i+desplasarVert),(j+desplasarHor),"  ");
	}
	attron(COLOR_PAIR(3));
	if (moves[0] == NULL){
		mvprintw( yMess, xMess,"1-          ");
	}else{
		const char* line1 = (moves[0]->name).c_str();
		mvprintw( yMess, xMess,"1-%s", line1);
	}
	if (moves[1] == NULL){
		mvprintw( yMess + 2, xMess,"2-          ");
	}else{
		const char* line2 = (moves[1]->name).c_str();
		mvprintw( yMess + 2, xMess,"2-%s", line2);
	}
	if (moves[2] == NULL){
		mvprintw( yMess + 4, xMess,"3-          ");
	}else{
		const char* line3 = (moves[2]->name).c_str();
		mvprintw( yMess + 4, xMess,"3-%s", line3);
	}
	if (moves[3] == NULL){
		mvprintw( yMess + 6, xMess,"4-          ");
	}else{
		const char* line4 = (moves[3]->name).c_str();
		mvprintw( yMess + 6, xMess,"4-%s", line4);
	}
}