/****************************************************************
 * AUTHOR        : Zachary Norman
 * ASSIGNMENT    : Student Records
 * CLASS         : CS03A
 * SECTION       : MW: 1-2:25, TH: 1-3:05
 * DUE DATE      : 3/5/19
 ****************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

/****************************************************************
 * Student Records
 * ______________________________________________________________
 * This program reads an input file of student records and
 * outputs to an output file. It outputs the average grades of
 * the students sorted by classes and last names.
 * ______________________________________________________________
 * INPUT:
 *      inputFileName       - The input file name
 *      outputFileName      - The output file name
 *
 * OUTPUT:
 *      An organized report of the students' grades.
 *
 ****************************************************************/

// CONSTANTS
const int NAME_SIZE = 20 + 1; // The maximum size for first and last names
                              // +1 for the null-terminating character
// STRUCTURES
struct Student{ // The student structure
    char lastName[NAME_SIZE];  // The student's last name
    char firstName[NAME_SIZE]; // The student's first name
    char course;        // The course the student is taking
    int test1Grade;     // The first test grade
    int test2Grade;     // The second test grade
    int finalExamGrade; // The final exam grade
    double testAverage; // The test average
};

// PROTOTYPES
/****************************************************************
 * getLetterGrade()
 *  This function returns a letter grade based on the given score
 ****************************************************************/
char getLetterGrade(double numGrade); // The number score

/****************************************************************
 * sortStudentsByLastName()
 *  This function receives an array of students through the use
 *  of a pointer, as well as the number of students. It then
 *  sorts the students by their last names.
 ****************************************************************/
void sortStudentsByLastName(Student *students, // The student array address
                            int numStudents); // The number of students

/****************************************************************
 * getStudentRecords()
 *  This function returns the address of the array of students
 *  obtained from a given input file stream. It also returns the
 *  number of students by reference.
 ****************************************************************/
Student* getStudentRecords(ifstream &in,   // The input file stream
                           int &numRecords); // The number of students

/****************************************************************
 * writeClassGrades()
 *  This function writes the grade summary for a SINGLE given
 *  class to the output stream using the class name, course code,
 *  array of students, and number of students
 ****************************************************************/
void writeClassGrades(string className, // The name of the class
                      char course,      // The course code
                      ostream &out,    // The output stream
                      const Student *students, // The array of students
                      int numRecords);      // The number of students

/****************************************************************
 * writeGradeSummary()
 *  This function writes the grade summary of all of the students
 *  organized by class name to the given output stream
 ****************************************************************/
void writeGradeSummary(ostream &out, // The output stream
                       const Student *students, // The student array
                       int numRecords); // The number of students



int main()
{

    // VARIABLES
    int numRecords; // Number of students

    Student *students; // The address of the array of students

    string inputFileName; // The name of the input file
    ifstream in;            // The input file stream
    string outputFileName; // The name of the output file
    ofstream out;           // The output file stream


    // Receieve a valid input file name
    do{
        cout << "Please enter the name of the input file." << endl;
        cout << "Filename: ";
        getline(cin, inputFileName);
        cout << endl;

        // Attempt to open file
        in.open(inputFileName.c_str());
    }while(!in); // Loop if not opened

    cout << endl;

    // Receive a valid output file name
    do{
        cout << "Please enter the name of the output file." << endl;
        cout << "Filename: ";
        getline(cin, outputFileName);
        cout << endl;

        // Attempt to open file
        out.open(outputFileName.c_str());
    }while(!out); // Loop if not opened

    // Generate array based on input file
    students = getStudentRecords(in, numRecords);

    // Sort the array by last name
    sortStudentsByLastName(students, numRecords);

    cout << "Processing Complete" << endl << endl;

    // Output the grade summary of the students
    writeGradeSummary(out, students, numRecords);
    writeGradeSummary(cout, students, numRecords);


    // Deallocate the memory used by student array
    delete students;

    // Close the file streams
    in.close();
    out.close();

    return 0;
}


// FUNCTION DEFINITIONS

/****************************************************************
 * getLetterGrade()
 *  This function returns a letter grade based on the given score
 ****************************************************************/
