Animal.exe: main.o Animal.o Gazelle.o Lion.o
	g++ $^ -o $@
main.o: main.cpp Animal.h Gazelle.h Lion.h
	g++ -std=c++20 -Wall -Wextra -O2 -c $< -o $@
Animal.o: Animal.cpp Animal.h
	g++ -std=c++20 -Wall -Wextra -O2 -c $< -o $@
Gazelle.o: Gazelle.cpp Gazelle.h
	g++ -std=c++20 -Wall -Wextra -O2 -c $< -o $@
Lion.o: Lion.cpp Lion.h
	g++ -std=c++20 -Wall -Wextra -O2 -c $< -o $@
clean:
	- del /f main.o Animal.o Gazelle.o Lion.o Animal.exe