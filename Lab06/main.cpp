/****************************************************************
 * AUTHOR        : Zachary Norman and Yongqiang Zhang
 * ASSIGNMENT    : Lab 05
 * CLASS         : CS03A
 * SECTION       : MW: 1-2:25, TH: 1-3:05
 * DUE DATE      : 3/11/19
 ****************************************************************/
#include <iostream>
#include <vector>

using namespace std;

/****************************************************************
 * Lab 06
 * ______________________________________________________________
 * This program performs matrix addition and matrix
 * multiplication.
 * ______________________________________________________________
 * INPUT:
 *      The matrices' number of rows, columns, and the matrices
 *      themselves.
 * OUTPUT:
 *      The results of the matrix addition and multiplication.
 *
 ****************************************************************/

// PROTOTYPES
/****************************************************************
 * matrixFill()
 *  This function fills a given matrix with user input
 ****************************************************************/
void matrixFill(vector<vector<int>> &v); // The matrix to fill

/****************************************************************
 * displayMatrix()
 *  This function displays a given matrix
 ****************************************************************/
void displayMatrix(const vector<vector<int>> &v); // matrix to display

/****************************************************************
 * matrixAddition()
 *  This function adds matrices a and b and stores the result in c
 ****************************************************************/
void matrixAddition(const vector<vector<int>> &a, // First matrix
    const vector<vector<int>> &b,                 // Second matrix
    vector<vector<int>> &c);                      // Sum

/****************************************************************
 * matrixMultiplication()
 *  This function multiplies matrices a and b and stores the
 *  result in c
 ****************************************************************/
void matrixMultiplication(const vector<vector<int>> &a, // First matrix
    const vector<vector<int>> &b,                       // Second matrix
    vector<vector<int>> &c);                            // Sum


int main()


{
    // ADDITION
    {
        // VARIABLES
        int r,  // Number of rows
            c;  // Number of columns

        // INPUT - receive number of rows and columns from the user
        cout << "Enter the number of rows and columns of the matrices "
                "to add: ";
        cin >> r >> c;
        cout << endl;

        // VARIABLES
        vector<int> temp(c);          // Temporary vector for the matrices
        vector<vector<int>> a(r, temp); // First matrix
        vector<vector<int>> b(r, temp); // Second matrix
        vector<vector<int>> s(r, temp); // Sum matrix

        // INPUT - receive matrix A from user
        cout << "Enter matrix A: ";
        matrixFill(a);
        cout << endl;
        // OUTPUT - matrix a
        cout << "For matrix A you entered: " << endl;
        displayMatrix(a);

        // INPUT - receive matrix B from user
        cout << "Enter matrix B: " << endl;
        matrixFill(b);
        // OUTPUT - matrix b
        cout << "For matrix B you entered: " << endl;
        displayMatrix(b);

        // Add the vectors and store in s
        matrixAddition(a, b, s);

        // OUTPUT - the result
        cout << "sum of A and B is: " << endl;
        displayMatrix(s);
    }

    cout << endl << endl;

    // MULTIPLICATION
    {
        // VARIABLES
        int ra, ca, // Rows and columns for vector a
            rb, cb; // Rows and columns for vector b
        cout << "Now for multiplication." << endl;

        // INPUT - receive valid input for rows and columns of the vectors
        do{
            cout << "Enter the number of rows and columns of matrix A: ";
            cin >> ra >> ca;
            cout << endl;
            cout << "Enter the number of rows and columns of matrix B: ";
            cin >> rb >> cb;
            cout << endl;

            if(ca != rb){ // In order to multiply, ca must equal rb
                cout << "The number of columns of matrix A must be the "
                        "same as the number of rows of matrix B." << endl;
            }
        }while(ca != rb);

        // VARIABLES
        vector<int> tempA(ca); // temp vector with ca columns
        vector<int> tempB(cb); // temp vector with cb columns
        vector<vector<int>> a(ra, tempA); // matrix a
        vector<vector<int>> b(rb, tempB); // matrix b
        vector<vector<int>> p(ra, tempB); // Product matrix

        // INPUT - receive matrix A from user
        cout << "Enter matrix A: ";
        matrixFill(a);
        cout << endl;
        // OUTPUT - matrix a
        cout << "For matrix A you entered: " << endl;
        displayMatrix(a);

        // INPUT - receive matrix B from user
        cout << "Enter matrix B: " << endl;
        matrixFill(b);
        // OUTPUT - matrix b
        cout << "For matrix B you entered: " << endl;
        displayMatrix(b);

        // Multiply the matrices and
        matrixMultiplication(a, b, p);

        // OUTPUT - the result
        cout << "product of A and B is: " << endl;
        displayMatrix(p);

    }

    return 0;
}
/****************************************************************
 * matrixFill()
 *  This function fills a given matrix with user input
 ****************************************************************/
void matrixFill(vector<vector<int>> &v){ // The matrix to fill
    for(int i = 0; i < v.size(); i++){
        for(int k = 0; k < v.at(i).size(); k++){
            cin >> v[i][k];
        }
    }
}


/****************************************************************
 * displayMatrix()
 *  This function displays a given matrix
 ****************************************************************/
void displayMatrix(const vector<vector<int>> &v){ // matrix to display

    // OUTPUT - output the vector
    for(int i = 0; i < v.size(); i++){
        for(int k = 0; k < v.at(i).size(); k++){
            cout << v[i][k] << " ";
        }
        cout << endl;
    }
}
/****************************************************************
 * matrixMultiplication()
 *  This function multiplies matrices a and b and stores the
 *  result in c
 ****************************************************************/
void matrixMultiplication(const vector<vector<int>> &a, // First matrix
    const vector<vector<int>> &b,                       // Second matrix
    vector<vector<int>> &c){                            // Sum

    // Use the given formula to find product (I switched k and j)
    for(int i = 0; i < c.size(); i++){
        for(int k = 0; k < c.at(i).size(); k++){
            for(int j = 0; j < c.at(i).size(); j++){ // Sigma part
                c[i][k] += a[i][j]*b[j][k];
            }
        }
    }
}
/****************************************************************
 * matrixAddition()
 *  This function adds matrices a and b and stores the result in c
 ****************************************************************/
void matrixAddition(const vector<vector<int>> &a, // First matrix
    const vector<vector<int>> &b,                 // Second matrix
    vector<vector<int>> &c){                      // Sum

    // Use the given formula to find the sum
    for(int i = 0; i < c.size(); i++){
        for(int k = 0; k < c.at(i).size(); k++){
            c[i][k] = a[i][k] + b[i][k];
        }
    }
}