char getLetterGrade(double numGrade){ // The number score
    if(numGrade < 60){ // LESS THAN 60
        return 'F';
    }else if(numGrade < 70){ // GREATER THAN OR = TO 60 LESS THAN 70
        return 'D';
    }else if(numGrade < 80){ // GREATER THAN OR = TO 70 LESS THAN 80
        return 'C';
    }else if(numGrade < 90){ // GREATER THAN OR = TO 80 LESS THAN 90
        return 'B';
    }else{                   // GREATER THAN OR = TO 90
        return 'A';
    }
}

/****************************************************************
 * sortStudentsByLastName()
 *  This function receives an array of students through the use
 *  of a pointer, as well as the number of students. It then
 *  sorts the students by their last names.
 ****************************************************************/
void sortStudentsByLastName(Student *students, // The student array address
                            int numStudents){ // The number of students
    // VARIABLES
    int minIndex; // The index of the student whose last name goes at the
                  // front of the unsorted portion
    string minName; // The last name of the student whose last name goes at
                    // the front of the unsorted portion

    // Loop through all of the students
    for(int i = 0; i < numStudents; i++){

        // Set the minimum index to the front of the unsorted portion
        minIndex = i;
        // Do the same with the last name
        minName = students[i].lastName;

        // Loop through the unsorted portion
        for(int k = i; k < numStudents; k++){

            // Set temporary variable for the current student's name
            string tempName = students[k].lastName;

            // If not comparing the same name
            if(tempName != minName){

                // Loop through the characters of the shorter last name
                for(int j = 0; j < (minName.size() < tempName.size() ?
                                    minName.size() : tempName.size());
                    j++){

                    // If the temp last name comes first
                    if(tolower(tempName.at(j)) < tolower(minName.at(j))){

                        // Set the new min index
                        minIndex = k;
                        // Set the new min last name
                        minName = tempName;

                        // Stop looping through the characters
                        break;

                    // If the min name comes first
                    }else if(tolower(tempName.at(j)) >
                             tolower(minName.at(j))){

                        // Stop looping through the characters
                        break;
                    }

                    // Made it through both checks, characters are equal
                    // Check next character
                }
            }
        }
        // Swap the student whose last name should be at the front of the
        // unsorted portion with the student at the front of the unsorted
        // portion
        Student temp = students[i];
        students[i] = students[minIndex];
        students[minIndex] = temp;

    }

}

/****************************************************************
 * getStudentRecords()
 *  This function returns the address of the array of students
 *  obtained from a given input file stream. It also returns the
 *  number of students by reference.
 ****************************************************************/
Student* getStudentRecords(ifstream &in,   // The input file stream
                           int &numRecords){ // The number of students

    // VARIABLES
    Student *studentsPtr = NULL; // The address of the student array

    // Receive the number of students
    in >> numRecords;
    // Remove the \n
    in.get();

    // Dynamically allocate memory for the number of students in array
    studentsPtr = new Student[numRecords];

    // Loop through all of students
    for(int k = 0; k < numRecords; k++){

        // VARIABLES
        Student student;    // The current student
        char temp;          // A temporary input variable
        int i;              // A count variable

        // DECLARING VARIABLES
        i = 0;              // Set count to 0

        // INPUT

        // Receive chars until a comma for LAST NAME
        while((temp = in.get()) && temp != ','){
            student.lastName[i] = temp;
            i++;
        }
        // Add null terminating character
        student.lastName[i] = '\0';

        // Reset count
        i = 0;
        // Receive chars until a comma for FIRST NAME
        while((temp = in.get()) && temp != ','){
            student.firstName[i] = temp;
            i++;
        }
        // Add null terminating character;
        student.firstName[i] = '\0';

        // Receive the course char
        temp = in.get();
        // Set it to uppercase
        student.course = toupper(temp);

        // Get rid of comma
        temp = in.get();

        // Sum variable for test scores
        int sum = 0;
        i = 100; // Set count to 100
        // Receive chars until a comma for FIRST TEST SCORE
        while((in >> temp) && temp != ','){
            // Obtain the integer value of the character
            temp -= '0';
            sum += temp * i; // Add to sum using count
            i /= 10;         // Reduce i by 1/10
        }
        // If i is 10, then only received one number before comma
        if(i == 10){
            sum /= 100;
        // If i is 1, received two numbers before comma
        }else if(i == 1){
            sum /= 10;
        }
        // Set the test 1 grade
        student.test1Grade = sum;

        // Reset the sum
        sum = 0;
        i = 100; // Reset the count to 100
        // Receive chars until a comma for SECOND TEST SCORE
        while((in >> temp) && temp != ','){
            // Obtain the integer value of the character
            temp -= '0';
            sum += temp * i; // Add to sum using count
            i /= 10;         // Reduce i by 1/10
        }
        // If i is 10, then only received one number before comma
        if(i == 10){
            sum /= 100;
        // If i is 1, received two numbers before comma
        }else if(i == 1){
            sum /= 10;
        }
        // Set the test 2 grade
        student.test2Grade = sum;

        sum = 0; // Reset the sum
        i = 100; // Reset the count to 100

        // Receive chars until a letter (which means next student)
        // for FINAL TEST SCORE
        while((in >> temp)
              && (tolower(temp) > 'z' || tolower(temp) < 'a')){
            // Obtain the integer value of the character
            temp -= '0';
            sum += temp * i; // Add to sum using count
            i /= 10;         // Reduce i by 1/10
        }
        // If i is 10, then only received one number before comma
        if(i == 10){
            sum /= 100;
        // If i is 1, received two numbers before comma
        }else if(i == 1){
            sum /= 10;
        }
        // Set the final exam grade
        student.finalExamGrade = sum;

        // Give the character of the next student back the input stream
        in.putback(temp);

        // Calculate and set the test average
        student.testAverage = (student.test1Grade * 0.3
                               + student.test2Grade * 0.3
                               + student.finalExamGrade * 0.4) ;
        // Set the student in the array
        studentsPtr[k] = student;
    }

    // Return the address of the array
    return studentsPtr;
}

