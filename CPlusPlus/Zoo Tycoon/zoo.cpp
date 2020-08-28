/******************************************************************************
 ** Program Name: Project 2
 ** Author: Emily Addiego
 ** Date: October 27, 2019
 ** Description: This is the cpp file for the Zoo class. It contains a
 ** constructor and member functions.
 ******************************************************************************/
#include "zoo.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
using std::string;

/******************************************************************************
 ** Description: This is a constructor for the Zoo class. It initializes all
 ** animal numbers to 0, all capacities to 10, the bank to 100000, the dailyPay
 ** and foodCharge to 0.
 ******************************************************************************/
Zoo::Zoo()
{
    turtNum = 0;
    tigNum = 0;
    penNum = 0;
    animal4Num = 0;
    tigCapacity = 10;
    turtCapacity = 10;
    penCapacity = 10;
    animal4Capacity = 10;
    tigerBaby = false;
    penguinBaby = false;
    turtleBaby = false;
    a4Baby = false;
    bank = 100000;
    dailyPay = 0;
    foodCharge = 0;
    
}

/******************************************************************************
 ** Description: This is the menu function. It asks the user to play or quit.
 ** If the user chooses to play, it calls functions to make animal arrays,
 ** and play the game. If the user chooses to quit, the program ends. If
 ** the user is out of money, the program ends. The menu deletes the arrays
 ** after the user quits.
 ******************************************************************************/
void Zoo::menu()
{
    std::cout << "Welcome to Zoo Tycoon. Please enter 1 start or 2 to quit." << std::endl;
    int choice = inputV(0, 3);
//begin game
    if ((choice == 1) && (bank > 0))
    {
//make arrays
        makeArrays();
//make a new animal -- extra credit option
        makeNewAnimal();
        do {
//run game loop
            runGame();
//prompt to play again or quit
            std::cout << "Would you like to play again? Enter 1 for yes or 2 for no." << std::endl;
            choice = inputV(0, 3);
            std::cout << '\n';
//kick player out and print message if there is no money in bank
            if (bank <= 0)
            {
                std::cout << "Sorry, you're out of money. Goodbye." << std::endl;
            }
        } while ((choice == 1) && (bank > 0));
    }
//free dynamically allocated arrays
    deleteArrays();
}


/******************************************************************************
 ** Description: This is the inputV function. It takes two parameters an int
 ** min and an int max. It uses getline to get the entire user input, converts
 ** the input to a stream, then checks if the stream is an integer between the
 ** min and the max. If it is not, the function asks for input in a loop until
 ** correct input is entered. This function is reused from Project 1 and is
 ** based on Cuddlebuddie928's function from the following thread:
 ** http://www.cplusplus.com/forum/beginner/58833/
 ******************************************************************************/
int Zoo::inputV(int min, int max)
{
    int n;
    string s;
    
    while(true) {
        //use getline to get entire line
        getline(std::cin, s);
        //convert string to stream
        std::stringstream convert(s);
        //check if stream is an integer and if it is within the minmum and maximum range
        if((convert >> n) && (!(convert >> s)) && (n > min) && (n < max))
        {
            return n;
        }
        else
        {
            std::cin.clear();
            std::cout << "Incorrect input. Try again." << std::endl;
        }
    }
}

/******************************************************************************
 ** Description: This is the runGame function. It ages up the animals, calls
 ** feedAnimals to feed the animals, randomEvent to generate a random event,
 ** then asks the user if they want to buy a new animal at the end of the day.
 ******************************************************************************/
