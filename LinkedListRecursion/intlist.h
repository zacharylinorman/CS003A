#ifndef INTLIST_H
#define INTLIST_H


#include <iostream>
#include "intlistiterator.h"

using namespace std;

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

    void push_back(int value);

    /*********************************************************
     * popFront()
     *  Removes the front from the list
     *********************************************************/
    void pop_front();

    void select_sort();
    void insert_sorted(int value);
    void remove_duplicates();

    IntListIterator begin();
    IntListIterator end();

    int front() const;
    int back() const;
    int length() const;
    int sum() const;

    void reverseDisplay() const;

    IntList& operator=(const IntList& list);

};



#endif // INTLIST_H
