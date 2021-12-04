CC=g++
CFLAGS=-std=c++20
SOURCES=main.cpp list.cpp colors.cpp other.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=exec.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $@
clean:
	rm ./exec.out
