#include <iostream>
#include "intVector.h"
/* This is the test File for the IntVec Intro
*/

using namespace std;

int main(){
    IntVector v;
    cout << "Testing default constructor\n";
    cout << "size: " << v.size() << "\tcapacity: " << v.capacity() << endl;
    cout << "Testing empty member function\n";
    if (v.empty())
        cout << "v is empty\n";
    else
        cout << "v is not empty\n";
    cout << "\n\n";

    IntVector v2(5);
    cout << "Testing one parameter constructor\n";
    cout << "size: " << v2.size() << "\tcapacity: " << v2.capacity() << endl;
    cout << "Testing empty member function\n";
    if (v2.empty())
        cout << "v2 is empty\n";
    else
        cout << "v2 is not empty\n";

    cout << "Testing at function by displaying contents of v2\n";
    for (unsigned i = 0; i < v2.size(); i++){
        cout << v2.at(i) << " ";
    }
    cout << endl;
    cout << "\n\n";

    IntVector v3(5,9);
    cout << "Testing two parameter constructor\n";
    cout << "size: " << v3.size() << "\tcapacity: " << v3.capacity() << endl;
    cout << "Testing empty member function\n";
    if (v3.empty())
        cout << "v3 is empty\n";
    else
        cout << "v3 is not empty\n";

    cout << "Testing at function by displaying contents of v3\n";
    for (unsigned i = 0; i < v3.size(); i++){
        cout << v3.at(i) << " ";
    }
    cout << endl;
    cout << "\n\n";

}
