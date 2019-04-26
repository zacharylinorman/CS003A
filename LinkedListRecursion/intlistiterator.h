#ifndef INTLISTITERATOR_H
#define INTLISTITERATOR_H

#include <iostream>

using namespace std;

struct IntNode
{
    int data;
    IntNode *next;
    IntNode( int data ) : data(data), next(0) {}
};

class IntListIterator
{
private:
    IntNode* current;
public:
    IntListIterator();
    IntListIterator( IntNode *ptr);
    int operator*();

    IntListIterator operator++();
    bool operator==(const IntListIterator& right) const;
    bool operator!=(const IntListIterator& right) const;

};

#endif // INTLISTITERATOR_H
