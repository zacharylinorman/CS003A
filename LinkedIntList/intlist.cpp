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

void IntList::push_back(int value){
    IntNode* newIntNode;
    newIntNode = new IntNode(value);

    newIntNode->next = nullptr;

    if(tail == NULL){
        tail = newIntNode;
    }else if(head == NULL){
        head = tail;
        tail = newIntNode;
        head->next = tail;
    }else{
        tail->next = newIntNode;
        tail = newIntNode;
    }
}

void IntList::select_sort(){
    // 1. Make head smallest number
    // 2. Go from head of unsorted list to end to find min value
    // 3. SortedTail.next = min, SortedTail = min, min.prev.next = unshead

    IntNode* min = head;
    IntNode* currentPrev = head;
    IntNode* minPrev;
    while(currentPrev->next != NULL){
        if(currentPrev->next->data < min->data){
            minPrev = currentPrev;
            min = currentPrev->next;
        }
        currentPrev = currentPrev->next;
    }

    IntNode* tempMinNext = min->next;
    min->next = head->next;
    minPrev->next = head;
    head->next = tempMinNext;

    head = min;

    IntNode* sortedTail = head;
    IntNode* unsortedHead = head->next;

    while(unsortedHead != NULL){
        IntNode* min = unsortedHead;
        IntNode* currentPrev = min;
        IntNode* minPrev = sortedTail;
        while(currentPrev->next != NULL){
            if(currentPrev->next->data < min->data){
                minPrev = currentPrev;
                min = currentPrev->next;
            }
            currentPrev = currentPrev->next;
        }

        if(min != unsortedHead){
            IntNode* tempMinNext = min->next;
            if(minPrev == unsortedHead){
                min->next = unsortedHead;
                unsortedHead->next = tempMinNext;
            }else{
                min->next = unsortedHead->next;
                minPrev->next = unsortedHead;
                unsortedHead->next = tempMinNext;
            }

            sortedTail->next = min;


            sortedTail = min;
            unsortedHead = sortedTail->next;

        }else{
            sortedTail = unsortedHead;
            unsortedHead = unsortedHead->next;
        }
    }


}

void IntList::insert_sorted(int value){
    IntNode* newValue;
    newValue = new IntNode(value);

    IntNode* spot = head;
    while(spot->next != NULL){
        if(newValue->data < spot->next->data){
            break;
        }
        spot = spot->next;
    }
    IntNode* tempSpotNext = spot->next;
    spot->next = newValue;
    newValue->next = tempSpotNext;

}

void IntList::remove_duplicates(){
    IntNode* currentValue = head;
    IntNode* walker;
    while(currentValue != NULL){
        walker = currentValue;
        while(walker->next != NULL){
            if(walker->next->data == currentValue->data){
                IntNode* tempDuplicate = walker->next;
                walker->next = walker->next->next;
                delete tempDuplicate;
            }else{
                walker = walker->next;
            }
        }
        currentValue = currentValue->next;
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
