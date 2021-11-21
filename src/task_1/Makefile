CC=g++
CFLAGS=-std=c++20
SOURCES=main.cc exercises.cc
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=exec.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $@
clean:
	rm ./exec.out
