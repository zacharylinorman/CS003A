
#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

/***************************************************************
 * Date
 *  This class represents a date with a numeric day, month and
 *  year. It also holds the month's name and has multiple
 *  constructors and functions.
 ***************************************************************/
class Date
{
private:
    // PRIVATE FIELDS
    unsigned day;       // The numeric day
    unsigned month;     // The numeric month
    string monthName;   // The name of the month
    unsigned year;      // The numeric year

    // PRIVATE FUNCTIONS
    /***********************************************************
     * isLeap
     *  This function returns true or false depending on whether
     *  the given year is a leap year.
     ***********************************************************/
    bool isLeap(unsigned y) // The year
    const;

    /***********************************************************
     * daysPerMonth
     *  This function returns the number of days are in the
     *  given month in the given year.
     ***********************************************************/
    unsigned daysPerMonth(unsigned m, // Month
                          unsigned y) // Year
    const;

    /***********************************************************
     * name
     *  This fucntion returns the name of the given month
     ***********************************************************/
    string name(unsigned m) // Month
    const;

    /***********************************************************
     * number
     *  This function returns the number of the given name of
     *  the month
     ***********************************************************/
    unsigned number(const string &mn) // Month Name
    const;
public:
    // CONSTRUCTORS
    /***********************************************************
     * No paramaters
     *  This constructor initializes the date to 1/1/2000
     ***********************************************************/
    Date();

    /***********************************************************
     * unsigned, unsigned, unsigned
     *  This constructor intializes the date to m/d/y and fixes
     *  any errors by assigning the closest possible date from
     *  the given values.
     ***********************************************************/
    Date(unsigned m,    // Month
         unsigned d,    // Day
         unsigned y);   // Year

    /***********************************************************
     * string, unsigned, unsigned
     *  This constructor initializes the date to number(mn)/d/y
     *  and fixes any errors by assigning the closest possible
     *  date from the given values.
     ***********************************************************/
    Date(const string &mn,  // Month Name
         unsigned d,        // Day
         unsigned y);       // Year


    // PUBLIC FUNCTIONS
    /***********************************************************
     * printNumeric
     *  This function prints the date in the form of m/d/y
     ***********************************************************/
    void printNumeric() const;

    /***********************************************************
     * printAlpha
     *  This function prints the date in the form of mn d, y
     ***********************************************************/
    void printAlpha() const;

    /***********************************************************
     * addDays
     *  This function adds the given amount of days to the
     *  current date and returns the result.
     ***********************************************************/
    Date addDays(int n) // Number of days to add
    const;
};

#endif // DATE_H
