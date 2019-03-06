/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Rational Class
 * CLASS         : CS03A
 * SECTION       : MW: 1-2:25, TH: 1-3:05
 * DUE DATE      : 3/5/19
 ****************************************************************/
#include <iostream>
#include "rational.h"

using namespace std;
/****************************************************************
 * Rational Class
 * ______________________________________________________________
 * This program tests the rational class.
 * ______________________________________________________________
 * OUTPUT:
 *      Test cases for the Rational Class.
 *
 ****************************************************************/

int main()
{
    // VARIABLES
    Rational a;         // Test default constructor
    Rational b(5);      // Test one argument constructor
    Rational c(2, 3);   // Test two argument constructor

    // OUTPUT - The test cases
    cout << "Testing default constructor." << endl;
    a.display();
    cout << endl << endl;

    cout << "Testing one argument constructor with 5 as the argument."
         << endl;
    b.display();
    cout << endl << endl;

    cout << "Testing two argument constructor with (2,3) as the argument."
         << endl;
    c.display();
    cout << endl << endl;

    cout << "Testing add function by adding 5 and 2/3." << endl;
    (b.add(c)).display();
    cout << endl << endl;

    cout << "Testing subtract function by subtracting 5 and 2/3." << endl;
    (b.subtract(c)).display();
    cout << endl << endl;

    cout << "Testing multiply function by multiplying 5 and 2/3." << endl;
    (b.multiply(c)).display();
    cout << endl << endl;

    cout << "Testing divide function by dividing 5 and 2/3." << endl;
    (b.divide(c)).display();
    cout << endl;

    return 0;
}
