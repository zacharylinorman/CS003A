/****************************************************************
 * AUTHOR        : Zachary Norman, Godwin Liang
 * ASSIGNMENT    : Lab 13
 * CLASS         : CS03A
 * SECTION       : MW: 1-2:25, TH: 1-3:05
 * DUE DATE      : 4/23/19
 ****************************************************************/
#include <iostream>
#include <vector>

using namespace std;

/****************************************************************
 * Lab 13
 * ______________________________________________________________
 * This program includes recursion exercises.
 * ______________________________________________________________
 ****************************************************************/

// PROTOTYPES

/****************************************************************
 * sum()
 *  Recursively returns the sum of all natural numbers up to n
 ****************************************************************/
int sum(int n); // Number to stop adding at

/****************************************************************
 * findmin()
 *  Recursively finds the minimum value in array a
 ****************************************************************/
int findmin(const int a[], // The array
            int n);        // Size of array

/****************************************************************
 * findsum()
 *  Recursively finds the sum of all numbers in the array
 ****************************************************************/
int findsum(const int a[], // The array
            int n);        // Size of array

/****************************************************************
 * ispalindrome()
 *  Recursively determines whether the given c-string is a
 *  palindrome
 ****************************************************************/
bool ispalindrome(const char a[], // The string
                  int n);         // Length of string

/****************************************************************
 * generate_substrings()
 *  Recursively returns all substrings of string s as a string
 *  vector
 ****************************************************************/
vector<string> generate_substrings(string s); // The string

/****************************************************************
 * drawPattern()
 *  Recursively outputs the specified pattern given a positive
 *  int n
 ****************************************************************/
void drawPattern(int n); // The positive int

int main()
{
    // Test for sum()
    cout << "sum(5): " << sum(5) << endl;
    cout << endl;

    // Test for findmin()
    int a[] = {1, 2, 3, 0, 4, 5};
    cout << "findmin(): " << findmin(a, 6) << endl;
    cout << endl;

    // Test for findsum()
    cout << "findsum(): " << findsum(a, 6) << endl;
    cout << endl;

    string palindrome = "racecar";
    cout << "racecar ispalindrome(): " << (ispalindrome(palindrome.c_str(), 7) ? "True" : "False") << endl;
    cout << endl;

    // Test for generate_substrings()
    cout << "generate_substrings(\"ABCD\")" << endl;

    string s = "ABCD";

    vector<string> v;

    v = generate_substrings(s);

    for(int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << endl;
    }
    cout << endl;

    // Test for drawPattern()
    cout << "drawPattern(4): " << endl;
    drawPattern(4);

    return 0;
}

/***********************************************************
* sum()
*_________________________________________________________
* Recursively finds the sum of integer numbers up to input n
*_________________________________________________________
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   Sum of integers up to n is returned
***********************************************************/
int sum(int n)                              //IN - Largest integer in sum
{

    //base case
    if(n == 1)
    {
        return 1;
    }

    //recursive call
    return n + sum(n-1);
}

/***********************************************************
* findmin()
*_________________________________________________________
* Recursively finds the lowest integer number in array a
*_________________________________________________________
* PRE-CONDITIONS
*   Array a is initialized with values
*
* POST-CONDITIONS
*   Lowest integer in the array a
***********************************************************/
int findmin(const int a[],                  //IN - array to be scanned
            int n)                          //IN - # of elements in array a
{

    //base case
    if(n == 0)
    {
        return a[n];
    }

    //recursive call
    return a[n-1] < findmin(a, n-1) ? a[n-1] : findmin(a, n-1);
}

/***********************************************************
* findsum()
*_________________________________________________________
* Recursively finds the sum of integers in array a
*_________________________________________________________
* PRE-CONDITIONS
*   Array a is initialized with values
*
* POST-CONDITIONS
*   Sum of integers in array a is returned
***********************************************************/
int findsum(const int a[],                  //IN - array to be summed
            int n)                          //IN - size of array a
{

    //base case
    if(n == 0)
    {
        return a[n];
    }

    //recursive call
    return a[n - 1] + findsum(a, n-1);
}

/***********************************************************
* ispalindrome()
*_________________________________________________________
* Recursively determines whether or not char array a is a
* palindrome
*_________________________________________________________
* PRE-CONDITIONS
*   Array a is initialized with values
*
* POST-CONDITIONS
*   true is returned if char array a is a palindrome
*   false is returned otherwise
***********************************************************/
bool ispalindrome(const char a[],           //IN - array of characters
                  int n)                    //IN - size of array a
{

    //base cases for both odd and even length palindromes
    if(n == 0 || n == 1)
    {
        return true;
    }

    //isn't a palindrome because corresponding characters don't match
    else if(a[n - 1] != a[0])
    {
        return false;
    }

    //recursive call
    else
    {
        //copy array except for elements on either end
        char b[n - 2];
        for(int i = 1; i < n - 1; i++)
        {
            b[i - 1] = a[i];
        }

        return ispalindrome(b, n - 2);
    }

}

/***********************************************************
* generate_substrings()
*_________________________________________________________
* Recursively generates all substrings in string s
*_________________________________________________________
* PRE-CONDITIONS
*   String s is initialized with a value
*
* POST-CONDITIONS
*   Vector v is initialized with all substrings of string s
*   Vector v is returned
***********************************************************/
vector<string> generate_substrings(string s)        //IN - string to retrieve substrings from
{
    // Create a vector that includes the given string
    vector<string> v(1, s);

    if(s.length() > 0){

        //recursive call to obtain substrings that start with first letter
        vector<string> vector1 = generate_substrings(s.substr(0, s.length()-1));

        //putting current substrings into vector
        for(unsigned i = 0; i < vector1.size(); i++){
            v.push_back(vector1.at(i));
        }

        //recursive call to get substrings without the current first letter
        vector<string> vector2 = generate_substrings(s.substr(1));

        for(unsigned i = 0; i < vector2.size(); i++){
            bool inVector = false;

            //checking for repeated substrings
            for(unsigned k = 0; k < vector1.size(); k++){
                if(vector2.at(i) == vector1.at(k)){
                    inVector = true;
                    break;
                }
            }

            //add to vector if no
            if(!inVector){
                v.push_back(vector2.at(i));
            }
        }
    }

    // return the created vector
    return v;
}

/***********************************************************
* drawPattern()
*_________________________________________________________
* Recursively draws a symmetrical pattern of asterisks
*_________________________________________________________
* PRE-CONDITIONS
*   None
*
* POST-CONDITIONS
*   Symmetrical pattern of asterisks is outputted to the system
***********************************************************/
void drawPattern(int n)                         //IN - max # of stars in pattern
{
    // Output from n to 1
    for(int i = 0; i < n; i++){
        cout << "*";
    }
    cout << endl;

    // Base case + recursive call
    if(n > 1){
        drawPattern(n - 1);
    }

    // Output from 1 to n
    for(int i = 0; i < n; i++){
        cout << "*";
    }
    cout << endl;

}
