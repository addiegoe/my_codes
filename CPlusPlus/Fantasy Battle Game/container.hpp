/*********************************************************
 ** Program Name: Project 4
 ** Author: Emily Addiego
 ** Date: November 24, 2019
 ** Description: This is the header file for the Container
 ** class. It has a struct for the nodes of the linked
 ** list, a constructor, a destructor, and functions
 ** to add to, subtract from, and print the list.
 ********************************************************/

#include<iostream>
#ifndef container_hpp
#define container_hpp
#include "character.hpp"

//Note: structure of class based on:
//https://stackoverflow.com/questions/40563173/linked-list-of-objects
class Container
{
protected:
    struct Node
    {
        Character *player;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *tail;
public:
    Container();
    ~Container();
    bool isEmpty();
    void addTop(Character *t);
    void addBottom(Character *b);
    void deleteTop();
    void movePlayer();
    void printList();
    void clearList();
    Character* getTop();
};

#endif