void Zoo::runGame()
{
    std::cout << "Good morning! It's a beautiful day at the zoo!" << std::endl;
//increase animal age by one day
    for (int i = 0; i < tigNum; i++)
    {
        tigers[i].setAge(1);
    }
    for (int i = 0; i < penNum; i++)
    {
        penguins[i].setAge(1);
    }
    for (int i = 0; i < turtNum; i++)
    {
        turtles[i].setAge(1);
    }
    for (int i = 0; i < animal4Num; i++)
    {
        fourthArray[i].setAge(1);
    }
//feed animals
    feedAnimals();
//call random event
    randomEvent();
//calculate profit
    dailyPay = tigNum * 2000 + turtNum * 5 + penNum * 100 + animal4Num * a4Payoff;
    std::cout << "You made a profit today of $" << dailyPay << std::endl;
    bank = bank + dailyPay;
    std::cout << "You now have $" << bank << " in the bank." << std::endl;
//prompt to buy an adult animal
    std::cout << "Would you like to buy an adult animal? Enter 1 for yes or 2 for no." << std::endl;
    int buy = inputV(0, 3);
    if (buy == 1)
    {
        std::cout << "Enter 1 to buy a tiger, 2 to buy a penguin, 3 to buy a turtle, or 4 to buy a " << a4Name << "." << std::endl;
        int animalChoice = inputV(0, 5);
        if (animalChoice == 1)
        {
            addTigers(tigers);
//age the animal to make it an adult
            tigers[tigNum - 1].setAge(3);
            bank = bank - 10000.00;
            std::cout << "You've bought a tiger. You now have $" << bank << " dollars in the bank." << std::endl;
        }
        else if (animalChoice == 2)
        {
            addPenguins(penguins);
            penguins[penNum - 1].setAge(3);
            bank = bank - 1000.00;
            std::cout << "You've bought a penguin. You now have $" << bank << " dollars in the bank." << std::endl;
        }
        else if (animalChoice == 3)
        {
            addTurtles(turtles);
            turtles[turtNum - 1].setAge(3);
            bank = bank - 500.00;
            std::cout << "You've bought a turtle. You now have $" << bank << " dollars in the bank." << std::endl;
        }
        else if (animalChoice == 4)
        {
            addFourth(fourthArray);
            fourthArray[animal4Num - 1].setAge(3);
            bank = bank - a4Cost;
            std::cout << "You've bought a " << a4Name << ". You now have $" << bank << " dollars in the bank." << std::endl;
        }
    }
}

/******************************************************************************
 ** Description: This is the makeArrays function. It dynamically allocates
 ** four arrays, one for each animal, and fills them with either 1 or 2 new
 ** animals based on user input.
 ******************************************************************************/
void Zoo::makeArrays()
{
//create arrays
    tigers = new Tiger[0];
    penguins = new Penguin[0];
    turtles = new Turtle[0];
    fourthArray = new Animal4[0];
    //prompt to buy animals
    std::cout << "You need to buy some animals to fill your zoo. You can buy 1 or 2 of each animal." << std::endl;
    std::cout << "Tigers cost $10,000 each. How many tigers would you like to buy?" << std::endl;
    int tNumber = inputV(0, 3);
    //add tigers to array
    for (int i =0; i < tNumber; i++)
    {
        addTigers(tigers);
        tigers[i].setAge(1);
    }
    std::cout << "Penguins cost $1,000 each. How many penguins would you like to buy?" << std::endl;
    int pNumber = inputV(0, 3);
    //add penguins to array
    for (int i =0; i < pNumber; i++)
    {
        addPenguins(penguins);
        penguins[i].setAge(1);
    }
    std::cout << "Turtles cost $500 each. How many turtles would you like to buy?" << std::endl;
    int trNumber = inputV(0, 3);
    //add turtles to array
    for (int i = 0; i < trNumber; i++)
    {
        addTurtles(turtles);
        turtles[i].setAge(1);
    }
    //calculate cost
    int cost = (tigNum * 10000) + (turtNum * 500) + (penNum * 1000);
    std::cout << "The total cost is: " << cost << std::endl;
    bank = bank - cost;
    std::cout << "You now have $" << bank << std::endl;
}


/******************************************************************************
 ** Description: This is the deleteArrays function. It frees the dynamically
 ** allocated arrays to prevent memory leaks.
 ******************************************************************************/
void Zoo::deleteArrays()
{
    //free dynamic arrays
    delete[] tigers;
    tigers = nullptr;
    delete[] turtles;
    turtles = nullptr;
    delete[] penguins;
    penguins = nullptr;
    delete[] fourthArray;
    fourthArray = nullptr;

}

