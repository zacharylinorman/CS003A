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
    if(index >= sz)
        exit(0);
    return data[index];
}

