#include "ncurses.h"
#include "graphics.h"

#include <stdio.h>
#include <unistd.h>

Graphics::Graphics(){}

Graphics::~Graphics(){}

void Graphics::drawpok1(){
	int desplasarHor = 6;
	attron(COLOR_PAIR(2));
	mvprintw(8,18+desplasarHor,"  ");
	mvprintw(8,22+desplasarHor,"   ");
	mvprintw(9,10+desplasarHor,"   ");
	mvprintw(9,17+desplasarHor," ");
	mvprintw(9,20+desplasarHor,"  ");
	mvprintw(9,25+desplasarHor,"   ");
	mvprintw(10,9+desplasarHor," ");
	mvprintw(10,12+desplasarHor," ");
	mvprintw(10,15+desplasarHor,"   ");
	mvprintw(10,19+desplasarHor," ");
	mvprintw(10,23+desplasarHor,"  ");
	mvprintw(10,28+desplasarHor,"  ");
	mvprintw(11,7+desplasarHor,"  ");
	mvprintw(11,11+desplasarHor," ");
	mvprintw(11,14+desplasarHor," ");
	mvprintw(11,16+desplasarHor," ");
	mvprintw(11,18+desplasarHor," ");
	mvprintw(11,7+desplasarHor,"  ");
	mvprintw(11,21+desplasarHor,"  ");
	mvprintw(11,30+desplasarHor," ");
	mvprintw(12,6+desplasarHor," ");
	mvprintw(12,8+desplasarHor," ");
	mvprintw(12,11+desplasarHor," ");
	mvprintw(12,13+desplasarHor," ");
	mvprintw(12,15+desplasarHor," ");
	mvprintw(12,17+desplasarHor," ");
	mvprintw(12,20+desplasarHor," ");
	mvprintw(12,24+desplasarHor,"     ");
	mvprintw(12,31+desplasarHor," ");
	mvprintw(13,4+desplasarHor,"   ");
	mvprintw(13,12+desplasarHor,"  ");
	mvprintw(13,15+desplasarHor," ");
	mvprintw(13,17+desplasarHor," ");
	mvprintw(13,19+desplasarHor," ");
	mvprintw(13,22+desplasarHor,"  ");
	mvprintw(13,29+desplasarHor," ");
	mvprintw(13,31+desplasarHor," ");
	mvprintw(14,4+desplasarHor," ");
	mvprintw(14,6+desplasarHor," ");
	mvprintw(14,11+desplasarHor,"   ");
	mvprintw(14,15+desplasarHor,"    ");
	mvprintw(14,21+desplasarHor," ");
	mvprintw(14,30+desplasarHor," ");
	mvprintw(14,32+desplasarHor," ");
	mvprintw(15,5+desplasarHor," ");
	mvprintw(15,10+desplasarHor," ");
	mvprintw(15,12+desplasarHor,"   ");
	mvprintw(15,18+desplasarHor," ");
	mvprintw(15,20+desplasarHor," ");
	mvprintw(15,30+desplasarHor," ");
	mvprintw(15,32+desplasarHor," ");
	mvprintw(16,5+desplasarHor," ");
	mvprintw(16,12+desplasarHor,"  ");
	mvprintw(16,14+desplasarHor,"  ");
	mvprintw(16,19+desplasarHor," ");
	mvprintw(16,22+desplasarHor,"   ");
	mvprintw(16,31+desplasarHor,"  ");
	mvprintw(17,5+desplasarHor," ");
	mvprintw(17,12+desplasarHor," ");
	mvprintw(17,15+desplasarHor," ");
	mvprintw(17,19+desplasarHor,"   ");
	mvprintw(17,25+desplasarHor," ");
	mvprintw(17,31+desplasarHor," ");
	mvprintw(18,5+desplasarHor," ");
	mvprintw(18,14+desplasarHor," ");
	mvprintw(18,20+desplasarHor," ");
	mvprintw(18,22+desplasarHor,"  ");
	mvprintw(18,26+desplasarHor," ");
	mvprintw(18,31+desplasarHor," ");
	mvprintw(19,5+desplasarHor," ");
	mvprintw(19,15+desplasarHor," ");
	mvprintw(19,20+desplasarHor," ");
	mvprintw(19,24+desplasarHor," ");
	mvprintw(19,26+desplasarHor," ");
	mvprintw(19,30+desplasarHor," ");
	mvprintw(20,4+desplasarHor," ");
	mvprintw(20,11+desplasarHor," ");
	mvprintw(20,13+desplasarHor,"  ");
	mvprintw(20,18+desplasarHor," ");
	mvprintw(20,20+desplasarHor," ");
	mvprintw(20,24+desplasarHor," ");
	mvprintw(20,26+desplasarHor," ");
	mvprintw(20,30+desplasarHor," ");
	mvprintw(21,4+desplasarHor," ");
	mvprintw(21,10+desplasarHor," ");
	mvprintw(21,14+desplasarHor," ");
	mvprintw(21,17+desplasarHor," ");
	mvprintw(21,20+desplasarHor," ");
	mvprintw(21,25+desplasarHor," ");
	mvprintw(21,29+desplasarHor," ");
	mvprintw(22,4+desplasarHor,"  ");
	mvprintw(22,8+desplasarHor,"  ");
	mvprintw(22,13+desplasarHor," ");
	mvprintw(22,16+desplasarHor,"  ");
	mvprintw(22,19+desplasarHor," ");
	mvprintw(22,23+desplasarHor,"  ");
	mvprintw(22,28+desplasarHor," ");
	mvprintw(23,5+desplasarHor,"     ");
	mvprintw(23,11+desplasarHor,"  ");
	mvprintw(23,16+desplasarHor,"  ");
	mvprintw(23,19+desplasarHor," ");
	mvprintw(23,22+desplasarHor," ");
	mvprintw(23,26+desplasarHor,"  ");
	mvprintw(24,9+desplasarHor," ");
	mvprintw(24,11+desplasarHor," ");
	mvprintw(24,13+desplasarHor," ");
	mvprintw(24,16+desplasarHor," ");
	mvprintw(24,18+desplasarHor," ");
	mvprintw(24,23+desplasarHor,"   ");
	mvprintw(25,10+desplasarHor," ");
	mvprintw(25,13+desplasarHor," ");
	mvprintw(25,15+desplasarHor," ");
	mvprintw(26,10+desplasarHor," ");
	mvprintw(26,12+desplasarHor," ");
	mvprintw(26,15+desplasarHor," ");
	mvprintw(27,11+desplasarHor,"  ");
	mvprintw(27,15+desplasarHor," ");
	mvprintw(28,12+desplasarHor," ");
	mvprintw(28,14+desplasarHor," ");
	mvprintw(29,12+desplasarHor,"  ");
	attron(COLOR_PAIR(6));
	mvprintw(19,9+desplasarHor," ");
	mvprintw(20,8+desplasarHor,"  ");
	attron(COLOR_PAIR(7));
	mvprintw(9,18+desplasarHor,"  ");
	mvprintw(9,22+desplasarHor,"   ");
	mvprintw(10,11+desplasarHor," ");
	mvprintw(10,17+desplasarHor,"  ");
	mvprintw(10,20+desplasarHor,"   ");
	mvprintw(10,25+desplasarHor,"   ");
	mvprintw(11,10+desplasarHor," ");
	mvprintw(11,17+desplasarHor," ");
	mvprintw(11,19+desplasarHor,"  ");
	mvprintw(11,23+desplasarHor,"       ");
	mvprintw(12,10+desplasarHor," ");
	mvprintw(12,16+desplasarHor," ");
	mvprintw(12,18+desplasarHor,"  ");
	mvprintw(12,21+desplasarHor,"   ");
	mvprintw(12,29+desplasarHor,"  ");
	mvprintw(13,9+desplasarHor,"   ");
	mvprintw(13,20+desplasarHor,"  ");
	mvprintw(13,24+desplasarHor,"     ");
	mvprintw(13,30+desplasarHor," ");
	mvprintw(14,5+desplasarHor," ");
	mvprintw(14,8+desplasarHor,"   ");
	mvprintw(14,19+desplasarHor,"  ");
	mvprintw(14,22+desplasarHor,"       ");
	mvprintw(14,31+desplasarHor," ");
	mvprintw(15,6+desplasarHor,"    ");
	mvprintw(15,11+desplasarHor," ");
	mvprintw(15,15+desplasarHor,"   ");
	mvprintw(15,21+desplasarHor,"         ");
	mvprintw(16,6+desplasarHor,"   ");
	mvprintw(16,10+desplasarHor," ");
	mvprintw(16,13+desplasarHor," ");
	mvprintw(16,16+desplasarHor,"   ");
	mvprintw(16,25+desplasarHor,"      ");
	mvprintw(17,6+desplasarHor,"     ");
	mvprintw(17,13+desplasarHor,"  ");
	mvprintw(17,16+desplasarHor,"   ");
	mvprintw(17,22+desplasarHor,"   ");
	mvprintw(17,26+desplasarHor,"     ");
	mvprintw(18,7+desplasarHor,"       ");
	mvprintw(18,15+desplasarHor,"    ");
	mvprintw(18,24+desplasarHor,"  ");
	mvprintw(18,27+desplasarHor,"   ");
	mvprintw(19,6+desplasarHor,"  ");
	mvprintw(19,10+desplasarHor,"     ");
	mvprintw(19,16+desplasarHor,"  ");
	mvprintw(19,6+desplasarHor,"  ");
	mvprintw(19,25+desplasarHor," ");
	mvprintw(19,27+desplasarHor,"   ");
	mvprintw(20,5+desplasarHor,"   ");
	mvprintw(20,5+desplasarHor,"   ");
	mvprintw(20,10+desplasarHor," ");
	mvprintw(20,12+desplasarHor," ");
	mvprintw(20,15+desplasarHor,"   ");
	mvprintw(20,25+desplasarHor," ");
	mvprintw(20,27+desplasarHor,"  ");
	mvprintw(21,5+desplasarHor,"     ");
	mvprintw(21,11+desplasarHor,"   ");
	mvprintw(21,15+desplasarHor,"  ");
	mvprintw(21,26+desplasarHor,"  ");
	mvprintw(22,6+desplasarHor,"  ");
	mvprintw(22,10+desplasarHor,"   ");
	mvprintw(22,14+desplasarHor,"  ");
	mvprintw(22,25+desplasarHor,"  ");
	mvprintw(23,9+desplasarHor,"  ");
	mvprintw(23,13+desplasarHor,"   ");
	mvprintw(23,23+desplasarHor,"  ");
	mvprintw(24,10+desplasarHor," ");
	mvprintw(24,12+desplasarHor," ");
	mvprintw(24,14+desplasarHor," ");
	mvprintw(25,14+desplasarHor," ");
	mvprintw(26,14+desplasarHor,"  ");
	mvprintw(26,13+desplasarHor,"  ");
	mvprintw(27,13+desplasarHor," ");
	mvprintw(28,13+desplasarHor,"  ");
	attron(COLOR_PAIR(1));
	mvprintw(11,15+desplasarHor," ");
	mvprintw(12,14+desplasarHor," ");
	mvprintw(13,14+desplasarHor," ");
	mvprintw(13,16+desplasarHor," ");
	mvprintw(13,18+desplasarHor," ");
	mvprintw(14,14+desplasarHor," ");
	mvprintw(14,29+desplasarHor," ");
	mvprintw(15,19+desplasarHor," ");
	mvprintw(15,31+desplasarHor," ");
	mvprintw(16,9+desplasarHor," ");
	mvprintw(16,11+desplasarHor," ");
	mvprintw(16,20+desplasarHor,"  ");
	mvprintw(17,11+desplasarHor," ");
	mvprintw(18,6+desplasarHor," ");
	mvprintw(18,19+desplasarHor," ");
	mvprintw(18,30+desplasarHor," ");
	mvprintw(19,18+desplasarHor,"  ");
	mvprintw(20,19+desplasarHor," ");
	mvprintw(20,29+desplasarHor," ");
	mvprintw(21,18+desplasarHor,"  ");
	mvprintw(21,28+desplasarHor," ");
	mvprintw(22,18+desplasarHor," ");
	mvprintw(22,27+desplasarHor," ");
	mvprintw(23,18+desplasarHor," ");
	mvprintw(23,25+desplasarHor," ");
	mvprintw(24,15+desplasarHor," ");
	mvprintw(25,11+desplasarHor,"  ");
	mvprintw(26,11+desplasarHor," ");
	mvprintw(27,14+desplasarHor," ");
}

