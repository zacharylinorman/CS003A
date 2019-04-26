#ifndef DISTANCE_H
#define DISTANCE_H
#include <iostream>

using namespace std;

class Distance
{
  private:
    unsigned feet;  //In&Out - feet
    double inches;  //In&Out - inches
  public:
    /******************************
    **        CONSTRUCTOR        **
    ******************************/
    Distance(){
        cout << "Test" << endl;
    }
    Distance(unsigned, double);
    Distance(double);
    /***************
    ** ACCESSORS **
    ***************/
    double convertToInches() const;
    const Distance operator+(const Distance &) const;
    const Distance operator-(const Distance &) const;
    void display() const;
  private:
    /***************
    **  MUTATORS  **
    ***************/
    void init();
};

#endif // DISTANCE_H

/*****************************************************************
 * Distance Class
 *  This class represents a distance. It manages feet and inches
 ****************************************************************/

/******************************
**        CONSTRUCTOR        **
******************************/

/*****************************************************************
 * Distance();
 *  Constructor: Initialize class attributes
 *  Parameters: none
 *  Return: none
 ****************************************************************/

/*****************************************************************
 * Distance(unsigned, double);
 *  Constructor: Initialize class attributes
 *  Parameters: unsigned and double variable
 *  Return: none
 ****************************************************************/

/*****************************************************************
 * Distance(unsigned, double);
 *  Constructor: Initialize class attributes
 *  Parameters: double variable
 *  Return: none
 ****************************************************************/

/***************
**  MUTATORS  **
***************/

/*******************************************************************
* void init();
*
*   Mutator; This method will update the feet and inches when inches is 12
*            or exceeds 12
*------------------------------------------------------------------
*   Parameter: none
*------------------------------------------------------------------
*   Return: none
*******************************************************************/

/***************
** ACCESSORS **
***************/

/*****************************************************************
 * double convertToInches() const;
 *
 *  Accessor; This method will return a double of inches after converting from
 *              feet
 * --------------------------------------------------------------
 *  Parameter: none
 * --------------------------------------------------------------
 *  Return: a double
 ****************************************************************/

/*****************************************************************
 * const Distance operator+(const Distance &) const;
 *
 *  Accessor; This method will overload the + operator to return a distance
 *              variable after adding two distances
 * --------------------------------------------------------------
 *  Parameter: const Distance & //In - right hand operand distance variable
 * --------------------------------------------------------------
 *  Return: a const distance variable
 ****************************************************************/

/*****************************************************************
 * const Distance operator-(const Distance &) const;
 *
 *  Accessor; This method will overload the - operator to return a distance
 *              variable after subtracting two distances
 * --------------------------------------------------------------
 *  Parameter: const Distance & //In - right hand operand distance variable
 * --------------------------------------------------------------
 *  Return: a const distance variable
 ****************************************************************/

/*****************************************************************
 * void display() const;
 *
 *  Accessor; This method will display the feet and inches
 * --------------------------------------------------------------
 *  Parameter: none
 * --------------------------------------------------------------
 *  Return: none
 ****************************************************************/


