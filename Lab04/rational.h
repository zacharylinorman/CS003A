#ifndef RATIONAL_H
#define RATIONAL_H

/******************************************************************
 * Rational
 *  This class contains a numerator and a denominator to represent
 *  a rational number. It also contains functions to perform basic
 *  operations involving rational numbers.
 ******************************************************************/
class Rational{
   private:
      int numer; // The numerator
      int denom; // The denominator
   public:
      // CONSTRUCTORS
      Rational();           // Default constructor: numer = 0, denom = 1
      Rational(int);        // Whole numer constructor: denom = 1;
      Rational(int, int);   // Given both numerator and denominator

      // FUNCTIONS
      /************************************************************
       * add()
       *    This function adds this rational number to the given
       *    and returns the result.
       ************************************************************/
      const Rational add(const Rational &) const; // Rational to add
      /************************************************************
       * subtract()
       *    This function subtracts this rational number by the
       *    given and returns the result.
       ************************************************************/
      const Rational subtract(const Rational &) const; // Given rational
      /************************************************************
       * multiply()
       *    This function multiplies this rational number by the
       *    given and returns the result.
       ************************************************************/
      const Rational multiply(const Rational &) const; // Given rational
      /************************************************************
       * divide()
       *    This function divides this rational number by the
       *    given and returns the result.
       ************************************************************/
      const Rational divide(const Rational &) const; // Given rational
      /************************************************************
       * display()
       *    This function outputs the rational in the format of
       *    numerator/denominator
       ************************************************************/
      void display() const;
};


#endif // RATIONAL_H
