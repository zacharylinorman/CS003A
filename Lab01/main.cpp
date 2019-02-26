/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Lab 01
 * CLASS         : CS03A
 * SECTION       : MW: 1-2:25, TH: 1-3:05
 * DUE DATE      : 2/21/19
 ****************************************************************/
#include <iostream>

using namespace std;

/****************************************************************
 * Lab 01
 * ______________________________________________________________
 * This program allows the user to translate between Roman
 * numerals and standard numerals.
 * ______________________________________________________________
 * INPUT:
 *      input                   : Whether to convert roman to
 *                                standard or the other way
 *                                around
 *      romanNumeral            : The roman numeral to convert
 *      standardNumeral         : The standard numeral to convert
 *
 * OUTPUT:
 *      The converted numeral based on the input
 *
 ****************************************************************/

// PROTOTYPES
/********************************************************************
 * romanNumeral
 *  This function returns the roman numeral form of a given standard
 *  numeral
 ********************************************************************/
string romanNumeral(int num); // The number to convert

/********************************************************************
 * romanDigit
 *  This function returns the roman numeral digit of a given standard
 *  numeral digit
 ********************************************************************/
string romanDigit(int num,   // The standard numeral digit
                  string s1, // The ones place character
                  string s2, // The tens place character
                  string s3);// The hundreds place character

/********************************************************************
 * standardNumeralStringCut
 *  This function returns a roman numeral with the given standard
 *  numeral digit cut off at the end
 ********************************************************************/
string standardNumeralStringCut(string numeral, // The roman numeral
                                int digit);// The standard numeral digit

/********************************************************************
 * standardNumeral
 *  This function returns a standard numeral given a roman numeral
 ********************************************************************/
int standardNumeral(string numeral);

/********************************************************************
 * standardDigit
 *  This function returns a standard numeral digit given a roman
 *  numeral and the characters of the digit wanted
 ********************************************************************/
int standardDigit(string numeralDigit, // The roman numeral
                  char s1, // The ones place character
                  char s2, // The tends place character
                  char s3); // The hundreds place character

int main()
{
    // VARIABLES
    string input; // Which numeral system to convert

    // INPUT - Receive user choice of which to convert
    cout << "Enter \"RTS\" to conver Roman to Standard or \"STR\" for "
         << "Standard to Roman: " << endl;
    cin >> input;
    cout << endl;

    // PROCESSING - Convert based on user's choice
    if(input == "RTS"){
        // ROMAN TO STANDARD

        // VARIABLES
        string romanNumeral; // The roman numeral to convert

        // INPUT - Receive the roman numeral
        cout << "Enter the Roman Numeral to convert: ";
        cin >> romanNumeral;
        cout << endl;

        // OUTPUT - Output the converted numeral
        cout << standardNumeral(romanNumeral) << endl;
    }else if(input == "STR"){
        // STANDARD TO ROMAN

        // VARIABLES
        int standardNumeral; // The standard numeral to convert

        // INPUT - Receive the standard numeral
        cout << "Enter the Standard Numeral to convert: ";
        cin >> standardNumeral;
        cout << endl;

        // OUTPUT - Output the converted numeral
        cout << romanNumeral(standardNumeral) << endl;
    }else{

        // INVALID INPUT
        cout << "Invalid input." << endl;
    }

    return 0;
}

/********************************************************************
 * standardDigit
 *  This function returns a standard numeral digit given a roman
 *  numeral and the characters of the digit wanted
 ********************************************************************/
int standardDigit(string numeralDigit, char s1, char s2, char s3){
    // VARIALBES
    int num = 0; // The return variable
    int size = static_cast<int>(numeralDigit.size()); // Size of roman num

    // CHECK THE END OF THE ROMAN NUMERAL
    if(numeralDigit.at(size-1) == s1){ // If it is a ones digit

        num++; // Add 1

        // CHECK FOR MORE ONES DIGITS OR A FIVES DIGIT
        for(int i = size-2; i > (size-5 >= 0 ? size-5 : 0); i--){
            if(numeralDigit.at(i) == s1){ // Ones digit
                num++; // Add one
            }else if(numeralDigit.at(i) == s2){ // Fives digit
                return num + 5; // End of roman digit, return
            }
        }

    }else if(numeralDigit.at(size-1) == s2){ // Fives digit

        // CHECK IF ONES DIGIT IS ON LEFT
        if(size - 2 >= 0){
            if(numeralDigit.at(size-2) == s1){ // If it is
                return 4; // End of roman digit, return
            }
        }
        return 5; // It is not, End of Roman digit, return

    }else if(numeralDigit.at(size-1) == s3){ // Tens digit

        // CHECK IF ONES DIGIT IS ON LEFT
        if(size - 2 >= 0){
            if(numeralDigit.at(size-2) == s1){ // IF it is
                return 9; // End of roman digit, return
            }
        }
    }
    return num; // End of roman digit, return

}

/********************************************************************
 * standardNumeralStringCut
 *  This function returns a roman numeral with the given standard
 *  numeral digit cut off at the end
 ********************************************************************/
