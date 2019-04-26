#include "complex.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const Complex i(0, 1);

// CONSTRUCTORS
// Default constructor sets real and imaginary to 0
Complex::Complex()
{
    real = 0;
    imaginary = 0;
}

// Two parameter constructor sets real to a and imaginary to b
Complex::Complex(double realPart){
    real= realPart;
    imaginary = 0;
}

// One parameter constructor sets real to realPart and imaginary to 0
Complex::Complex(double a, double b){
    real = a;
    imaginary = b;
}

// OPERATORS
/****************************************************************
 * ==
 *  Returns whether the real and imaginary parts are equal
 ****************************************************************/
bool Complex::operator==(const Complex &rhs) const{ // Right-hand side
    return real == rhs.real && imaginary == rhs.imaginary;
}
/****************************************************************
 * +
 *  Adds the real and imaginary parts together
 ****************************************************************/
Complex Complex::operator+(const Complex &rhs) const{ // Right-hand side
    // Add parts
    double newReal = real + rhs.real;
    double newImaginary = imaginary + rhs.imaginary;

    // Return result
    Complex a(newReal, newImaginary);
    return a;
}
/****************************************************************
 * -
 *  Subtracts the real and imaginary parts
 ****************************************************************/
Complex Complex::operator-(const Complex &rhs) const{ // Right-hand side
    // Subtract parts
    double newReal = real - rhs.real;
    double newImaginary = imaginary - rhs.imaginary;

    // Return result
    Complex a(newReal, newImaginary);
    return a;
}
/****************************************************************
 * *
 *  Uses the given formula to find the product
 ****************************************************************/
Complex Complex::operator*(const Complex &rhs) const{ // Right-hand side
    // Create parts with given formula
    double newReal = real * rhs.real - imaginary * rhs.imaginary;
    double newImaginary = real * rhs.imaginary + imaginary * rhs.real;

    // Return result
    Complex a(newReal, newImaginary);
    return a;
}

/****************************************************************
 * <<
 *  Outputs the complex number in the form of
 *  '(real) + (imaginary)i'
 ****************************************************************/
ostream& operator<<(ostream &out, // Output stream
                    const Complex &rhs){ // Right-hand side
    out << rhs.real << (rhs.imaginary < 0 ? "" : "+") << rhs.imaginary << "i";
    return out;
}

/****************************************************************
 * >>
 *  Extracts the real part then the imaginary part from the input
 *  stream
 ****************************************************************/
istream& operator>>(istream &in, // Input stream
                    Complex &rhs){ // Right-hand side
    // VARIABLES
    string input;       // Input
    string real,        // Real part as a string
           imaginary;   // Imaginary part as a string

    // RECEIVE INPUT
    getline(in, input);

    // PROCESS INPUT
    // If there is no i, then only real
    if(input.find('i') == string::npos){
        real = input;
        imaginary = "0";

    // If there is no +, and first char is -, then 0-imaginary*i
    }else if(input.find('+') == string::npos &&
             input.find_last_of('-') == 0){
        real = "0";

        if(input.find('i') == 1){ // If i is second char, then 0-1i
            imaginary = "-1";
        }else{
            imaginary = input.substr(0, input.find('i'));
        }

    // If there is no + and no -, then 0+imaginary*i
    }else if(input.find('+') == string::npos &&
             input.find('-') == string::npos){
        real = "0";

        if(input.find('i') == 0){ // If i is the first char, then 0+1i
            imaginary = "1";
        }else{
            imaginary = input.substr(0, input.find('i'));
        }

    // If there is no +, then real-imaginary*i
    }else if(input.find('+') == string::npos){
        real = input.substr(0, input.find_last_of('-'));
        imaginary = input.substr(input.find_last_of('-'), input.find('i'));

    // Otherwise, it is real+imaginary*i
    }else{
        real = input.substr(0, input.find('+'));
        imaginary = input.substr(input.find('+'), input.find('i'));
    }

    char* thing; // Null pointer for strtod

    // Convert strings to doubles
    rhs.real = strtod(real.c_str(), &thing);
    rhs.imaginary = strtod(imaginary.c_str(), &thing);
    return in;
}


