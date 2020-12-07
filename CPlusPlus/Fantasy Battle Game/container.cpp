/*******************************************************
** Program Name: Project 4
** Author: Emily Addiego
** Date: November 24, 2019
** Description: This is the cpp file for the container
** class. It contains a constructor, destructor, and
** member functions.
*******************************************************/
#include<iostream>
#include "container.hpp"

/******************************************************
 ** Description: This is the constructor for the Queue
 ** class. It sets the head node to NULL.
 ********************************************************/
Container::Container()
{
    head = NULL;
}


Container::~Container()
{
//check if container is empty
    if (head != NULL)
    {
//create a pointer to traverse container
        Node *traverse = head->next;
//while traverse isn't the head, go through list
        while (traverse != head)
        {
//delete each node as it goes through the list, also delete player object in Node
            Node *deleteAll = traverse;
            traverse = traverse->next;
	    delete deleteAll->player;
            delete deleteAll;
        }
//set head node to NULL
        delete head->player;
	delete head;
        head = NULL;
    }
}


/******************************************************
 ** Description: This is isEmpty function. It returns
 ** true if the queue is empty and false if the queue is
 ** not.
 ********************************************************/
bool Container::isEmpty()
{
    //if head=NULL, no values have been added and queue is empty
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/******************************************************
 ** Description: This is the addBottom function. If the
 ** queue is empty, it creates a new node and assigns the
 ** head, head->next, and head->prev to it. If the queue
 ** has 1+ elements, it creates a new node and inserts it
 ** after head->prev, creating a new tail of the list.
 ********************************************************/
void Container::addBottom(Character *c)
{
    //check if queue is empty
    if (head == NULL)
    {
//create and fill a new Node, assign to head
        Node *newQ = new Node;
        newQ->player = c;
        head = newQ;
//maintain circular structure by pointing head back at itself
        head->next = head;
        head->prev = head;
    }
//if queue isn't empty
    else
    {
//make a new Node
        Node *newQ = new Node;
        newQ->player = c;
//make a pointer to the tail of the list
        Node *tempTail = head->prev;
//set newQ as the end of the list
        newQ->prev = tempTail;
        newQ->next = head;
        tempTail->next = newQ;
        head->prev = newQ;
        
    }
}


/******************************************************
 ** Description: This is the getFront function. If the
 ** queue is not empty, it prints the value stored in
 ** the head node.
 ********************************************************/
Character* Container::getTop()
{
//if the queue is not empty, return the value stored in head
    if (!isEmpty())
    {
        return head->player;
    }
    else
    {
        return 0;
    }
}


/******************************************************
 ** Description: This is removeFront function. If the queue
 ** is not empty, it removes the node at the head of the
 ** queue and sets head->next to head. If there is only
 ** one element in the queue, it sets it to NULL.
 ********************************************************/
void Container::deleteTop()
{
//if the list is empty, print an error message
    if (isEmpty())
    {
        std::cout << "List is empty! Cannot remove elements." << std::endl;
    }
//if there is only one element, set it to NULL
    else if (head->next == head)
    {
        delete head;
        head = NULL;
    }
    else
    {
//create a temp node for head and tail
        Node *tempHead = head;
        Node *tempTail = head->prev;
//move head pointer to next position
        head = head->next;
//hook tail up to new head
        tempTail->next = head;
        head->prev = tempTail;
//delete old head node
        delete tempHead;
    }
}


/******************************************************
 ** Description: This is the printList function. It
 ** prints the head of the list, then traverses through
 ** the list, printing each element, until the head is
 ** reached again.
 ********************************************************/
void Container::printList()
{
    if (!isEmpty())
    {
        //print head value
        std::cout << head->player->getType() << ": ";
	std::cout << head->player->getName() << std::endl;
        //create pointers to head->next and head of list
        Node *traverse = head->next;
        Node *stop = head;
		while (traverse != stop)
		{
            std::cout << traverse->player->getType() << ": ";
	    std::cout << traverse->player->getName() << std::endl;
            traverse = traverse->next;
        }
    }
    else
    {
        std::cout << "List is empty. Cannot print." << std::endl;
    }
}


/***************************************************************
** Description: This is the addTop function. It takes a character
** pointer as a parameter and assigns it to a new node which is
** inserted at the head of the list.
***************************************************************/  
void Container::addTop(Character *c)
{
    if (head == NULL)
    {
//create and fill a new Node, assign to head
        Node *newN = new Node;
        newN->player = c;
        head = newN;
//maintain circular structure by pointing head back at itself
        head->next = head;
        head->prev = head;
    }
    else
    {
//create and fill new Node
        Node *newN = new Node;
        newN->player = c;
        Node *tempTail = head->prev;
        tempTail->next = newN;
//set new Node after the "tail" of the list and link it up
        newN->next = head;
        head->prev = newN;
        newN->prev = tempTail;
        head = newN;
        
    }
}


/************************************************************
** Description: This is the movePlayer function. It moves the
** top player to the bottom of the lineup.
************************************************************/
void Container::movePlayer()
{
//if there is more than 1 element in the list
    if (head != head->next)
    {
//assign temp node to head
        Node *tempHead = head;
        Node *tempTail = head->prev;
//move head to next
        head = head->next;
//set new temp head in head position and link it up
        head->prev = tempHead;
        tempTail->next = tempHead;
        tempHead->prev = tempTail;
        tempHead->next = head;
        head = tempHead;
    }
}


/*****************************************************************
** Description: This is the clearList function. It acts just like
** the destructor and clears the containers so the user can play
** again.
******************************************************************/
void Container::clearList()
{
//check if container is empty
    if (head != NULL)
    {
//create a pointer to traverse container
    Node *traverse = head->next;
//while traverse isn't the head, go through list
    while (traverse != head)
    {
//delete each node as it goes through the list, also delete player object in Node
    Node *deleteAll = traverse;
    traverse = traverse->next;
    delete deleteAll->player;
    delete deleteAll;
    }
//set head node to NULL
    delete head->player;
    delete head;
    head = NULL;
}
}
