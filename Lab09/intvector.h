#ifndef INTVECTOR_H
#define INTVECTOR_H

// A vector of integers
class IntVector
{
private:
    unsigned sz; // SIZE
    unsigned cap; // CAPACITY
    int* data;   // POINTER TO VECTOR OF INTEGERS
public:
    // CONSTRUCTORS
    /**************************************************************
     * No parameters
     *  Size and cap 0
     **************************************************************/
    IntVector();

    /**************************************************************
     * One parameter
     *  Size and cap = unsigned size, data all 0s
     **************************************************************/
    IntVector(unsigned size);

    /**************************************************************
     * Two parameters
     *  Size and cap = unsigned size, data all = value
     **************************************************************/
    IntVector(unsigned size, int value);

    // PUBLIC FUNCTIONS
    /**************************************************************
     * size()
     *  Returns sz
     **************************************************************/
    unsigned size() const;

    /**************************************************************
     * capacity()
     *  returns cap
     **************************************************************/
    unsigned capacity() const;

    /**************************************************************
     * empty()
     *  Returns whether size == 9
     **************************************************************/
    bool empty() const;

    /**************************************************************
     * at()
     *  Returns the value at index
     **************************************************************/
    const int& at(unsigned index) const; // Index of value
};

#endif // INTVECTOR_H
