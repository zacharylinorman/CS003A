#include "intlist.h"

#include <iostream>

using namespace std;

/*********************************************************
 * IntList()
 *  Default constructor both head and tail are nullptr
 *********************************************************/
IntList::IntList()
{
    head = nullptr;
    tail = nullptr;
}


/*********************************************************
 * display()
 *  Displays the list separated by spaces on one line
 *********************************************************/
void IntList::display() const{
    // Choose starting node: if nothing in head, use tail as start node
    IntNode* current = head != NULL ? head : tail;

    // Loop through list to display data
    while(current != NULL){
        cout << current->data;
        current = current->next;
        if(current != NULL){
            cout << " ";
        }
    }
}

/*********************************************************
 * pushFront()
 *  Adds the value to the front of the list
 *********************************************************/
void IntList::push_front(int value){
    IntNode* newIntNode;
    newIntNode = new IntNode(value);

    // Nothing in list yet, new value is tail
    if(tail == NULL){
        newIntNode->next = nullptr;
        tail = newIntNode;

    // Second node in list, new value is head
    }else if(head == NULL){
        newIntNode->next = tail;
        head = newIntNode;

    // Add value to front of list
    }else{
        newIntNode->next = head;
        head = newIntNode;
    }
}

/*********************************************************
 * popFront()
 *  Removes the front from the list
 *********************************************************/
void IntList::pop_front(){
    //IntNode* temp = head;
    head = head->next;
    //delete temp;
}

/*********************************************************
 * ~IntList()
 *  Frees memory
 *********************************************************/
IntList::~IntList(){
    IntNode* current = head;
    while(current != NULL){
        IntNode* temp = current;
        current = current->next;
        delete temp;
    }
}
