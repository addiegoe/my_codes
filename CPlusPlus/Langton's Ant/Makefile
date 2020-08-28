project1: main.o ant.o menu.o
	g++ main.o ant.o menu.o -o project1
main.o: main.cpp
	g++ -c main.cpp
ant.o: ant.cpp ant.hpp
	g++ -c ant.cpp
menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp
clean:
	rm *.o project1
	  
