#Variables
CXX = g++
CXXFLAGS = -std=c++11

#Targets
lab4: main.o menu.o university.o building.o person.o student.o instructor.o
	${CXX} ${CXXFLAGS} main.o menu.o university.o building.o person.o student.o instructor.o -o lab4
main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp
menu.o: menu.cpp menu.hpp
	${CXX} ${CXXFLAGS} -c menu.cpp
university.o: university.cpp university.hpp
	${CXX} ${CXXFLAGS} -c university.cpp
building.o: building.cpp building.hpp
	${CXX} ${CXXFLAGS} -c building.cpp
person.o: person.cpp person.hpp
	${CXX} ${CXXFLAGS} -c person.cpp
student.o: student.cpp student.hpp
	${CXX} ${CXXFLAGS} -c student.cpp
instructor.o: instructor.cpp instructor.hpp
	${CXX} ${CXXFLAGS} -c instructor.cpp
clean:
	rm *.o lab4
