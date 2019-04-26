#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    StudentNode* list = getStudentRecords();
    outputStudentRecords(list);
    cout << endl;
    cout << "Student found:" << endl;
    outputStudent(getStudent(list, "Anna White"));
    cout << endl << endl;
    removeAndOutputFront(list);
    cout << endl << endl;
    cout << "Updated Student List:" << endl;
    outputStudentRecords(list);
    cout << endl;
    cout.precision(2);
    cout << "GPA: " << averageGPA(list) << endl;
    return 0;
}
