CC = g++
VER = -std=c++20
CFLAGS = -Wall -Wextra -O2
LDFLAGS =
EXE = Monde_animal.exe
SOURCES = main.cpp
OBJECTS = $(SOURCES:.c=.o)

all: $(EXE)
$(EXE): $(OBJECTS)
	$(CC) $(VER) $(OBJECTS) -o $(EXE) $(LDFLAGS)
%.o: %.c
	$(CC) $(VER) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJECTS) $(EXE)


