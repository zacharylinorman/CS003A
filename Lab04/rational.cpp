#include "rational.h"
#include <iostream>

using namespace std;
// Default constructor: numer = 0, denom = 1
Rational::Rational(){
    numer = 0;
    denom = 1;
}

// Whole numer constructor: denom = 1;
Rational::Rational(int n)
{
    numer = n;
    denom = 1;
}

// Given both numerator and denominator
Rational::Rational(int n, int d){
    numer = n;
    denom = d;
}


/************************************************************
 * add()
 *    This function adds this rational number to the given
 *    and returns the result.
 ************************************************************/
const Rational Rational::add(const Rational &r) const{
    return Rational(numer * r.denom + r.numer * denom, denom * r.denom);
}
/************************************************************
 * subtract()
 *    This function subtracts this rational number by the
 *    given and returns the result.
 ************************************************************/
const Rational Rational::subtract(const Rational &r) const{
    return Rational(numer * r.denom - r.numer * denom, denom * r.denom);
}
/************************************************************
 * multiply()
 *    This function multiplies this rational number by the
 *    given and returns the result.
 ************************************************************/
const Rational Rational::multiply(const Rational &r) const{
    return Rational(numer * r.numer, denom * r.denom);
}
/************************************************************
 * divide()
 *    This function divides this rational number by the
 *    given and returns the result.
 ************************************************************/
const Rational Rational::divide(const Rational &r) const{
    return Rational(numer * r.denom, denom * r.numer);
}
/************************************************************
 * display()
 *    This function outputs the rational in the format of
 *    numerator/denominator
 ************************************************************/
void Rational::display() const{
    cout << numer << "/" << denom;
}