/******************************************************************************
 ** Description: This is the feedAnimals function. It calculates the cost
 ** of food for the animals in the zoo and prompts the user to feed the animals
 ** by enter 1, then shows the remaining balance in the bank.
 ******************************************************************************/
void Zoo::feedAnimals()
{
    std::cout << "You need to feed your animals. The cost of food is:" << std::endl;
    std::cout << "Tigers: $" << (50 * tigNum) << std::endl;
    std::cout << "Penguins: $" << (10 * turtNum) << std::endl;
    std::cout << "Turtles: $" << (5 * turtNum) << std::endl;
    std::cout << a4Name << "s: $" << (a4BFC * animal4Num) << std::endl;
//calculate food cost
    int totalFoodCost = (50 * tigNum) + (10 * turtNum) + (5 * turtNum) + (a4BFC * animal4Num);
    std::cout << "Total: $" << totalFoodCost << std::endl;
    std::cout << "Enter 1 to feed your animals." << std::endl;
    inputV(0, 2);
//subtract from bank
    std::cout << "Thank you. You now have $" << bank - totalFoodCost << " in the bank." << std::endl;
    bank -= totalFoodCost;
    
}

/******************************************************************************
 ** Description: This is the randomEvent function. It generates a random number,
 ** from 1-4,then calls either sickness, haveBabies, attendanceBoom, or prints a
 ** message that nothing happened, depending on the number.
 ******************************************************************************/
void Zoo::randomEvent()
{
    std::srand(time(NULL));
    int n = std::rand() % 4 + 1;
    if (n == 1)
    {
        sickness();
    }
    else if (n == 2)
    {
        attendanceBoom();
    }
    else if (n == 3)
    {
        haveBaby();
    }
    else if (n == 4)
    {
        std::cout << "Nothing happened at the zoo today." << std::endl;
    }
}


/******************************************************************************
 ** Description: This is the sickness function. It generates a random number,
 ** then chooses a type of animal to die based on the number. If the array
 ** already has no animals, it moves to the next type of animal. If no animals
 ** are alive in the zoo, it prints an error message.
 ******************************************************************************/
void Zoo::sickness()
{
    std::srand(time(NULL));
    int n = (std::rand() % 4) + 1;
    if ((n == 1) && (tigNum > 0))
    {
        
        deleteTigers(tigers);
        std::cout << "Sadly, a tiger got sick and died today. You now have " << tigNum << " tiger(s)." << std::endl;
    }
    else if ((n == 2) && (penNum > 0))
    {
        deletePenguins(penguins);
        std::cout << "Sadly, a penguin got sick and died today. You now have " << penNum << " penguin(s)." << std::endl;
        
    }
    else if ((n == 3) && (turtNum > 0))
    {
        deleteTurtles(turtles);
        std::cout << "Sadly, a turtle got sick and died today. You now have " << turtNum << " turtle(s)." << std::endl;
    }
    else if ((n == 4) && (animal4Num > 0))
    {
        deleteFourth(fourthArray);
    std::cout << "Sadly, a " << a4Name << " got sick and died today. You now have " << animal4Num << " " << a4Name << "s in the zoo." << std::endl;
    }
    else
    {
        if (tigNum > 0)
        {
            deleteTigers(tigers);
            std::cout << "Sadly, a tiger got sick and died today. You now have " << tigNum << " tiger(s)." << std::endl;
        }
        else if (penNum > 0)
        {
            deletePenguins(penguins);
            std::cout << "Sadly, a penguin got sick and died today. You now have " << penNum << " penguin(s)." << std::endl;
        }
        else if (turtNum > 0)
        {
            deleteTurtles(turtles);
            std::cout << "Sadly, a turtle got sick and died today. You now have " << turtNum << " turtle(s)." << std::endl;
        }
        else if (animal4Num > 0)
        {
            deleteFourth(fourthArray);
            std::cout << "Sadly, a " << a4Name << " got sick and died today. You now have " << animal4Num << " " << a4Name << "s in the zoo." << std::endl;
        }
        else
        {
            std::cout << "All animals in the zoo have died. Please buy more animals." << std::endl;
        }
    }
}


