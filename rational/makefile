all: connect4 rational

connect4: main.o C4Col.o C4Board.o
	g++ main.o C4Col.o C4Board.o -o connect4

rational: mainRational.o Rational.o
	g++ mainRational.o Rational.o -o rational

main.o: main.cpp
	g++ -c main.cpp

C4Col.o: C4Col.cpp
	g++ -c C4Col.cpp

C4Board.o: C4Board.cpp
	g++ -c C4Board.cpp 

mainRational.o: mainRational.cpp
	g++ -c mainRational.cpp

Rational.o: Rational.cpp
	g++ -c Rational.cpp

clean:
	rm rational connect4 *.o


