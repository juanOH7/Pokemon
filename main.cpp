#include "ncurses.h"
#include <cstring>
#include "move.h"
#include "status.h"
#include "offensive.h"
#include "pokemon.h"
#include "graphics.h"
#include <time.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <unistd.h>

using std::string;
using std::cout;

void pantallaOsc();
void menu();
void drawHP(int,int&,int,int&);
char charVal();
bool charVal2(char&);
void pokeTitle();
void Player1(Pokemon&,Pokemon&, Graphics,int,int&,int&);
void Play2(Pokemon&,Pokemon&, Graphics,int,int&,int&);
bool fight(int, int);
char charValMov(Graphics, Pokemon&, int, int&);
bool charPos(char&,int,Pokemon&);
void setStage(Graphics,int,int&,int,int&);

int main(int argc, char const *argv[]){
	/*cout << "Main";
	Pokemon pik("Hitmolee", 1, 1);
	Pokemon sd("Abra",13,1);
	Offensive Sts("GG", 13, 1,12, 425, 60);
	Status sdsa("GG", 13, 1,12, 425, 60);
	sd.setMove(3, Sts);
	sd.setMove(2, sdsa);
	for (int i = 0; i < 10; ++i){
			cout << sd.useMove(3) << "\n";
	}
	for (int i = 0; i < 10; ++i){
			cout << sd.useMove(2) << "\n";
	}
	pik.defend(sd, 3);*/
	Pokemon Tail("Ninetails", 9, 15);
	Pokemon Volt("Voltorb", 12, 15);
	Offensive Sts("Fire Fang", 9, 0,12, 60, 95);
	Offensive sdsa("Thunder", 12, 1,12, 90, 80);
	bool BattleGoes = true;
	Tail.setMove(0, Sts);
	Volt.setMove(0, sdsa);
	char respMen,respMov,respMov2;
	char posMoch[1];
	int posMo;
	char posMoch2[1];
	int posMo2;
	int turn = 1;
	bool goodans = false;
	initscr();
	start_color();
	init_pair(2,COLOR_RED, COLOR_BLACK);
	init_pair(1,COLOR_BLUE, COLOR_BLUE );
	init_pair(3,COLOR_BLACK, COLOR_BLUE);
	init_pair(4,COLOR_BLACK, COLOR_WHITE);	
	init_pair(5,COLOR_BLACK, COLOR_GREEN);
	init_pair(6,COLOR_BLACK, COLOR_RED);	
	init_pair(7,COLOR_BLACK, COLOR_CYAN);	
	init_pair(8,COLOR_BLACK, COLOR_MAGENTA);	
	init_pair(9,COLOR_BLACK, COLOR_YELLOW);
	pantallaOsc();
	Graphics test1;
	getch();
	do
	{
		int HP1 = Tail.HP(), HP2 = Volt.HP();
		int CurrHP1 =Tail.GamHP1(), CurrHP2 = Volt.GamHP1();
		goodans = false;
		posMo=0;
		posMo2 = 0;
		while(!goodans){
			respMen = charVal();
			goodans = charVal2(respMen);
		}
		if (respMen == 'A' || respMen == 'a'){
			BattleGoes = true;
			turn = 1;
			while(BattleGoes){
				if (turn == 1){
					goodans = false;
					posMo=0;
					posMo2 = 0;
					attron(COLOR_PAIR(2));
					while(!goodans){
						respMov = charValMov(test1,Tail, HP2, CurrHP2);
						mvprintw(8,61,"Player1 Ninetails");
						setStage(test1, HP1, CurrHP1, HP2, CurrHP2);
						posMoch[0] = respMov;
						posMo = atoi(posMoch);
						goodans = charPos(respMov, posMo, Tail);
					}
					goodans = false;
					while(!goodans){
						posMo=0;
						posMo2 = 0;
						mvprintw(8,61,"Player2 Voltorb");
						respMov2 = charValMov(test1,Volt, HP2, CurrHP2);
						posMoch2[0] = respMov2;
						posMo2 = atoi(posMoch2);
						goodans = charPos(respMov2, posMo2, Volt);
					}
					posMoch[0] = respMov;
					posMo = atoi(posMoch);
					posMoch2[0] = respMov2;
					posMo2 = atoi(posMoch2);
					turn = 2;
				}else if (turn == 2){
					if ((Tail.Speed() > Volt.Speed())){
						mvprintw(8,61,"Fast Tail");
						if (Tail.canAttack()){
							mvprintw(8,61,"Fast Tail can canAttack");
							Player1(Tail, Volt ,test1, posMo - 1, CurrHP1, CurrHP2);
						}else{
							mvprintw(31,61,"You Can't move");
							getch();
						}
						if (Volt.canAttack()){
							mvprintw(8,61,"Fast Tail Volt");
							Play2(Tail, Volt ,test1,posMo2 - 1, CurrHP1, CurrHP2);
						}else{
							mvprintw(31,61,"You Can't move");
							getch();
						}
					}else{
						mvprintw(8,61,"Fast Volt");
						if (Volt.canAttack()){
							mvprintw(8,61,"Fast Tail can canAttack");
						Play2(Tail, Volt ,test1,posMo - 1, CurrHP1, CurrHP2);
						}else{
							mvprintw(31,61,"You Can't move");
							getch();
						}
						if (Tail.canAttack()){
							mvprintw(8,61,"Fast Volt Tail ATk");
							Player1(Tail, Volt ,test1,posMo2 - 1, CurrHP1, CurrHP2);
						}else{
							mvprintw(31,61,"You Can't move");
							getch();
						}
					}
					turn =  (CurrHP1 <= 0  || CurrHP2 <= 0) ? 3 : 1;
				}else if (turn = 3){
					if (CurrHP2 > 0 && CurrHP1 <= 0){
						setStage(test1, HP1, CurrHP1, HP2, CurrHP2);
						mvprintw(31,61,"Player 2 Wins!!");
						getch();
					}else if (CurrHP2 <= 0 && CurrHP1 > 0){
						setStage(test1, HP1, CurrHP1, HP2, CurrHP2);
						mvprintw(31,61,"Player 1 Wins!!");
						getch();
					}else{
						setStage(test1, HP1, CurrHP1, HP2, CurrHP2);
						mvprintw(31,61,"Tie??");
						getch();
					}
					BattleGoes = false;
				}
			}
		}
	} while (respMen != 'C' || respMen != 'c');
	getch();
	
	getch();
	endwin();
	return 0;
}