/******************************************************************************
 ** Description: This is the attendanceBoom function. It generates a random
 ** number between 250 and 500, then multiplies that number by the number of
 ** tigers in order to generate a bonus. It then adds the bonus to the payoff
 ** and prints a message.
 ******************************************************************************/
void Zoo::attendanceBoom()
{
    std::srand(time(NULL));
    int n = std::rand() % (500 - 251) + 250;
    int bonus = n * tigNum;
    std::cout << "A lot of people came to the zoo today! You earned a bonus profit of " << bonus << "!" << std::endl;
    dailyPay += bonus;
}


/******************************************************************************
 ** Description: This is the haveBaby function. It generates a random number,
 ** then chooses a type of animal to have babies based on the number. If
 ** the array has no adult animals, it moves to the next type of animal. It
 ** uses bool flags to indicate whether animals can have babies. If there are
 ** no adult animals in the zoo, it prints an error message.
 ******************************************************************************/
void Zoo::haveBaby()
{
//generate a random number
    std::srand(time(NULL));
    int n = std::rand() % 4 + 1;
//check if any animals can have babies
    for (int i = 0; i < tigNum; i++)
    {
        if (tigers[i].getAge() >= 3)
        {
            tigerBaby = true;
        }
    }
    for (int i = 0; i < penNum; i++)
    {
        if (penguins[i].getAge() >= 3)
        {
            penguinBaby = true;
        }
    }
    for (int i = 0; i < turtNum; i++)
    {
        if (turtles[i].getAge() >= 3)
        {
            turtleBaby = true;
        }
    }
    for (int i = 0; i < animal4Num; i++)
    {
        if (fourthArray[i].getAge() >= 3)
        {
            a4Baby = true;
        }
    }
//if-statements to go through each group of animals based on the randomly generated number
    if ((n == 1) && (tigerBaby == true))
    {
        addTigers(tigers);
        std::cout << "The tigers had a baby! You now have " << tigNum << " tigers in the zoo." << std::endl;
    }
    else if ((n == 2) && (penguinBaby == true))
    {
        for (int i = 0; i < 5; i++)
        {
            addPenguins(penguins);
        }
        std::cout << "The penguins had 5 babies! You now have " << penNum << " penguins in the zoo." << std::endl;
    }
    else if ((n == 3) && (turtleBaby == true))
    {
        for (int i = 0; i < 10; i++)
        {
            addTurtles(turtles);
        }
        std::cout << "The turtles had 10 babies! You now have " << turtNum << " turtles in the zoo." << std::endl;
    }
    else if ((n == 4) && (a4Baby == true))
    {
        for (int i = 0; i < a4NumBabies; i++)
        {
            addFourth(fourthArray);
        }
        std::cout << "The " << a4Name << "s had " << a4NumBabies <<  " babies! You now have " << animal4Num << " " << a4Name << "s in the zoo." << std::endl;
    }
    //if above conditions are not met, see if any animals can have babies
    else
    {
        if (tigerBaby == true)
        {
            addTigers(tigers);
            std::cout << "The tigers had a baby! You now have " << tigNum << " tigers in the zoo." << std::endl;
        }
        else if (penguinBaby == true)
        {
            for (int i = 0; i < 5; i++)
            {
                addPenguins(penguins);
            }
            std::cout << "The penguins had 5 babies! You now have " << penNum << " penguins in the zoo." << std::endl;
        }
        else if (turtleBaby == true)
        {
            for (int i = 0; i < 10; i++)
            {
                addTurtles(turtles);
            }
            std::cout << "The turtles had 10 babies! You now have " << turtNum << " turtles in the zoo." << std::endl;
        }
        else if (a4Baby == true)
        {
            for (int i = 0; i < a4NumBabies; i++)
            {
                addFourth(fourthArray);
            }
        std::cout << "The " << a4Name << "s had " << a4NumBabies <<  "babies! You now have " << animal4Num << " " << a4Name << "s in the zoo." << std::endl;
        }
        //print error message if animals can't have babies
        else
        {
            std::cout << "Your animals are too young to have babies. Please be patient!" << std::endl;
        }
    
}
}

