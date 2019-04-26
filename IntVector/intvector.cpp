#include "intvector.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

/**************************************************************
 * No parameters
 *  Size and cap 0
 **************************************************************/
IntVector::IntVector(){
    sz = 0;
    cap = 0;
}

/**************************************************************
 * One parameter
 *  Size and cap = unsigned size, data all 0s
 **************************************************************/
IntVector::IntVector(unsigned size){
    sz = size;
    cap = size;
    data = new int[size];
    for(unsigned i = 0; i < size; i++){
        data[i] = 0;
    }
}

/**************************************************************
 * Two parameters
 *  Size and cap = unsigned size, data all = value
 **************************************************************/
IntVector::IntVector(unsigned size, int value){
    sz = size;
    cap = size;
    data = new int[size];
    for(unsigned i = 0; i < size; i++){
        data[i] = value;
    }
}

/**************************************************************
 * expand()
 *  This function doubles the capacity
 **************************************************************/
void IntVector::expand(){
    if(cap == 0){
        cap++;
    }else{
        cap *= 2; // Double capacity
    }

    int* oldData = data; // Temporary pointer to current vector

    data = new int[cap]; // Allocate new memory

    // Fill new memory with vector
    for(unsigned i = 0; i < sz; i++){
        data[i] = oldData[i];
    }

    // Free old memory
    delete oldData;
}

/**************************************************************
 * expand()
 *  This function increases the capacity by the given amount
 **************************************************************/
void IntVector::expand(unsigned amount){ // The amount to increase cap by
    cap += amount; // Increase capacity by amount

    int* oldData = data; // Temporary pointer to current vector

    data = new int[cap]; // Allocate new memory

    // Fill new memory with vector
    for(unsigned i = 0; i < sz; i++){
        data[i] = oldData[i];
    }

    // Free old memory
    delete oldData;
}

/**************************************************************
 * size()
 *  Returns sz
 **************************************************************/
unsigned IntVector::size() const{
    return sz;
}

/**************************************************************
 * capacity()
 *  returns cap
 **************************************************************/
unsigned IntVector::capacity() const{
    return cap;
}

/**************************************************************
 * empty()
 *  Returns whether size == 9
 **************************************************************/
bool IntVector::empty() const{
    return sz == 0;
}

/**************************************************************
 * at()
 *  Returns the value at index
 **************************************************************/
const int& IntVector::at(unsigned index) const{ // Index of value
    if(index >= sz){
        exit(1);
    }
    return data[index];
}

/**************************************************************
 * at()
 *  Returns the value at index
 **************************************************************/
int& IntVector::at(unsigned index){ // Index of value
    if(index >= sz){
        exit(1);
    }
    return data[index];
}

/**************************************************************
 * front()
 *  Returns the first value of the vector
 **************************************************************/
const int& IntVector::front() const{
    return data[0];
}

/**************************************************************
 * front()
 *  Returns the first value of the vector
 **************************************************************/
int& IntVector::front(){
    return data[0];
}

/**************************************************************
 * back()
 *  Returns the last value of the vector
 **************************************************************/
const int& IntVector::back() const{
    return data[sz-1];
}

/**************************************************************
 * back()
 *  Returns the last value of the vector
 **************************************************************/
int& IntVector::back(){
    return data[sz-1];
}

/**************************************************************
 * insert()
 *  Inserts the value at the index
 **************************************************************/
void IntVector::insert(unsigned index, // Index of value to insert
                       int value){ // Value to insert
    if(index >= sz){
        exit(1);
    }
    if(sz == cap){ // No more capacity, double capacity
        expand();
    }

    // Shift values one to the right
    for(unsigned i = sz; i > index; i--){
        data[i] = data[i-1];
    }

    // Insert value
    data[index] = value;

    sz++;
}

/**************************************************************
 * erase()
 *  Erases the value at index
 **************************************************************/
void IntVector::erase(unsigned index){ // Index of value to erase
    if(index >= sz){
        exit(1);
    }

    // Shift values to the left
    for(unsigned i = index; i < sz; i++){
        data[i] = data[i+1];
    }
    sz--;
}

/**************************************************************
 * push_back()
 *  Inserts the value at the end of the array
 **************************************************************/
void IntVector::push_back(int value){ // Value to insert
    if(sz == cap){ // Needs more capacity
        expand();
    }
    data[sz] = value;
    sz++;
}

/**************************************************************
 * pop_back()
 *  Removes the last value of the vector
 **************************************************************/
void IntVector::pop_back(){
    if(empty()){ // Cannot pop_back empty vector
        exit(1);
    }
    sz--;
}

/**************************************************************
 * clear()
 *  Removes all values from the vector
 **************************************************************/
void IntVector::clear(){
    sz = 0;
}

/**************************************************************
 * resize()
 *  Resizes the vector to given size
 **************************************************************/
void IntVector::resize(unsigned size){ // New size of vector
    if(size > sz){ // New size greater than current
        if(size > cap){ // New size greater than capacity

            // Increase capacity by larger amount
            size > (cap * 2) ? expand(size - cap) : expand();
        }

        // Fill empty spaces with 0s
        for(unsigned i = sz; i < size; i++){
            data[i] = 0;
        }
    }
    sz = size;
}

/**************************************************************
 * resize()
 *  Resizes the vector to given size and fills extra spaces
 *  with value
 **************************************************************/
void IntVector::resize(unsigned size, int value){
    if(size > sz){// New size greater than current
        if(size > cap){ // New size greater than capacity

            // Increase capacity by larger amount
            size > (cap * 2) ? expand(size - cap) : expand();
        }

        // Fill empty spaces with value
        for(unsigned i = sz; i < size; i++){
            data[i] = value;
        }
    }
    sz = size;
}

/**************************************************************
 * reserve()
 *  Changes capacity to at least n if n is greater than size
 **************************************************************/
void IntVector::reserve(unsigned n){
    if(n >= sz){
        if(n > cap){
            n > (cap * 2) ? expand(n - cap) : expand();
        }
    }
}

/**************************************************************
 * assign()
 *  Replaces the vector with size n of values
 **************************************************************/
void IntVector::assign(unsigned n, // New size
                       int value){ // Values
    if(n > cap){ // New size greater than capacity

        // Increase capacity by larger amount
        n > (cap * 2) ? expand(n - cap) : expand();
    }
    sz = n;

    // Set all elements to value
    for(unsigned i = 0; i < sz; i++){
        data[i] = value;
    }
}

// DESTRUCTOR
IntVector::~IntVector(){
    if(cap > 0)
        delete data;
}


