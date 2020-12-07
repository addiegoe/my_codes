#Variables:
CXX = g++
CXXFLAGS = -std=c++0x

#Targets:
project4: main.o game.o character.o vampire.o barbarian.o harryPotter.o blueMan.o medusa.o container.o
	${CXX} ${CXXFLAGS} main.o character.o game.o vampire.o harryPotter.o blueMan.o medusa.o barbarian.o container.o -o project4
main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp
game.o: game.cpp game.hpp
	${CXX} ${CXXFLAGS} -c game.cpp
character.o: character.cpp character.hpp
	${CXX} ${CXXFLAGS} -c character.cpp
container.o: container.cpp container.hpp
	${CXX} ${CXXFLAGS} -c container.cpp
vampire.o: vampire.cpp vampire.hpp
	${CXX} ${CXXFLAGS} -c vampire.cpp
barbarian.o: barbarian.cpp barbarian.hpp
	${CXX} ${CXXFLAGS} -c barbarian.cpp
medusa.o: medusa.cpp medusa.hpp
	${CXX} ${CXXFLAGS} -c medusa.cpp
harryPotter.o: harryPotter.cpp harryPotter.hpp
	${CXX} ${CXXFLAGS} -c harryPotter.cpp
blueMan.o: blueMan.cpp blueMan.hpp
	${CXX} ${CXXFLAGS} -c blueMan.cpp
clean:
	rm *.o project4
