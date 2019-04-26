#include <iostream>
#include "complex.h"

using namespace std;

int main()
{
    Complex a;
    cout << endl;
    cout << "Testing default constructor" << endl;
    cout << a << endl;
    cout << endl;

    Complex b(5);
    cout << "Testing one parameter constructor with input 5" << endl;
    cout << b << endl;
    cout << endl;

    Complex c(0, 0);
    cout << "Testing two parameter constructor with input 0, 0" << endl;
    cout << c << endl;
    cout << endl;

    Complex d(1, 2);
    cout << "Testing two parameter constructor with input 1, 2" << endl;
    cout << d << endl;
    cout << endl;

    Complex e(-13, 21);
    cout << "Testing two parameter constructor with input -13, 21" << endl;
    cout << e << endl;
    cout << endl;

    Complex f(-3, -4);
    cout << "Testing two parameter constructor with input -3, -4" << endl;
    cout << f << endl;
    cout << endl;

    Complex g(10, 4), h(5, 3);
    cout << "Testing addition subtraction and multiplication "
            "for complex numbers: 10+4i and 5+3i" << endl;
    cout << g << " + " << h << " = " << g + h << endl;
    cout << g << " - " << h << " = " << g - h << endl;
    cout << g << " * " << h << " = " << g * h << endl;
    cout << endl;

    Complex i(-10, -4), j(-5, -3);
    cout << "Testing addition subtraction and multiplication "
            "for complex numbers: -10-4i and -5-3i" << endl;
    cout << i << " + " << j << " = " << i + j << endl;
    cout << i << " - " << j << " = " << i - j << endl;
    cout << i << " * " << j << " = " << i * j << endl;
    cout << endl;

    cout << "Testing == operator with -10-4i and -5-3i" << endl;
    cout << "Should be false: " << (i == j) << endl;
    cout << endl;

    cout << "Testing == operator with 10+4i and 10+4i" << endl;
    cout << "Should be true: " << (g == g) << endl;
    cout << endl;

    Complex k;
    cout << "Testing << and >> operators" << endl;
    cout << "enter imaginary number of form a+bi or a-bi" << endl;
    cin >> k;
    cout << k;
    cout << endl;

    return 0;
}
