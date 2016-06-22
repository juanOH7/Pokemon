main: main.o pokemon.o move.o offensive.o status.o graphics.o 
	g++ -std=c++0x main.o pokemon.o move.o offensive.o status.o graphics.o  -o  main.exe -lncurses --enable-ext-colors
	
main.o:	main.cpp pokemon.h move.h
	g++ -c main.cpp 

graphics.o: graphics.h graphics.cpp
	g++ -c graphics.cpp -lncurses

pokemon.o:	pokemon.cpp pokemon.h move.h
	g++ -std=c++0x -c pokemon.cpp -lncurses

offensive.o: offensive.h offensive.cpp move.h
	g++ -std=c++0x -c offensive.cpp

status.o: status.h status.cpp offensive.h
	g++ -std=c++0x -c status.cpp

move.o: move.cpp move.h
	g++ -c move.cpp