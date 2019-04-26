#include "distance.h"
#include <iostream>

using namespace std;

/*****************************************************************
 * Distance();
 *  Constructor: Initialize class attributes
 *  Parameters: none
 *  Return: none
 ****************************************************************/
/*Distance::Distance()

{
    feet = 0;
    inches = 0;
}*/

/*****************************************************************
 * Distance(unsigned, double);
 *  Constructor: Initialize class attributes
 *  Parameters: unsigned and double variable
 *  Return: none
 ****************************************************************/
Distance::Distance(unsigned f,  //In - feet
                   double i)    //In - inches
{
    feet = f;
    inches = i;
    init();
}

/*****************************************************************
 * Distance(unsigned, double);
 *  Constructor: Initialize class attributes
 *  Parameters: double variable
 *  Return: none
 ****************************************************************/
Distance::Distance(double i)    //In - inches
{
    feet = 0;
    inches = i;
    init();
}

/**********************************************************
 *
 * Method convertToInches: Class Date
 *
 * _________________________________________________________
 * This method will convert the distance to inches
 * _________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      none
 *
 * POST-CONDITION
 *      this function will return a double of the inches
 *
***********************************************************/
double Distance::convertToInches() const
{
    double tempInch = 0;
    tempInch = inches + (feet * 12);
    return tempInch;
}

/**********************************************************
 *
 * Method operator+: Class Date
 *
 * _________________________________________________________
 * This method will overload the + operator to add two distances
 * _________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      d   : right hand operand of type distance
 *
 * POST-CONDITION
 *      this function will return a new const Distance with the sum of both
 * distances
 *
***********************************************************/
const Distance Distance::operator+(const Distance &d) const
                                    //In - right hand operand distance type
{
    //Declaring variables
    unsigned tempFeet = feet;   //Calc-temporary feet variable
    double tempInches = inches; //Calc-temporary inches variable

    //Adding feet from left hand operand and parameter operand
    tempFeet += d.feet;
    tempInches +=d.inches;

    //Checking if tempInches is over 12, if so adding it to feet
    if(tempInches >= 12)
    {
        tempFeet += static_cast<unsigned>(tempInches / 12);
        tempInches = tempInches - (static_cast<int>(tempInches / 12) * 12);
    }

    //Declaring const Distance with new attributes to be returned
    const Distance temp(tempFeet, tempInches);
    return temp;
}

/**********************************************************
 *
 * Method operator-: Class Date
 *
 * _________________________________________________________
 * This method will overload the - operator to subtract two distances
 * _________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      d   : right hand operand of type distance
 *
 * POST-CONDITION
 *      this function will return a new const Distance with the difference of
 *  both distances
 *
***********************************************************/
const Distance Distance::operator-(const Distance &d) const
                                    //In - right hand operand distance type
{
    //Declaring variables
    unsigned tempFeet = feet;   //Calc-temporary feet variable
    double tempInches = inches; //Calc-temporary inches variable

    tempInches += (feet * 12);
    tempInches -= d.inches;
    tempInches -= (d.feet * 12);
    if(tempInches < 0)
        tempInches = tempInches * -1;
    if(tempInches >= 12)
    {
        tempFeet = static_cast<unsigned>(tempInches / 12);
        tempInches = tempInches - (static_cast<int>(tempInches / 12) * 12);
    }

    //Declaring const Distance with new attributes to be returned
    const Distance temp(tempFeet, tempInches);
    return temp;
}

/**********************************************************
 *
 * Method display: Class Date
 *
 * _________________________________________________________
 * This method will display the feet and inches
 * _________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      none
 *
 * POST-CONDITION
 *      this function will display the feet and inches and return nothing
 *
***********************************************************/
void Distance::display() const
{
    //Displaying feet and inches
    cout << feet << "' " << inches << "\"";
}

/**********************************************************
 *
 * Method init: Class Date
 *
 * _________________________________________________________
 * This method will convert inches >= 12 to feet and alter the values
 * _________________________________________________________
 * PRE-CONDITIONS
 *  The following need previously defined values:
 *      none
 *
 * POST-CONDITION
 *      this function will convert inches >= 12 to feet and alter the values
 *      but returns nothing
 *
***********************************************************/
void Distance::init()
{
    //Converting inches that are negative to positive
    if(inches < 0)
        inches = inches * -1;
    //Converting inches = to or > than 12 to feet
    if(inches >= 12)
    {
        feet += static_cast<unsigned>(inches / 12);
        inches = inches - (static_cast<int>(inches / 12) * 12);
    }
}