void pantallaOsc(){
	refresh();
	wbkgd(stdscr, COLOR_PAIR(1));
}

void Player1(Pokemon& Tail,Pokemon& Volt, Graphics test1, int posMo, int& CurrHP1, int& CurrHP2){
	int HP1 = Tail.HP(), HP2 = Volt.HP();
	setStage(test1, HP1, CurrHP1, HP2, CurrHP2);
	getch();
	if (Tail.useMove(posMo) == 0){
		mvprintw(31,61,"Miss Hit");
	}else if (Tail.useMove(posMo) > 0){
		if (Volt.effectiveness(Tail.ATKDMGT(posMo)) == 1){
			mvprintw(31,61,"Super Effective!");
			Volt.defend(Tail, posMo);
			CurrHP2 = Tail.GamHP1();
		}else if (Volt.effectiveness(Tail.ATKDMGT(posMo)) == 2){
			mvprintw(31,61,"Not very Effective!");
			Volt.defend(Tail, posMo);
			CurrHP2 = Tail.GamHP1();
		}else if (Volt.effectiveness(Tail.ATKDMGT(posMo)) == 3){
			mvprintw(31,61,"Doesn't affect opponent");
			Volt.defend(Tail, posMo);
			CurrHP2 = Tail.GamHP1();
		}else{
			Volt.defend(Tail, posMo);
			CurrHP2 = Tail.GamHP1();
			mvprintw(31,61,"It Hit!");
		}
		setStage(test1, HP1, CurrHP1, HP2, CurrHP2);
		getch();
	}else{
		Volt.setState(Tail.useMove(posMo));
		Volt.defend(Tail, posMo);
		CurrHP2 = Tail.GamHP1();
		mvprintw(31,61,"Status Given");
	}
}
void setStage(Graphics test1,int HP1,int& CurrHP1, int HP2,int& CurrHP2){
	test1.drawStage1();
	test1.drawpok1();
	test1.drawpok2();
	drawHP(HP1, CurrHP1, HP2, CurrHP2);
}
void drawHP(int totHP, int& currHP, int totHP2, int& currHP2){
	attron(COLOR_PAIR(1));
	int desplasarHor = 3, desplasarVert = 2;
	int desplasarVert2 = 34;
	for (int j = 0; j < 52; ++j){
		mvprintw(desplasarVert,(j+desplasarHor)," ");
		mvprintw(desplasarVert + 1,(j+desplasarHor)," ");
		mvprintw(desplasarVert + 2,(j+desplasarHor)," ");
	}
	for (int desplasarHor2 = 139, j = 0; j < 52; ++j, desplasarHor2--){
		mvprintw(desplasarVert2,(desplasarHor2)," ");
		mvprintw(desplasarVert2 + 1,(desplasarHor2)," ");
		mvprintw(desplasarVert2 + 2,(desplasarHor2)," ");
	}
	double currHPD = currHP, currHPD2 = currHP2, totHPD = totHP, totHPD2 = totHP2;
	double percent1 = currHPD/totHPD;
	double percent2 = currHPD2/totHPD2;
	for (int j = 1; j < currHP+1; ++j){
		if (percent1 > 0.3 && percent1 < 0.5){
			attron(COLOR_PAIR(9));
			mvprintw(desplasarVert + 1,(j+desplasarHor)," ");	
		}else if (percent1 < 0.3){
			attron(COLOR_PAIR(6));
			mvprintw(desplasarVert + 1,(j+desplasarHor)," ");
		}else{
			attron(COLOR_PAIR(5));
			mvprintw(desplasarVert + 1,(j+desplasarHor)," ");
		}
	}
	for (int desplasarHor2 = 138, j = 0; j < currHP2; ++j, desplasarHor2--){
		if (percent2 > 0.3 && percent2 < 0.5){
			attron(COLOR_PAIR(9));
			mvprintw(desplasarVert2 + 1,(desplasarHor2)," ");	
		}else if (percent2 < 0.3){
			attron(COLOR_PAIR(6));
			mvprintw(desplasarVert2 + 1,(desplasarHor2)," ");
		}else{
			attron(COLOR_PAIR(5));
			mvprintw(desplasarVert2 + 1,(desplasarHor2)," ");
		}

	}
}