/*****************************************************************************
** Description: This is the deleteTigers function. It takes a pointer to a
** reference to an array and resizes the array to be one element smaller.
** If there is an adult animal in the array, it makes sure the animal is
** still there.
** Source: https://stackoverflow.com/questions/22123809/resizing-a-dynamic-array-of-objects-in-c
 *****************************************************************************/
void Zoo::deleteTigers(Tiger *&array)
{
    Tiger *temp= new Tiger[tigNum - 1];
    delete []array;
    array = temp;
    tigNum -= 1;
    if (tigerBaby == true)
    {
        tigers[0].setAge(3);
    }
    
}


/*****************************************************************************
 ** Description: This is the deletePenguins function. It takes a pointer to a
 ** reference to an array and resizes the array to be one element smaller.
 ** If there is an adult animal in the array, it makes sure the animal is
 ** still there.
 ** Source: https://stackoverflow.com/questions/22123809/resizing-a-dynamic-array-of-objects-in-c
 *****************************************************************************/
void Zoo::deletePenguins(Penguin *&array)
{
    Penguin *temp= new Penguin[penNum - 1];
    delete []array;
    array = temp;
    penNum -= 1;
    if (penguinBaby == true)
    {
        penguins[0].setAge(3);
    }
}


/*****************************************************************************
 ** Description: This is the deleteTurtles function. It takes a pointer to a
 ** reference to an array and resizes the array to be one element smaller.
 ** If there is an adult animal in the array, it makes sure the animal is
 ** still there.
 ** Source: https://stackoverflow.com/questions/22123809/resizing-a-dynamic-array-of-objects-in-c
 *****************************************************************************/
void Zoo::deleteTurtles(Turtle *&array)
{
    Turtle *temp= new Turtle[turtNum - 1];
    delete []array;
    array = temp;
    turtNum -= 1;
    if (turtleBaby == true)
    {
        turtles[0].setAge(3);
    }
}


/*****************************************************************************
 ** Description: This is the addTigers function. It takes a pointer to a
 ** reference to an array and resizes the array to be one element larger.
 ** If the size of the array is at capacity, it resizes the capacity to be
 ** two times larger. If there is an adult animal in the array, it makes sure the
 ** animal is still there.
 ** Source: https://stackoverflow.com/questions/22123809/resizing-a-dynamic-array-of-objects-in-c
 *****************************************************************************/
void Zoo::addTigers(Tiger *&array)
{
    if ((tigNum + 1) == tigCapacity)
    {
        tigCapacity = tigCapacity * 2;
    }
    
    Tiger *temp= new Tiger[tigNum + 1];
    delete []array;
    array = temp;
    tigNum += 1;
    if (tigerBaby == true)
    {
        tigers[0].setAge(3);
    }
    
}


/*****************************************************************************
 ** Description: This is the addPenguins function. It takes a pointer to a
 ** reference to an array and resizes the array to be one element larger.
 ** If the size of the array is at capacity, it resizes the capacity to be
 ** two times larger. If there is an adult animal in the array, it makes sure the
 ** animal is still there.
 ** Source: https://stackoverflow.com/questions/22123809/resizing-a-dynamic-array-of-objects-in-c
 *****************************************************************************/
void Zoo::addPenguins(Penguin *&array)
{
    if ((penNum + 1) == penCapacity)
    {
        penCapacity = penCapacity * 2;
    }
    Penguin *temp= new Penguin[penNum + 1];
    delete []array;
    array = temp;
    penNum += 1;
    if (penguinBaby == true)
    {
        penguins[0].setAge(3);
    }
}


/*****************************************************************************
 ** Description: This is the addTurtles function. It takes a pointer to a
 ** reference to an array and resizes the array to be one element larger.
 ** If the size of the array is at capacity, it resizes the capacity to be
 ** two times larger. If there is an adult animal in the array, it makes sure the
 ** animal is still there.
 ** Source: https://stackoverflow.com/questions/22123809/resizing-a-dynamic-array-of-objects-in-c
 *****************************************************************************/
