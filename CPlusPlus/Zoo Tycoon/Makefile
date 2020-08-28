#Variables
CXX = g++
CXXFLAGS = -std=c++0x

#Targets
project2: main.o zoo.o animal.o tiger.o turtle.o penguin.o animal4.o
	${CXX} ${CXXFLAGS} main.o zoo.o animal.o tiger.o turtle.o penguin.o animal4.o -o project2
main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp
zoo.o: zoo.cpp zoo.hpp
	${CXX} ${CXXFLAGS} -c zoo.cpp
animal.o: animal.cpp animal.hpp
	${CXX} ${CXXFLAGS} -c animal.cpp
tiger.o: tiger.cpp tiger.hpp
	${CXX} ${CXXFLAGS} -c tiger.cpp
turtle.o: turtle.cpp turtle.hpp
	${CXX} ${CXXFLAGS} -c turtle.cpp
penguin.o: penguin.cpp penguin.hpp
	${CXX} ${CXXFLAGS} -c penguin.cpp
animal4.o: animal4.cpp animal4.hpp
	${CXX} ${CXXFLAGS} -c animal4.cpp
clean:
	rm *.o project2

#Source: Makefile lecture on course website