void Graphics::drawpok2(){
	attron(COLOR_PAIR(2));
	mvprintw(8,111,"    ");
	mvprintw(9,109,"  ");
	mvprintw(9,115,"  ");
	mvprintw(10,107,"  ");
	mvprintw(10,117,"  ");
	mvprintw(11,107," ");
	mvprintw(11,118," ");
	mvprintw(12,106," ");
	mvprintw(12,119," ");
	mvprintw(13,106," ");
	mvprintw(13,119," ");
	mvprintw(14,105," ");
	mvprintw(14,120," ");
	mvprintw(15,105,"  ");
	mvprintw(15,113," ");
	mvprintw(15,120," ");
	mvprintw(16,105," ");
	mvprintw(16,107," ");
	mvprintw(16,110," ");
	mvprintw(16,112," ");
	mvprintw(16,120," ");
	mvprintw(17,105," ");
	mvprintw(17,107," ");
	mvprintw(17,111," ");
	mvprintw(17,120," ");
	mvprintw(18,106," ");
	mvprintw(18,111," ");
	mvprintw(18,119," ");
	mvprintw(19,106," ");
	mvprintw(19,119," ");
	mvprintw(20,107," ");
	mvprintw(20,118," ");
	mvprintw(21,107,"  ");
	mvprintw(21,117,"  ");
	mvprintw(22,109,"  ");
	mvprintw(22,115,"  ");
	mvprintw(23,111,"    ");
	attron(COLOR_PAIR(6));
	mvprintw(19,107," ");
	mvprintw(19,118," ");
	mvprintw(20,108,"  ");
	mvprintw(20,116,"  ");
	mvprintw(21,109,"        ");
	mvprintw(22,111,"    ");
}



