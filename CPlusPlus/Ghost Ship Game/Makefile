#Variables:
CXX = g++
CXXFLAGS = -std=c++0x

#Targets:
final: main.o game.o ship.o space.o stairs.o deck.o bridge.o diningRoom.o kitchen.o
	${CXX} ${CXXFLAGS} main.o game.o ship.o space.o stairs.o deck.o bridge.o diningRoom.o kitchen.o -o final
main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp
game.o: game.cpp game.hpp
	${CXX} ${CXXFLAGS} -c game.cpp
ship.o: ship.cpp ship.hpp
	${CXX} ${CXXFLAGS} -c ship.cpp
space.o: space.cpp space.hpp
	${CXX} ${CXXFLAGS} -c space.cpp
stairs.o: stairs.cpp stairs.hpp
	${CXX} ${CXXFLAGS} -c stairs.cpp
deck.o: deck.cpp deck.hpp
	${CXX} ${CXXFLAGS} -c deck.cpp
bridge.o: bridge.cpp bridge.hpp
	${CXX} ${CXXFLAGS} -c bridge.cpp
diningRoom.o: diningRoom.cpp diningRoom.hpp
	${CXX} ${CXXFLAGS} -c diningRoom.cpp
kitchen.o: kitchen.cpp kitchen.hpp
	${CXX} ${CXXFLAGS} -c kitchen.cpp
clean:
	rm *.o final
