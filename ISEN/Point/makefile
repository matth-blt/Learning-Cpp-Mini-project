Point.exe: main.o Point.o Geometry.o
	g++ $^ -o $@
main.o: main.cpp Point.h Geometry.h
	g++ -std=c++20 -Wall -Wextra -O2 -c $< -o $@
Point.o: Point.cpp Point.h
	g++ -std=c++20 -Wall -Wextra -O2 -c $< -o $@
Geometry.o: Geometry.cpp Geometry.h
	g++ -std=c++20 -Wall -Wextra -O2 -c $< -o $@
clean:
	- del /f main.o Point.o Geometry.o Point.exe