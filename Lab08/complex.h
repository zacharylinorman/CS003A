#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

/*******************************************************************
 * Complex
 *  This class simulates a complex number with a real and imaginary
 *  part
 *******************************************************************/
class Complex
{
private:
    // VARIABLES
    double real;        // Real part
    double imaginary;   // Imaginary part
public:
    // CONSTRUCTORS
    // Default constructor sets real and imaginary to 0
    Complex();

    // Two parameter constructor sets real to a and imaginary to b
    Complex(double a, double b);

    // One parameter constructor sets real to realPart and imaginary to 0
    Complex(double realPart);


    // OPERATORS
    /****************************************************************
     * ==
     *  Returns whether the real and imaginary parts are equal
     ****************************************************************/
    bool operator==(const Complex &rhs) const; // Right-hand side

    /****************************************************************
     * +
     *  Adds the real and imaginary parts together
     ****************************************************************/
    Complex operator+(const Complex &rhs) const; // Right-hand side

    /****************************************************************
     * -
     *  Subtracts the real and imaginary parts
     ****************************************************************/
    Complex operator-(const Complex &rhs) const; // Right-hand side

    /****************************************************************
     * *
     *  Uses the given formula to find the product
     ****************************************************************/
    Complex operator*(const Complex &rhs) const; // Right-hand side

    /****************************************************************
     * <<
     *  Outputs the complex number in the form of
     *  '(real) + (imaginary)i'
     ****************************************************************/
    friend ostream& operator<<(ostream &out, // Output stream
                               const Complex &rhs); // Right-hand side

    /****************************************************************
     * >>
     *  Extracts the real part then the imaginary part from the input
     *  stream
     ****************************************************************/
    friend istream& operator>>(istream &in, // Input stream
                               Complex &rhs); // Right-hand side
};

#endif // COMPLEX_H
