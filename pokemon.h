#pragma once
#include "move.h"
#include "offensive.h"
#include <string>

using std::string;

class Pokemon{
	string name;
	Move** moves;
	int GamHP;
	int type;
	int froZSlee;
	int* iv;//6 (0-31) individual values
	double* stats;//HP ATK DEF SPATK SPDEF SPE 
	double* basestats;//HP ATK DEF SPATK SPDEF SPE 
	int* ev;//6 (0-252) effort values
	int state;// -1 sleeping -2 frozen -3 paralyze
	int level;
	double xp;
public:
	Pokemon(string, int ,int); //name, type, level
	Pokemon(const Pokemon&);
	~Pokemon();
	bool canAttack();//check state
	string toString();
	void defend(Pokemon& ,int);
	void setState(int);
	double useMove(int);//4 tot
	void setMove(int, Move&);// pos move
	void levelUp();
	int Speed();
	int HP();
	int GamHP1();
	int ATKDMGT(int);
	int effectiveness(int);
	void drawMoves();
};
//Breed? 
//const Pokemon operator+(const Pokemon&, const Pokemon&);
