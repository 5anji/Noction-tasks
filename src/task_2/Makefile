CC=g++
CFLAGS=-std=c++20 -Wall -O2
SOURCES=main.cpp list.cpp colors.cpp other.cpp
EXECUTABLE=exec.out

run: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXECUTABLE) && ./$(EXECUTABLE)

build: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(EXECUTABLE)

clean: $(EXECUTABLE)
	rm ./exec.out
