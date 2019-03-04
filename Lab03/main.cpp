/****************************************************************
 * AUTHOR        : Zachary Norman, Heebeom Park
 * ASSIGNMENT    : Lab 03
 * CLASS         : CS03A
 * SECTION       : MW: 1-2:25, TH: 1-3:05
 * DUE DATE      : 2/26/19
 ****************************************************************/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/****************************************************************
 * Lab 03
 * ______________________________________________________________
 * This program allows the user manage an inventory of bins. The
 * program first reads a list of bins from a file and then edits
 * the contents of the list of bins.
 * ______________________________________________________________
 * INPUT:
 *      inventoryFileName           : The file name of the
 *                                    inventory file
 *      input                       : General-purpose input
 *                                    variable
 *
 * OUTPUT:
 *      The list of bins with their contents are displayed, as
 *      well as menus for editing them.
 *
 ****************************************************************/

// CONSTANTS
const int SIZE = 30; // The size of the bins array

// STRUCTS
struct Bin{ // The bin structure- holds the contents of a bin
    string partName; // The description of the part the bin holds
    int numParts; // The number of parts the bin holds
};

// PROTOTYPES

/****************************************************************
 * addParts()
 *  This function takes a bin as a reference variable and a
 *  number. It then adds the number to the bin's parts if the
 *  result is less than 30 and the number is positive.
 ****************************************************************/
void addParts(Bin &bin, // The bin to edit
              int num); // The number of parts to add

/****************************************************************
 * removeParts()
 *  This function takes a bin as a reference variable and a
 *  number. It then subtracts the number from the bin's parts if
 *  the number is positive.
 ****************************************************************/
void removeParts(Bin &bin, // The bin to edit
                 int num); // The number of parts to remove

/****************************************************************
 * addItem()
 *  This function adds a bin to the given array of bins at the
 *  given index
 ****************************************************************/
void addItem(Bin bins[SIZE], // The bins array
             Bin bin,        // The bin to add
             int index);     // The index to add at

/****************************************************************
 * displayInventory
 *  This function displays a given bins array up to a certain
 *  given number.
 ****************************************************************/
void displayInventory(const Bin bins[SIZE], // The array to display
                      int numBins); // The number of bins to display


