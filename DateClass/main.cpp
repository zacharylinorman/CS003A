#include <iostream>
#include "date.h"

using namespace std;

void test1();
void test2();
void test3();
void test4();
void test5();

int main()
{
    int testNum;
    cout << "Enter test number: ";
    cin >> testNum;
    cout << endl;

    switch(testNum){
    case 1:
        test1();
        break;
    }

    return 0;
}

void test1()
{
    cout << "1. Default" << endl;
    Date x = Date();
    cout << "numeric:  " ;
    x.printNumeric(); cout << endl;
    cout << "alpha:  ";
    x.printAlpha();
    cout << endl;
    cout << "-------------------" << endl;
}
void test2()
{
    cout << "2. Numeric Date: 7.3.1991" << endl;
    Date x = Date(7,3,1991);
    cout << "numeric:\t" ;
    x.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "­­­­­­­­­­­­­-------------" << endl;
}
void test3()
{
    cout << "3. Alpha Date: July 3, 1991" << endl;
    Date x = Date("July",3,1991);
    cout << "numeric:\t" ;
    x.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "-------------­­­­­­­­­­­­­" << endl;
}
void test4()
{
    cout << "4. Invalid Numeric Date: 0.3.1991 ­> 1.3.1991" << endl;
    Date x = Date(0,3,1991);
    cout << "numeric:\t" ;
    x.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "­­­­­­­­­­­­­-------------" << endl;
}
void test5()
{
    cout << "5. Invalid Alpha Date: 1.adf.1991 ­> 1.1.2000" << endl;
    Date x = Date("adf",1, 1991);
    cout << "numeric:\t" ; x.printNumeric();
    cout << endl;
    cout << "alpha:\t";
    x.printAlpha();
    cout << endl;
    cout << "­­­­­­­­­­­­­-------------" << endl;
}
