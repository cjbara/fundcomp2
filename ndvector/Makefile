all: 52card main

52card: CardDeck.o 52card.o NDVector.o
	g++ CardDeck.o 52card.o NDVector.o -o 52card

main: main.o NDVector.o 
	g++ main.o NDVector.o -o main

main.o: main.cpp
	g++ main.cpp -c

52card.o: 52card.cpp
	g++ -c 52card.cpp

CardDeck.o: CardDeck.cpp
	g++ -c CardDeck.cpp

NDVector.o: NDVector.cpp
	g++ -c NDVector.cpp

clean:
	rm 52card main *.o
