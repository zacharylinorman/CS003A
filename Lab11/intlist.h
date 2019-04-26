#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>

using namespace std;

struct IntNode
{
    int data;
    IntNode *next;
    IntNode( int data ) : data(data), next(0) {}
};

class IntList
{
private:
    IntNode* head; // Head of the linked list
    IntNode* tail; // Tail of the linked list
public:
    /*********************************************************
     * IntList()
     *  Default constructor both head and tail are nullptr
     *********************************************************/
    IntList();

    /*********************************************************
     * ~IntList()
     *  Frees memory
     *********************************************************/
    ~IntList();

    /*********************************************************
     * display()
     *  Displays the list separated by spaces on one line
     *********************************************************/
    void display() const;

    /*********************************************************
     * pushFront()
     *  Adds the value to the front of the list
     *********************************************************/
    void push_front(int value); // Value to add to list

    /*********************************************************
     * popFront()
     *  Removes the front from the list
     *********************************************************/
    void pop_front();
};



#endif // INTLIST_H
