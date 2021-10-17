CXX = g++

FLAGS = -Wall -Werror

CFLAGS = -c -Wall -Werror

OBJECTS = build/main.o build/generation_alphabet.o build/generation_password.o build/handling_main_argument.o

.PHONY: all bin build clean

all: build bin bin/main

bin/main: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/main

build/main.o: src/main.cpp
	$(CXX) $(CFLAGS) src/main.cpp -o build/main.o

build/generation_alphabet.o: src/generation_alphabet.cpp
	$(CXX) $(CFLAGS) src/generation_alphabet.cpp -o build/generation_alphabet.o

build/generation_password.o: src/generation_password.cpp
	$(CXX) $(CFLAGS) src/generation_password.cpp -o build/generation_password.o

build/handling_main_argument.o: src/handling_main_argument.cpp
	$(CXX) $(CFLAGS) src/handling_main_argument.cpp -o build/handling_main_argument.o

build:
	mkdir -p build

bin:
	mkdir -p bin 

clean:
	-rm -rf build bin