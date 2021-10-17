CXX = g++

FLAGS = -Wall -Werror

CFLAGS = -c -Wall -Werror

OBJECTS = build/src/main.o build/src/generation_alphabet.o build/src/generation_password.o build/src/handling_main_argument.o

OBJECTS_TEST = build/test/main.o build/test/tests.o build/src/generation_alphabet.o

.PHONY: all bin build clean test

all: build bin bin/main test

test: build bin bin/main_test
	bin/main_test

bin/main_test: $(OBJECTS_TEST)
	$(CXX) $(FLAGS) $(OBJECTS_TEST) -o bin/main_test

build/test/main.o: test/main.c
	$(CXX) $(CFLAGS) test/main.c -I thirdparty/ -I src/ -o build/test/main.o

build/test/tests.o: test/tests.c
	$(CXX) $(CFLAGS) test/tests.c -I thirdparty/ -I src/ -o build/test/tests.o

bin/main: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/main

build/src/main.o: src/main.cpp
	$(CXX) $(CFLAGS) src/main.cpp -o build/src/main.o

build/src/generation_alphabet.o: src/generation_alphabet.cpp
	$(CXX) $(CFLAGS) src/generation_alphabet.cpp -o build/src/generation_alphabet.o

build/src/generation_password.o: src/generation_password.cpp
	$(CXX) $(CFLAGS) src/generation_password.cpp -o build/src/generation_password.o

build/src/handling_main_argument.o: src/handling_main_argument.cpp
	$(CXX) $(CFLAGS) src/handling_main_argument.cpp -o build/src/handling_main_argument.o

build:
	mkdir -p build/src
	mkdir -p build/test

bin:
	mkdir -p bin 

clean:
	-rm -rf build bin