void Graphics::drawMess1(){
	attron(COLOR_PAIR(1));
	mvprintw( 6, 34,"        ");
	for (int i = 6; i < 12; ++i){
		mvprintw( i, 42," ");
	}
	for (int i = 6; i < 12; ++i){
		mvprintw( i, 34," ");
	}
	mvprintw( 12, 34,"         ");
	for (int i = 13; i < 18; ++i){
		mvprintw( i, 42," ");
	}
	for (int i = 13; i < 18; ++i){
		mvprintw( i, 34," ");
	}
	mvprintw( 18, 34,"         ");
	//A
	mvprintw( 6, 44,"        ");
	for (int i = 6; i < 12; ++i){
		mvprintw( i, 44," ");
	}
	for (int i = 6; i < 12; ++i){
		mvprintw( i, 52," ");
	}
	mvprintw( 12, 44,"         ");
	for (int i = 13; i < 19; ++i){
		mvprintw( i, 52," ");
	}
	for (int i = 13; i < 19; ++i){
		mvprintw( i, 44," ");
	}
	//Ts
	mvprintw( 6, 55,"        ");
	for (int i = 6; i < 19; ++i){
		mvprintw( i, 59," ");
	}
	mvprintw( 6, 66,"        ");
	for (int i = 6; i < 19; ++i){
		mvprintw( i, 69," ");
	}
	//L
	for (int i = 6; i < 19; ++i){
		mvprintw( i, 77," ");
	}
	mvprintw( 18, 77,"        ");
	//E
	mvprintw( 6, 88,"        ");
	for (int i = 6; i < 12; ++i){
		mvprintw( i, 88," ");
	}
	mvprintw( 12, 88,"         ");
	for (int i = 13; i < 18; ++i){
		mvprintw( i, 88," ");
	}
	mvprintw( 18, 88,"         ");
	//!s
	for (int i = 6; i < 17; ++i){
		mvprintw( i, 99," ");
	}
	mvprintw( 18, 99," ");	
	for (int i = 6; i < 17; ++i){
		mvprintw( i, 110," ");
	}
	mvprintw( 18, 110," ");}

void Graphics::drawStage1(){
	refresh();
	clear();
	wbkgd(stdscr, COLOR_PAIR(4));
	attron(COLOR_PAIR(2));
	for (int i = 0 , j = 0; j < 141; ++j){
		mvprintw(i,j," ");
	}
	for (int i = 0 , j = 0; i < 38; ++i){
		mvprintw(i,j,"  ");
	}
	for (int i = 0 , j = 69; i < 38; ++i){
		mvprintw(i,j,"  ");
	}	
	for (int i = 0 , j = 141; i < 38; ++i){
		mvprintw(i,j,"  ");
	}
	for (int i = 38 , j = 0; j < 142; ++j){
		mvprintw(i,j,"  ");
	}
}