void Zoo::addTurtles(Turtle *&array)
{
    if ((turtNum + 1) == turtCapacity)
    {
        turtCapacity = turtCapacity * 2;
    }
    Turtle *temp= new Turtle[turtNum + 1];
    delete []array;
    array = temp;
    turtNum += 1;
    if (turtleBaby == true)
    {
        turtles[0].setAge(3);
    }
    
}


/*****************************************************************************
 ** Description: This is the deleteFourth function. It takes a pointer to a
 ** reference to an array and resizes the array to be one element smaller.
 ** If there is an adult animal in the array, it makes sure the animal is
 ** still there.
 ** Source: https://stackoverflow.com/questions/22123809/resizing-a-dynamic-array-of-objects-in-c
 *****************************************************************************/
void Zoo::deleteFourth(Animal4 *&array)
{
    Animal4 *temp= new Animal4[animal4Num - 1];
    delete []array;
    array = temp;
    animal4Num -= 1;
    if (a4Baby == true)
    {
        fourthArray[0].setAge(3);
    }
}


/*****************************************************************************
 ** Description: This is the addFourth function. It takes a pointer to a
 ** reference to an array and resizes the array to be one element larger.
 ** If the size of the array is at capacity, it resizes the capacity to be
 ** two times larger. It also initalizes the objects.
 ** Source: https://stackoverflow.com/questions/22123809/resizing-a-dynamic-array-of-objects-in-c
 *****************************************************************************/
void Zoo::addFourth(Animal4 *&array)
{
    if ((animal4Num + 1) == animal4Capacity)
    {
        animal4Capacity = animal4Capacity * 2;
    }
    
    Animal4 *temp= new Animal4[animal4Num + 1];
    delete []array;
    array = temp;
    animal4Num += 1;
//initialize objects
    for (int i = 0; i < animal4Num; i++)
    {
        fourthArray[i].setCost(a4Cost);
        fourthArray[i].setFoodCost(a4BFC);
        fourthArray[i].setPayoff(a4Payoff);
        fourthArray[i].setNumBabies(a4NumBabies);
    }
    if (a4Baby == true)
    {
        fourthArray[0].setAge(3);
    }
    
}


/*****************************************************************************
 ** Description: This is the makeNewAnimal function. It prompts the user to
 ** enter information about a new animal, then saves the information in
 ** member variables, lets the user buy 1 or 2 new animals, and allocates
 ** a new array of the fourth animal.
 *****************************************************************************/
void Zoo::makeNewAnimal()
{
    std::string n;
    std::cout << "For extra credit, please add a new animal to the zoo. What kind of animal would you like to add?" << std::endl;
//get the type of animal
    getline(std::cin, n);
    a4Name = n;
//get the cost of the animal
    std::cout << "How much does the animal cost? (Choose a cost between $100 and $10000)." << std::endl;
    int cost = inputV(99, 10001);
    a4Cost = cost;
//get base food cost
    std::cout << "How much does the animal's food cost? (Choose a cost between $10 and $50)." << std::endl;
     int baseFood = inputV(9, 51);
     a4BFC = baseFood;
//get payoff
    std::cout << "What is the animal's payoff per day? (Choose a number between 5 and 2000)." << std::endl;
    int pay = inputV(4, 2001);
    a4Payoff = pay;
//get number of babies
    std::cout << "How many babies can the animal have? (Choose a number between 1 and 10)." << std::endl;
    int babies = inputV(0, 11);
    a4NumBabies = babies;
//buy a new animal
    std::cout << "You can now buy 1 or 2 " << a4Name << "s. How many would you like to buy?" << std::endl;
    int a4Choice = inputV(0, 3);
//add animals to array
    for (int i =0; i < a4Choice; i++)
    {
        addFourth(fourthArray);
        fourthArray[i].setAge(1);
    }
//subtract cost of animals fom the bank
    int totalCost = animal4Num * a4Cost;
    bank -= totalCost;
    std::cout << "You now have $" << bank << " in the bank." << std::endl;
    
}