/****************************************************************
 * writeClassGrades()
 *  This function writes the grade summary for a SINGLE given
 *  class to the output stream using the class name, course code,
 *  array of students, and number of students
 ****************************************************************/
void writeClassGrades(string className, // The name of the class
                      char course,      // The course code
                      ostream &out,    // The output stream
                      const Student *students, // The array of students
                      int numRecords){      // The number of students

    // VARIABLES
    double testSum;  // Sum of test scores
    int numStudents; // Number of students in class

    // Output the class name
    out << className << " CLASS" << endl;
    out << endl;

    // Output the class header
    out << "Student Name                         Test Avg     Grade"
        << endl;
    out << "---------------------------------------------------"
           "-------------" << endl;

    // INITIALIZE THE VARIABLES TO 0
    testSum = numStudents = 0;

    // Loop through the students in the array
    for(int i = 0; i < numRecords; i++){

        // Set a temporary variable for the current student
        Student temp = students[i];

        // If the student is in the course
        if(temp.course == course){
            // Create a cstring that can store first and last name
            // With a comma and space (max size is 20 + 20 + 2 (42))
            // so +1 for null terminating character
            char name[NAME_SIZE*2 + 1] = "";

            // Add last name
            strcat(name, temp.lastName);
            // Add comma and space
            strcat(name, ", ");
            // Add first name
            strcat(name, temp.firstName);

            // OUTPUT name
            out.width(40);
            out << left << name;

            // OUTPUT test average
            out.width(4);
            out << right << temp.testAverage;
            testSum += temp.testAverage;

            // OUTPUT letter grade using getLetterGrade()
            out.width(8);
            out << right << getLetterGrade(temp.testAverage);

            out << endl;
            numStudents++; // Add to number of students in class

        }
    }
    // OUTPUT class average
    out << endl;
    out.width(40);
    out << left << "Class Average";
    out.width(4);
    out << right << testSum / numStudents; // Calculate average
    out.width(8);

    // Get letter grade of average
    out << right << getLetterGrade(testSum / numStudents) << endl;
    out << "---------------------------------------------------"
           "-------------" << endl;
}


/****************************************************************
 * writeGradeSummary()
 *  This function writes the grade summary of all of the students
 *  organized by class name to the given output stream
 ****************************************************************/
void writeGradeSummary(ostream &out, // The output stream
                       const Student *students, // The student array
                       int numRecords){ // The number of students

    // Set formatting for numbers
    out.setf(ios::fixed);
    out.setf(ios::showpoint);
    out.precision(2);

    // OUTPUT header
    out << "Student Grade Summary" << endl;
    out << "---------------------" << endl;
    out << endl << endl;

    // OUTPUT English class grades
    writeClassGrades("ENGLISH", 'E', out, students, numRecords);

    // OUTPUT History class grades
    writeClassGrades("HISTORY", 'H', out, students, numRecords);

    // OUTPUT Math class grades
    writeClassGrades("MATH", 'M', out, students, numRecords);


}

