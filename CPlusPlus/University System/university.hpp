#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#ifndef university_hpp
#define university_hpp
#include "building.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"
using std::string;
using std::vector;

class University
{
private:
    string name;
    vector <Building> buildings{Building("Memorial Union", 303512, "2501 SW Jefferson Way, Corvallis, OR 97331") };
    vector <std::shared_ptr<Person>> people{std::make_shared<Instructor>("Remus Lupin", 34, 4.5, "Instructor"),
        std::make_shared<Student>("Hermione Granger", 18, 4.0, "Student")
    };
public:
    University();
    string getName();
    void printBuildings();
    void printPeople();
    int inputV(int min, int max);
    double doubleInputV(double min, double max);
    void peopleWork();
//functions for extra credit operations
    void getBuildings();
    void getPeople();
    void writeFile();
    void readFile();
    
   
};



#endif
