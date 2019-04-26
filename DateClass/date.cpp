#include "date.h"
#include <iostream>
#include <string>

using namespace std;

// CONSTRUCTORS
/***********************************************************
 * No paramaters
 *  This constructor initializes the date to 1/1/2000
 ***********************************************************/
Date::Date()
{
    month = 1;
    day = 1;
    year = 2000;
    monthName = name(month);
}

/***********************************************************
 * unsigned, unsigned, unsigned
 *  This constructor intializes the date to m/d/y and fixes
 *  any errors by assigning the closest possible date from
 *  the given values.
 ***********************************************************/
Date::Date(unsigned m, unsigned d, unsigned y){
    // VARIABLES
    // Whether to display error message or not
    bool invalid = false;
    if(m > 12){ // Month is greater than 12
        month = 12;
        invalid = true;
    }else if(m < 1){ // Month is 0
        month = 1;
        invalid = true;
    }else{
        month = m;
    }

    // If day is greater than the number of days in month
    if(d > daysPerMonth(month, y)){
        day = daysPerMonth(month, y);
        invalid = true;
    }else if(d < 1){ // Day is 0
        day = 1;
        invalid = true;
    }else{
        day = d;
    }

    year = y;
    monthName = name(month);

    if(invalid){
        // OUTPUT- display error message
        cout << "Invalid date values: Date corrected to ";
        printNumeric();
        cout << ".";
        cout << endl;
    }

}

/***********************************************************
 * string, unsigned, unsigned
 *  This constructor initializes the date to number(mn)/d/y
 *  and fixes any errors by assigning the closest possible
 *  date from the given values.
 ***********************************************************/
Date::Date(const string &mn, unsigned d, unsigned y){
    if(number(mn) == 0){ // The month name is invalid
        month = 1;
        day = 1;
        year = 2000;
        monthName = name(month);

        // OUTPUT- display error message
        cout << "Invalid month name: the Date was set to ";
        printNumeric();
        cout << ".";
        cout << endl;
    }else{ // Month name not invalid
        // VARIABLES
        // Whether to display error message or not
        bool invalidDay = false;

        month = number(mn);

        // Day is greater than number of days per month
        if(d > daysPerMonth(month, y)){
            day = daysPerMonth(month, y);
            invalidDay = true;
        }else if(d < 1){ // Day is 0
            day = 1;
            invalidDay = true;
        }else{
            day = d;
        }
        year = y;
        monthName = name(month);

        // OUTPUT - disply error message
        if(invalidDay){
            cout << "Invalid date values: Date corrected to ";
            printNumeric();
            cout << ".";
            cout << endl;
        }
    }
}

// PUBLIC FUNCTIONS
/***********************************************************
 * printNumeric
 *  This function prints the date in the form of m/d/y
 ***********************************************************/
void Date::printNumeric() const{
    // OUTPUT - display the date
    cout << month << "/" << day << "/" << year;
}

/***********************************************************
 * printAlpha
 *  This function prints the date in the form of mn d, y
 ***********************************************************/
void Date::printAlpha() const{
    // OUTPUT - display the date
    cout << monthName << " " << day << ", " << year;
}


/***********************************************************
 * addDays
 *  This function adds the given amount of days to the
 *  current date and returns the result.
 ***********************************************************/
Date Date::addDays(int n) // Number of days to add
const{
    // VARIABLES
    // Convert day and year into signed in case they go negative
    // Month will never be negative, so keep unsigned
    int signedDay = static_cast<int>(day);
    int signedYear = static_cast<int>(year);
    unsigned newMonth = month;

    // If the number of days being added will bring the day below 1
    if(signedDay + n < 1){
        do{
            // Add the current day to the number of days to add
            n += signedDay;

            // Go to the previous month
            newMonth--;

            // If the month was January, go to previous year's December
            if(newMonth < 1){
                newMonth = 12;
                signedYear--;
            }

            // Set the day to be the last in the new month
            signedDay = daysPerMonth(newMonth, signedYear);
        }while(signedDay + n < 1); // Continue as long as n brings day < 1
    }else if(signedDay + n > daysPerMonth(month, year)){
     // If the number of days being added will bring the day past the max
        do{
            // Subtract the remaining days in the month from n
            n -= daysPerMonth(newMonth, signedYear) - signedDay;

            // Set the day to 0
            signedDay = 0;

            // Go to next month
            newMonth++;

            // If the month was December, go to next year's January
            if(newMonth > 12){
                newMonth = 1;
                signedYear++;
            }
         // Continue as long as n increases the day past the max for month
        }while(signedDay + n > daysPerMonth(newMonth, signedYear));
    }

    // Add the remaining days to the day
    signedDay += n;

    // Create the new date
    Date date(newMonth,
              static_cast<unsigned>(signedDay),
              static_cast<unsigned>(signedYear));

    // Return it
    return date;
}

// PRIVATE FUNCTIONS
/***********************************************************
 * isLeap
 *  This function returns true or false depending on whether
 *  the given year is a leap year.
 ***********************************************************/
bool Date::isLeap(unsigned y) // The year
const{
    if(y % 400 == 0){ // Multiple of 400
        return true;
    }else if(y % 100 == 0){ // Multiple of 100
        return false;
    }else if(y % 4 == 0){ // Multiple of 4
        return true;
    }
    return false;
}

/***********************************************************
 * daysPerMonth
 *  This function returns the number of days are in the
 *  given month in the given year.
 ***********************************************************/
unsigned Date::daysPerMonth(unsigned m, // Month
                      unsigned y) // Year
const{
    switch(m){
    // These months have 31 days
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    // These months have 30 days
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    // Case for February
    case 2:
        if(isLeap(y))
            return 29;
        else
            return 28;
    // Given month was not valid
    default:
        return 0;
    }
}

/***********************************************************
 * name
 *  This fucntion returns the name of the given month
 ***********************************************************/
string Date::name(unsigned m) // Month
const{
    switch(m){
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default: // Invalid month
        return "";
    }
}
/***********************************************************
 * number
 *  This function returns the number of the given name of
 *  the month
 ***********************************************************/
unsigned Date::number(const string &mn) // Month Name
const{
    string m = "";
    // Set the string to lowercase
    for(unsigned i = 0; i < mn.size(); i++){
        m += tolower(mn.at(i));
    }
    if(m == "january" || m == "jan"){
        return 1;
    }else if(m == "february" || m == "feb"){
        return 2;
    }else if(m == "march" || m == "mar"){
        return 3;
    }else if(m == "april" || m == "apr"){
        return 4;
    }else if(m == "may"){
        return 5;
    }else if(m == "june"){
        return 6;
    }else if(m == "july"){
        return 7;
    }else if(m == "august" || m == "aug"){
        return 8;
    }else if(m == "september" || m == "sep"){
        return 9;
    }else if(m == "october" || m == "oct"){
        return 10;
    }else if(m == "november" || m == "nov"){
        return 11;
    }else if(m == "december" || m == "dec"){
        return 12;
    }
    // Invalid month name
    return 0;
}
