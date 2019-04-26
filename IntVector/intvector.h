#ifndef INTVECTOR_H
#define INTVECTOR_H

// A vector of integers
class IntVector
{
private:
    unsigned sz; // SIZE
    unsigned cap; // CAPACITY
    int* data;   // POINTER TO VECTOR OF INTEGERS

    /**************************************************************
     * expand()
     *  This function doubles the capacity
     **************************************************************/
    void expand();

    /**************************************************************
     * expand()
     *  This function increases the capacity by the given amount
     **************************************************************/
    void expand(unsigned amount); // The amount to increase cap by
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

    // DESTRUCTOR - Frees memory
    ~IntVector();

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

    /**************************************************************
     * at()
     *  Returns the value at index
     **************************************************************/
    int& at(unsigned index); // Index of value

    /**************************************************************
     * insert()
     *  Inserts the value at the index
     **************************************************************/
    void insert(unsigned index, // Index of value to insert
                int value); // Value to insert

    /**************************************************************
     * erase()
     *  Erases the value at index
     **************************************************************/
    void erase(unsigned index); // Index of value to erase

    /**************************************************************
     * front()
     *  Returns the first value of the vector
     **************************************************************/
    const int& front() const;

    /**************************************************************
     * front()
     *  Returns the first value of the vector
     **************************************************************/
    int& front();

    /**************************************************************
     * back()
     *  Returns the last value of the vector
     **************************************************************/
    const int& back() const;

    /**************************************************************
     * back()
     *  Returns the last value of the vector
     **************************************************************/
    int& back();

    /**************************************************************
     * assign()
     *  Replaces the vector with size n of values
     **************************************************************/
    void assign(unsigned n, // New size
                int value); // Values

    /**************************************************************
     * push_back()
     *  Inserts the value at the end of the array
     **************************************************************/
    void push_back(int value); // Value to insert

    /**************************************************************
     * pop_back()
     *  Removes the last value of the vector
     **************************************************************/
    void pop_back();

    /**************************************************************
     * clear()
     *  Removes all values from the vector
     **************************************************************/
    void clear();

    /**************************************************************
     * resize()
     *  Resizes the vector to given size
     **************************************************************/
    void resize(unsigned size); // New size of vector

    /**************************************************************
     * resize()
     *  Resizes the vector to given size and fills extra spaces
     *  with value
     **************************************************************/
    void resize(unsigned size, // New size of vector
                int value); // Fill value

    /**************************************************************
     * reserve()
     *  Changes capacity to at least n if n is greater than size
     **************************************************************/
    void reserve(unsigned n); // New value of capacity
};

#endif // INTVECTOR_H
