main: main.o BankAccount.o Checking.o CheckingComp.o Savings.o
	g++ main.o BankAccount.o Checking.o CheckingComp.o Savings.o -o main

main.o: main.cpp
	g++ -c main.cpp

BankAccount.o: BankAccount.cpp
	g++ -c BankAccount.cpp

Checking.o: Checking.cpp
	g++ -c Checking.cpp

Savings.o: Savings.cpp
	g++ -c Savings.cpp

CheckingComp.o: CheckingComp.cpp
	g++ -c CheckingComp.cpp

clean:
	rm main *.o