string standardNumeralStringCut(string numeral, int digit){
    // Cut the string based on the last digit
    if(digit == 4 || digit == 9){ // IV, IX - only 2
        return numeral.substr(0, numeral.size()-2);
    }else if(digit < 4){ // I, II, III - The numbers themselves
        return numeral.substr(0, numeral.size()-digit);
    }else if(digit > 4){ // VI, VII, VIII - The numbers minus 4
        return numeral.substr(0, numeral.size()-(digit-4));
    }
    return numeral;
}

/********************************************************************
 * standardNumeral
 *  This function returns a standard numeral given a roman numeral
 ********************************************************************/
int standardNumeral(string numeral){
    // VARIABLES
    int num = 0; // The return variable
    int digit; // Each digit of numeral

    // 1. Receive digit using standardDigit, 2. cut roman numeral with
    // standardNumeralStringCut, and 3. add the digit in the right place
    // Repeat for each digit place

    // ONES PLACE
    digit = standardDigit(numeral, 'I', 'V', 'X');      // 1
    numeral = standardNumeralStringCut(numeral, digit); // 2
    num += digit;                                       // 3

    // TENS PLACE
    digit = standardDigit(numeral, 'X', 'L', 'C');      // 1
    numeral = standardNumeralStringCut(numeral, digit); // 2
    num += digit * 10;                                  // 3

    // HUNDREDS PLACE
    digit = standardDigit(numeral, 'C', 'D', 'M');      // 1
    numeral = standardNumeralStringCut(numeral, digit); // 2
    num += digit * 100;                                 // 3

    // THOUSANDS PLACE
    digit = standardDigit(numeral, 'M', ' ', ' ');      // 1
    num += digit * 1000;                                // 3
    return num; // Return the number

    // ALTERNATIVE METHOD ONLY USING ONE FUNCTION -- NOT PART OF ACTUAL
    // CODE
    /*for(int i = numeral.size()-1; i >= 0; i--){
        if(numeral.at(i) == 'M'){
            if(i - 1 >= 0){
                if(numeral.at(i - 1) == 'C'){
                    num += 900;
                    i--;
                }else{
                    num += 1000;
                }
            }else{
                num += 1000;
            }
        } else if(numeral.at(i) == 'C'){
            if(i - 1 >= 0){
                if(numeral.at(i-1) == 'X'){
                    num += 90;
                    i--;
                }else{
                    num += 100;
                }
            }else{
                num += 100;
            }
        } else if(numeral.at(i) == 'X'){
            if(i - 1 >= 0){
                if(numeral.at(i - 1) == 'I'){
                    num += 9;
                    i--;
                }else{
                    num += 10;
                }
            }else {
                num += 10;
            }
        } else if(numeral.at(i) == 'D'){
            if(i - 1 > 0){
                if(numeral.at(i - 1) == 'C'){
                    num += 400;
                    i--;
                }else{
                    num += 500;
                }
            }else{
                num += 500;
            }
        } else if(numeral.at(i) == 'L'){
            if(i - 1 > 0){
                if(numeral.at(i - 1) == 'X'){
                    num += 40;
                    i--;
                }else{
                    num += 50;
                }
            }else{
                num += 50;
            }
        } else if(numeral.at(i) == 'V'){
            if(i - 1 > 0){
                if(numeral.at(i - 1) == 'I'){
                    num += 4;
                    i--;
                }else {
                    num += 5;
                }
            }else{
                num += 5;
            }
        } else if(numeral.at(i) == 'I'){
            num += 1;
        }
    }

    return num;*/


}

/********************************************************************
 * romanDigit
 *  This function returns the roman numeral digit of a given standard
 *  numeral digit
 ********************************************************************/
string romanDigit(int num, string s1, string s2, string s3){
    // VARIABLES
    string numeral = ""; // Return variable

    // PROCESSING - Create the correct Roman digit depending on given digit
    switch(num){
    case 1:
        numeral = s1;
        break;
    case 2:
        numeral = s1 + s1;
        break;
    case 3:
        numeral = s1 + s1 + s1;
        break;
    case 4:
        numeral = s1 + s2;
        break;
    case 5:
        numeral = s2;
        break;
    case 6:
        numeral = s2 + s1;
        break;
    case 7:
        numeral = s2 + s1 + s1;
        break;
    case 8:
        numeral = s2 + s1 + s1 + s1;
        break;
    case 9:
        numeral = s1 + s3;
        break;
    }
    return numeral; // Return
}

/********************************************************************
 * romanNumeral
 *  This function returns the roman numeral form of a given standard
 *  numeral
 ********************************************************************/
string romanNumeral(int num){
    // Use each digit of standard numeral to obtain the roman numeral digit

    // ONES PLACE
    string ones = romanDigit(num % 10, "I", "V", "X");
    num /= 10; // Remove last digit

    // TENS PLACE
    string tens = romanDigit(num % 10, "X", "L", "C");
    num /= 10; // Remove last digit

    // HUNDREDS PLACE
    string hundreds = romanDigit(num % 10, "C", "D", "M");
    num /= 10; // Remove last digit

    // THOUSANDS PLACE
    string thousands = romanDigit(num % 10, "M", "", "");

    // Return the concatenation of the digits
    return thousands + hundreds + tens + ones;
}
