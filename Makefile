CXX = g++

FLAGS = -Wall -Werror

CFLAGS = -c -Wall -Werror

OBJECTS = build/main.o build/generation_alphabet.o

.PHONY: all bin build clean

all: build bin bin/main

bin/main: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/main

build/main.o: src/main.cpp
	$(CXX) $(CFLAGS) src/main.cpp -o build/main.o

build/generation_alphabet.o: src/generation_alphabet.cpp
	$(CXX) $(CFLAGS) src/generation_alphabet.cpp -o build/generation_alphabet.o

build:
	mkdir -p build

bin:
	mkdir -p bin 

clean:
	-rm -rf build bin