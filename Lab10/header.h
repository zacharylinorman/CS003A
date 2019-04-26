#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
using namespace std;

struct StudentNode{
    string name;
    unsigned age;
    string major;
    double gpa;

    StudentNode* link;
};

StudentNode* getStudentRecords();

StudentNode getStudent(StudentNode* list, string name);

void outputStudent(StudentNode student);

void outputHeader();

void outputStudentRecords(StudentNode* list);

void removeAndOutputFront(StudentNode* &list);

double averageGPA(StudentNode* list);


#endif // HEADER_H
