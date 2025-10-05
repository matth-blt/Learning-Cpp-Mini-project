Animal.exe: main.o Animal.o
	g++ $^ -o $@
main.o: main.cpp Animal.h
	g++ -std=c++20 -Wall -Wextra -O2 -c $< -o $@
Animal.o: Animal.cpp Animal.h
	g++ -std=c++20 -Wall -Wextra -O2 -c $< -o $@
clean:
	- del /f main.o Animal.o Animal.exe