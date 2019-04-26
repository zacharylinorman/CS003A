/****************************************************************
 * AUTHOR        : Zachary Norman and Jeffrey Chen
 * ASSIGNMENT    : Lab 05
 * CLASS         : CS03A
 * SECTION       : MW: 1-2:25, TH: 1-3:05
 * DUE DATE      : 3/7/19
 ****************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/****************************************************************
 * Lab 05
 * ______________________________________________________________
 * This program tests the vector class
 * ______________________________________________________________
 * OUTPUT:
 *      Test cases for the vector class.
 *
 ****************************************************************/

// PROTOTYPES

/****************************************************************
 * testEmptyMemberFunction()
 *  This functions tests to see if the given vector is empty. It
 *  will print a message and return a bool value accordingly
 ****************************************************************/
bool testEmptyMemberFunction(const vector<int> &v); // The vector to test

/****************************************************************
 * displaySizeAndCapacity()
 *  This functions displays the given vector's size and capacity
 ****************************************************************/
void displaySizeAndCapacity(const vector<int> &v); // The vector to display

/****************************************************************
 * displayVector()
 *  This functions displays the given vector's contents
 ****************************************************************/
void displayVector(const vector<int> &v); // The vector to display

/****************************************************************
 * testConstructor()
 *  This functions runs tests for the constructor behavior of
 *  the given vector.
 ****************************************************************/
void testConstructor(const vector<int> &v, // The vector to test
                     string vectorName); // The name of the vector


int main()
{
    // VECTOR DECLARATIONS
    vector<int> v;          // DEFAULT
    vector<int> v2(5);      // ONE PARAMETER
    vector<int> v3(5, 9);   // TWO PARAMETERS


    // CONSTRUCTOR TESTS
    cout << "Testing default constructor" << endl;
    testConstructor(v, "v");

    cout << "Testing One parameter constructor" << endl;
    testConstructor(v2, "v2");

    cout << "Testing Two parameter constructor" << endl;
    testConstructor(v3, "v3");

    // PUSH_BACK FUNCTION TEST
    cout << "Testing push back function" << endl;
    for(int i = 0; i < 10; i++){ // Push back 10 times
        v.push_back(i);
        displaySizeAndCapacity(v); // Display size and capacity after each
    }
    cout << endl;

    // POP BACK FUNCTION TEST
    cout << "Testing pop back function" << endl;
    // Perform two pop_backs and display size and capacity after each
    v.pop_back();
    displaySizeAndCapacity(v);
    v.pop_back();
    displaySizeAndCapacity(v);
    cout << endl;

    // FRONT AND BACK FUCNTIONS TEST
    cout << "Testing front and back functions" << endl;
    // Output vector's front and back elements using front() and back()
    cout << "front: " << v.at(v.front()) << " back: " << v.at(v.back())
         << endl;
    cout << endl;

    // INSERT FUNCTION TEST
    cout << "Testing insert() function by adding at position 5" << endl;
    v.insert(v.begin()+5, 100); // v.begin()+5 to get to 5th element
    displayVector(v); // Display the result
    cout << endl;

    // ERASE FUNCTION TEST
    cout << "Testing erase() function by erasing position 6" << endl;
    v.erase(v.begin()+6); // v.begin()+6 to get to 6th element
    displayVector(v); // Display the result
    cout << endl;

    // RESIZE FUNCTION TEST (ONE PARAMETER)
    cout << "Testing resize() function (one parameter)" << endl;
    v.resize(20);   // Resize the vector with 1 parameter
    displaySizeAndCapacity(v); // Display size, capacity, and contents
    displayVector(v);
    v.resize(10);   // Resize the vector with 1 paramater
    displaySizeAndCapacity(v); // Display size, capacity, and contents
    displayVector(v);
    cout << endl;

    // RESIZE FUNCTION TEST (TWO PARAMETERS)
    cout << "Testing resize() function (two parameter)" << endl;
    v.resize(20, 101);  // Resize the vector with 2 parameters
    displaySizeAndCapacity(v);  // Display size, capacity, and contents
    displayVector(v);
    v.resize(10, 0);   // Resize the vector with 2 parameters
    displaySizeAndCapacity(v); // Display size, capacity, and contents
    displayVector(v);
    cout << endl;

    // ASSIGN FUNCTION TEST
    cout << "Testing assign() function" << endl;
    v.assign(5, 102); // Reassign vector to size 5 with elements 102
    displaySizeAndCapacity(v); // Display size, capacity, and contents
    displayVector(v);
    cout << endl;

    // CLEAR FUNCTION TEST
    cout << "Testing clear() function" << endl;
    v.clear(); // Clear the vector
    displaySizeAndCapacity(v); // Display size and capacity
    cout << endl;

    return 0;
}
// FUNCTION DEFINITIONS

/****************************************************************
 * testEmptyMemberFunction()
 *  This functions tests to see if the given vector is empty. It
 *  will print a message and return a bool value accordingly
 ****************************************************************/
bool testEmptyMemberFunction(const vector<int> &v){ // The vector to test
    cout << "Testing empty member function" << endl;
    if(v.empty()){ // EMPTY
        cout << "v is empty" << endl;
        return true;
    }else{ // NOT EMPTY
        cout << "v is not empty" << endl;
        return false;
    }
}

/****************************************************************
 * displaySizeAndCapacity()
 *  This functions displays the given vector's size and capacity
 ****************************************************************/
void displaySizeAndCapacity(const vector<int> &v){ // The vector to display
    cout << "size: " << v.size() << " capacity: " << v.capacity() << endl;
}

/****************************************************************
 * displayVector()
 *  This functions displays the given vector's contents
 ****************************************************************/
void displayVector(const vector<int> &v){ // The vector to display
    for(unsigned int i = 0; i < v.size(); i++){ // Loop through vector
        cout << v.at(i) << " "; // Use at function to obtain contents
    }
    cout << endl;
}

/****************************************************************
 * testConstructor()
 *  This functions runs tests for the constructor behavior of
 *  the given vector.
 ****************************************************************/
void testConstructor(const vector<int> &v, // The vector to test
                     string vectorName){ // The name of the vector
    // Display the vector's size and capacity
    displaySizeAndCapacity(v);

    // Test if it is empty
    if(!testEmptyMemberFunction(v)){

        // If it isn't, display its contents
        cout << "Testing at function by displaying " << vectorName << endl;
        displayVector(v);
    }
    cout << endl;
}
