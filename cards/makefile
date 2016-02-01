all: tencard monkeysort casino

tencard: CardDeck.o tencard.o
	g++ CardDeck.o tencard.o -o tencard

monkeysort: CardDeck.o monkeysort.o
	g++ CardDeck.o monkeysort.o -o monkeysort

casino: BlackJack.o CardDeck.o casino.o
	g++ BlackJack.o CardDeck.o casino.o -o casino

tencard.o: tencard.cpp
	g++ -c tencard.cpp

monkeysort.o: monkeysort.cpp
	g++ -c monkeysort.cpp

CardDeck.o: CardDeck.cpp
	g++ -c CardDeck.cpp

BlackJack.o: BlackJack.cpp
	g++ -c BlackJack.cpp

casino.o: casino.cpp
	g++ -c casino.cpp

clean:
	rm tencard monkeysort casino *.o
