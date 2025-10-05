heritage.exe: main.o unit.o character.o
	g++ $^ -o $@
main.o: main.cpp unit.hpp character.hpp
	g++ -std=c++20 -Wall -Wextra -O2 -c $< -o $@
Point.o: unit.cpp unit.hpp
	g++ -std=c++20 -Wall -Wextra -O2 -c $< -o $@
Geometry.o: character.cpp character.hpp
	g++ -std=c++20 -Wall -Wextra -O2 -c $< -o $@
clean:
	- del /f main.o unit.o character.o heritage.exe