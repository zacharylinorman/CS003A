/****************************************************************
 * AUTHOR        : Zachary Norman, Hayk Khulyan, Heebeom Park
 * ASSIGNMENT    : Lab 02
 * CLASS         : CS03A
 * SECTION       : MW: 1-2:25, TH: 1-3:05
 * DUE DATE      : 2/21/19
 ****************************************************************/
#include <iostream>
#include <cstdlib>

using namespace std;

/****************************************************************
 * Lab 02
 * ______________________________________________________________
 * This program allows the user to simulate a chosen number of
 * four dice rolls. The sums are taken of each simulation, and a
 * histogram is printed with the results.
 * ______________________________________________________________
 * INPUT:
 *      numSimulations            : The number of simulations
 *      seed                      : The random seed
 *
 * OUTPUT:
 *      The historgram of the results
 *
 ****************************************************************/

// CONSTANTS
const int SIZE = 21;    // Size of the count array

// PROTOTYPES
/****************************************************************
 * roll()
 *  This function returns a random number from 1-6 inclusive
 ****************************************************************/
int roll();

/****************************************************************
 * printHistogram()
 *  This function prints a histogram of the given array
 ****************************************************************/
void printHistogram(int counts[]); // The array to print a histogram of

int main()
{

    // VARIABLES
    int numSimulations;     // The number of simulations
    int counts[SIZE];       // The results array
    int seed;               // The random seed

    // INITIALIZE - The array to 0
    for(int i = 0; i < SIZE; i++){
        counts[i] = 0;
    }

    // INPUT - receive the random seed
    cout << "Enter the seed value: ";
    cin >> seed;
    cout << endl;

    // INPUT - receive the wanted number of simulations
    cout << "Enter the number of Rolls: ";
    cin >> numSimulations;
    cout << endl;

    cout << endl;

    // PROCESSING - set random seed
    srand(seed);

    // PROCESSING - perform the rolls and collect data with counts array
    for(int i = 0; i < numSimulations; i++){
        int sum = roll() + roll() + roll() + roll();
        counts[sum-4]++;
    }

    // OUTPUT - pring the histogram
    printHistogram(counts);

    return 0;
}

/****************************************************************
 * roll()
 *  This function returns a random number from 1-6 inclusive
 ****************************************************************/
int roll(){
    return (rand() % 6) + 1;
}

/****************************************************************
 * printHistogram()
 *  This function prints a histogram of the given array
 ****************************************************************/
void printHistogram(int counts[]){
    // Loop through the array
    for(int i = 0; i < SIZE; i++){

        // Print the number it represents
        cout << i + 4;
        if(i + 4 < 10){
            cout << " : ";
        }else{
            cout << ": ";
        }

        // Print the number of X's according to the count
        for(int k = 0; k < counts[i]; k++){
            cout << "X";
        }
        cout << endl;
    }
}