int main()
{
    // VARIABLES
    Bin bins[SIZE]; // The array of bins
    ifstream in;    // The input stream
    int numBins;    // The number of bins in the array
    string inventoryFileName; // The inventory file name

    string input; // General-purpose input variable

    // INITIALIZE VARIABLES
    numBins = 0; // Set number of bins to 0

    // INPUT - receive inventory file name
    cout << "Enter name of inventory file: ";
    cin >> inventoryFileName;
    cin.get(); // We are going to be using getlines, remove the \n
    cout << endl;

    // Open the file
    in.open(inventoryFileName.c_str());

    // If the file was successfully openeed
    if(in){

        // As long as there is a description to read
        while(getline(in, bins[numBins].partName)){
            //Read in the number of parts
            in >> bins[numBins].numParts;
            in.get(); // Remove \n

            // Increment number of bins
            numBins++;
        }
    }


    do {
        // OUTPUT - the current inventory
        displayInventory(bins, numBins);

        // INPUT - Receive a valid menu option
        do{
            cout << endl;
            cout << "Menu:" << endl;
            cout << "Add a new item (a)" << endl;
            cout << "Select a bin (s)" << endl;
            cout << "Quit (q)" << endl;
            cout << endl;
            cout << "Selection: ";
            getline(cin, input);
            cout << endl;
        }while(!(input == "a" || input == "s" || input == "q"));

        if(input == "a"){ // ADD A NEW ITEM:
            cout << endl;

            // VARIABLES
            Bin bin; // The bin to add
            int numParts; // The number of parts

            // INPUT - receive the bin's description
            cout << "Enter Part Description: ";
            getline(cin, input);
            cout << endl;
            bin.partName = input; // Set it

            // INPUT - receive the number of parts
            cout << "Number of Parts in the Bin: ";
            cin >> numParts;
            cin.get();
            cout << endl;
            bin.numParts = numParts; // Set it

            // Add to the bins array
            bins[numBins] = bin;
            numBins++; // Increment the number of bins

            cout << endl;
        }else if(input == "s"){ // SELECT A BIN:
            // VARIABLES
            int binIndex; // The index of the bin to edit

            // INPUT - receive a valid bin selection
            do{
                binIndex = -1;
                cout << "Bin Selection: ";
                getline(cin, input);

                // Check if input is valid, and if it is- set the index
                for(int i = 0; i < numBins; i++){
                    if(bins[i].partName == input){
                        binIndex = i;
                        break;
                    }
                }
            }while(binIndex == -1);
            cout << endl;

            // INPUT & OUTPUT - Display options for edits and receive
            //                  valid input
            do{
                cout << endl;
                cout << "Menu:" << endl;
                cout << "Add parts (a)" << endl;
                cout << "Remove parts (r)" << endl;
                cout << endl;
                cout << "Selection: ";
                getline(cin, input);
                cout << endl;
            }while(!(input == "a" || input == "r"));

            if(input == "a"){ // ADD PARTS:
                // VARIABLES
                int n; // The number of parts to add

                // INPUT - receive the number of parts to add
                cout << "Number of parts to add: ";
                cin >> n;
                cin.get();
                cout << endl;

                // Add the parts
                addParts(bins[binIndex], n);
            }else if(input == "r"){ // REMOVE PARTS:
                // VARIABLES
                int n; // The number of parts to remove

                // INPUT - receive the number of parts to remove
                cout << "Number of parts to remove: ";
                cin >> n;
                cin.get();
                cout << endl;

                // Remove the parts
                removeParts(bins[binIndex], n);
            }
        }else if(input == "q"){ // QUIT:
            // OUTPUT - goodbye message
            cout << "Good Bye!!!" << endl;
        }

    } while (input != "q"); // Loop as long as not quit

    return 0;
}

// FUNCTION DEFINITIONS
/****************************************************************
 * addParts()
 *  This function takes a bin as a reference variable and a
 *  number. It then adds the number to the bin's parts if the
 *  result is less than 30.
 ****************************************************************/
void addParts(Bin &bin, int num){
    if(bin.numParts + num > 30){ // Check if result is greater than 30
        cout << "Unable to add to the bin." << endl;
    }else if(num < 0){ // Check if input is negative
        cout << "Cannot add negative parts." << endl;
    }else{
        // Passed tests, add parts
        bin.numParts += num;
    }
}

/****************************************************************
 * removeParts()
 *  This function takes a bin as a reference variable and a
 *  number. It then subtracts the number from the bin's parts if
 *  the number is positive.
 ****************************************************************/
void removeParts(Bin &bin, int num){
    if(bin.numParts - num < 0){ // Check if result is less than 0
        cout << "Unable to remove from the bin." << endl;
    }else if(num < 0){ // Check if input is negative
        cout << "Cannot remove negative parts." << endl;
    }else{
        // Passed tests, remove parts
        bin.numParts -= num;
    }
}

/****************************************************************
 * addItem()
 *  This function adds a bin to the given array of bins at the
 *  given index
 ****************************************************************/
void addItem(Bin bins[SIZE], Bin bin, int index){
    // Add the bin to the array at the given index
    bins[index] = bin;
}

/****************************************************************
 * displayInventory
 *  This function displays a given bins array up to a certain
 *  given number.
 ****************************************************************/
void displayInventory(const Bin bins[SIZE], int numBins){
    // Loop through the array up to the number of bins to display
    for(int i = 0; i < numBins; i++){
        // OUTPUT - the bin's contents
        cout.width(20);
        cout << left << bins[i].partName;

        cout.width(3);
        cout << right << bins[i].numParts << endl;
    }
}