void Play2(Pokemon& Tail,Pokemon& Volt, Graphics test1, int posMo2, int& CurrHP1, int& CurrHP2){
	int HP1 = Tail.HP(), HP2 = Volt.HP();

	setStage(test1, HP1, CurrHP1, HP2, CurrHP2);
	if (Volt.useMove(posMo2) == 0){
		mvprintw(31,61,"Miss Hit");
	}else if (Volt.useMove(posMo2) > 0){
		setStage(test1, HP1, CurrHP1, HP2, CurrHP2);
		if (Tail.effectiveness(Volt.ATKDMGT(posMo2)) == 1){
			Tail.defend(Volt, posMo2);
			CurrHP1 = Tail.GamHP1();
			mvprintw(31,61,"Super Effective!");
		}else if (Tail.effectiveness(Volt.ATKDMGT(posMo2)) == 2){
			Tail.defend(Volt, posMo2);
			CurrHP1 = Tail.GamHP1();
			mvprintw(31,61,"Not very Effective!");
		}else if (Tail.effectiveness(Volt.ATKDMGT(posMo2)) == 3){
			Tail.defend(Volt, posMo2);
			CurrHP1 = Tail.GamHP1();
			mvprintw(31,61,"Doesn't affect opponent");
		}else{
			mvprintw(31,61,"It Hit!");
			Tail.defend(Volt, posMo2);
			CurrHP1 = Tail.GamHP1();
		}
		setStage(test1, HP1, CurrHP1, HP2, CurrHP2);
		getch();
	}else{
		Tail.defend(Volt, posMo2);
		CurrHP1 = Tail.GamHP1();
		Tail.setState(Volt.useMove(posMo2));
		mvprintw(31,61,"Status Given");
	}
}

void menu(){
	int desplasarHor = 38,desplasarVert =12;
	refresh();
	attron(COLOR_PAIR(2));
	int posLastY = 65, posLastX = 10;
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
	mvprintw( yMess, xMess,"-> A - Battle With Graphics (Limited)!!!        ");
	mvprintw( yMess + 2, xMess,"-> B - Battle With Custom Pokémon (No Images)!!!");
	mvprintw( yMess + 4, xMess,"-> C - Load last session                        ");
	mvprintw( yMess + 6, xMess,"-> D - Exit game                                ");
}

void pokeTitle(){
	attron(COLOR_PAIR(4));
}

char charVal(){
	char resp;
	bool validarEntrada = true;
	while(validarEntrada){
		pokeTitle();
		menu();
		mvprintw(29,61,"Choose one: ");
		noecho();
		char temp;
		temp = getch();
		if(charVal2(temp)){
			echo();
			resp = temp;
			attron(COLOR_PAIR(3));
			mvaddch(29,75,resp);
			validarEntrada = false;
		}else{
			pokeTitle();
			menu();
			validarEntrada == true;
			mvprintw(35,61,"Invalid Input!!!");	
		}
		getch();
		clear();
	}
	return resp;
}

bool charVal2(char& charToval){
	if(charToval == 65  || charToval == 97  || charToval == 66 || charToval == 98 || charToval == 67 || charToval == 99 || charToval == 68 || charToval == 100 ){
		return true;
	}else{
		return false;
	}
}

char charValMov(Graphics test1,Pokemon& currentPok, int HP2, int& CurrHP2){
	char resp;
	int posMo;
	char posMoch[1];
	bool validarEntrada = true;
	getch();
	int HP1 = currentPok.HP(), otHP2 = HP2;
	int CurrHP1 = currentPok.HP(), otCurrHP2 = CurrHP2;
	setStage(test1, HP1, CurrHP1, HP2, CurrHP2);
	while(validarEntrada){
		setStage(test1, HP1, CurrHP1, HP2, CurrHP2);
		mvprintw(29,61,"Move: ");
		currentPok.drawMoves();
		noecho();
		char temp;
		temp = getch();
		posMoch[0] = temp;
		posMo = atoi(posMoch);
		if(charPos(temp, posMo, currentPok)){
			echo();
			resp = temp;
			attron(COLOR_PAIR(3));
			mvaddch(29,75,resp);
			validarEntrada = false;
		}else{
			setStage(test1, HP1, CurrHP1, HP2, CurrHP2);
			currentPok.drawMoves();
			validarEntrada == true;
			mvprintw(29,61,"Move: ");
			mvprintw(31,61,"Invalid Input!!!");	
		}
		getch();
		clear();
	}
	return resp;
}

bool charPos(char& charToval,int posMo,Pokemon& currentPok){
	if((charToval > 48  && charToval < 53) && currentPok.useMove(posMo-1)  ){
		return true;
	}else{
		return false;
	}
}