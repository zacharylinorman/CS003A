#include "header.h"
#include <iostream>

using namespace std;

StudentNode* getStudentRecords(){
    StudentNode* head = nullptr;
    ifstream in;
    in.open("inFile.txt");
    if(in){
        string input;
        while(getline(in, input)){
            StudentNode* temp;
            temp = new StudentNode;
            if(head == NULL){
                head = temp;
            }else{
                temp->link = head;
                head = temp;
            }
            head->name = input;
            in >> head->age;
            in.get();
            getline(in, input);
            head->major = input;
            in >> head->gpa;
            in.get();
            getline(in, input);
        }
    }
    return head;
}

StudentNode getStudent(StudentNode* list, string name){
    StudentNode* current = list;
    while(current->name != name){
        current = current->link;
        if(current == NULL){
            break;
        }
    }
    return *current;
}

void outputStudent(StudentNode student){
    cout.width(15);
    cout << left << student.name;
    cout.width(7);
    cout << left << student.age;
    cout.width(15);
    cout << left << student.major;
    cout << student.gpa;
}

void outputHeader(){

    cout.width(15);
    cout << left << "Name";
    cout.width(7);
    cout << left << "Age";
    cout.width(15);
    cout << left << "Major";
    cout << "GPA";
}

void outputStudentRecords(StudentNode* list){
    cout.precision(1);
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);

    outputHeader();
    cout << endl;

    StudentNode* current = list;
    while(current != NULL){
        outputStudent(*current);
        cout << endl;
        current = current->link;
    }

}

void removeAndOutputFront(StudentNode* &list){
    cout << "Front Node Deleted:" << endl;
    outputHeader();
    cout << endl;
    outputStudent(*list);
    list = list->link;
}

double averageGPA(StudentNode* list){
    StudentNode* current = list;
    double sum = 0;
    int count = 0;
    while(current != NULL){
        sum += current->gpa;
        count++;
        current = current->link;
    }

    return sum / count;
}
