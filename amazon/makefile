main: main.o Package.o Overnight.o TwoDay.o
	g++ main.o Overnight.o Package.o TwoDay.o -o main

main.o: main.cpp
	g++ -c main.cpp

Overnight.o: Overnight.cpp
	g++ -c Overnight.cpp

Package.o: Package.cpp
	g++ -c Package.cpp

TwoDay.o: TwoDay.cpp
	g++ -c TwoDay.cpp

clean:
	rm main *.o


