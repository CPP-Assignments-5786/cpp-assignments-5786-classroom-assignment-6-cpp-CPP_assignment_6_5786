CXX=g++
CXXFLAGS=-std=c++23 -Werror -Wsign-conversion
SOURCES=Animal.cpp Mammal.cpp Bird.cpp Reptile.cpp Zoo.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

all: demo
	./demo

demo: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestRunner.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test
	./test

TestRunner.o: test.cpp Animal.hpp Mammal.hpp Bird.hpp Reptile.hpp Zoo.hpp doctest.h
	$(CXX) $(CXXFLAGS) --compile test.cpp -o TestRunner.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

Animal.o: Animal.cpp Animal.hpp

Mammal.o: Mammal.cpp Mammal.hpp Animal.hpp

Bird.o: Bird.cpp Bird.hpp Animal.hpp

Reptile.o: Reptile.cpp Reptile.hpp Animal.hpp

Zoo.o: Zoo.cpp Zoo.hpp Animal.hpp Mammal.hpp Bird.hpp Reptile.hpp

main.o: main.cpp Animal.hpp Mammal.hpp Bird.hpp Reptile.hpp Zoo.hpp

clean:
	rm -f *.o demo test