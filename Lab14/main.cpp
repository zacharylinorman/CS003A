/****************************************************************
 * AUTHOR        : Zachary Norman, Godwin Liang
 * ASSIGNMENT    : Lab 14
 * CLASS         : CS03A
 * SECTION       : MW: 1-2:25, TH: 1-3:05
 * DUE DATE      : 4/25/19
 ****************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

/****************************************************************
 * Lab 14
 * ______________________________________________________________
 * This program is the recursive building of a maze
 * ______________________________________________________________
 ****************************************************************/

//global constants
const int R = 16, C = 26;

/****************************************************************
 * Point
 *  This struct simulates a position on the maze
 ****************************************************************/
struct Point{
    Point(int c, int r){
        x = c;
        y = r;
    }
    int x;
    int y;
};

/****************************************************************
 * displayMaze()
 *  Outputs the contents of the current maze
 ****************************************************************/
void displayMaze(string maze[][C]); // The maze to display

void initMaze(string maze[][C]); // The maze to initialize

Point generateStart(string maze[][C]); // The maze to generate a start point

Point generateMaze(string maze[][C], // The maze
                   Point p,  // The current position
                   vector<Point>& validPoints); // The vector of possibly valid points

int main()
{
    // Set random seed
    srand(time(0));

    // Declare maze
    string maze[R][C];
    initMaze(maze); // Initialize maze
    Point start = generateStart(maze); // Generate starting point

    // cout << "R: " << start.y << ", C: " << start.x << endl << endl;

    // Create the valid points vector with the starting position
    vector<Point> validPoints(1, start);

    // GENERATE THE MAZE WITH RECURSION
    generateMaze(maze, start, validPoints);

    // Display the finished result
    displayMaze(maze);



    return 0;
}

/***********************************************************
* displayMaze()
*_________________________________________________________
* Outputs the current contents of the maze
*_________________________________________________________
* PRE-CONDITIONS
*   the maze string array is initialized
*
* POST-CONDITIONS
*   Current contents of the string maze are outputted
***********************************************************/
void displayMaze(string maze[][C]){ // The maze to display

    for(int i = 0; i < R; i++){
        for(int k = 0; k < C; k++){
            cout << maze[i][k] << " ";
        }
        cout << endl;
    }
}

/***********************************************************
* initMaze()
*_________________________________________________________
* Fills each spot in the maze with the character 'X'
*_________________________________________________________
* PRE-CONDITIONS
*   maze has been defined with rows and columns
*
* POST-CONDITIONS
*   Each value in the 2D maze array is initialized to 'X'
***********************************************************/
void initMaze(string maze[][C]){ // The maze to initialize

    for(int i = 0; i < R; i++){
        for(int k = 0; k < C; k++){
            maze[i][k] = "X";
        }
    }
}

/***********************************************************
* generateStart()
*_________________________________________________________
* Randomly selects the starting position and ending position
*_________________________________________________________
* PRE-CONDITIONS
*   the maze string array is initialized
*
* POST-CONDITIONS
*   Current contents of the string maze are outputted
***********************************************************/
Point generateStart(string maze[][C]){ // The maze to generate a start point

    int r = rand() % R; // Random row within bounds
    int c = rand() % C; // Random column within bounds

    // If none of them are an edge
    if(!(r == 0 || r == R - 1 || c == 0 || c == C - 1)){

        // Choose either row or column to make edge
        if(rand() % 2){
            r = (rand() % 2 ? R - 1 : 0);
        }else{
            c = (rand() % 2 ? C - 1 : 0);
        }
    }

    // Row is an edge, create start and end
    if(r == 0 || r == R - 1){
        maze[r == 0 ? R - 1 : 0][c] = " ";
        if(R % 2 == 0){
            maze[r == 0 ? R - 2 : 1][c] = " ";
        }

        maze[r][c] = " ";
        r += (r == 0 ? 1 : -1);
        maze[r][c] = " ";
    }else if(c == 0 || c == C - 1){
    // Column is an edge, create start and end

        maze[r][c == 0 ? C - 1 : 0] = " ";
        if(C % 2 == 0){
            maze[r][c == 0 ? C - 2 : 1] = " ";
        }

        maze[r][c] = " ";
        c += (c == 0 ? 1 : -1);
        maze[r][c] = " ";
    }

    // Return the starting point
    Point pos(c, r);
    return pos;

}

/***********************************************************
* generateMaze()
*_________________________________________________________
* Recursively generates the maze path
*_________________________________________________________
* PRE-CONDITIONS
*   starting point p is stored in the Struct
*   maze is initialized
*   vector validPoints is initialized
*
* POST-CONDITIONS
*   Two spaces are carved out, the Point vector validPoints
*   is updated, and the new position is returned
***********************************************************/
Point generateMaze(string maze[][C],  // The maze
                   Point p, // The current position
                   vector<Point>& validPoints){ // The vector of possibly valid points


    int r = p.y; // Current row
    int c = p.x; // Current column


    // right = 0, left = 1, down = 2, up = 3
    int d;       // Direction

    // Whether the direction is valid
    bool rightValid, leftValid, downValid, upValid;
    int numValidDirections = 0;


    rightValid = leftValid = downValid = upValid = false;

    // Check for valid directions
    if(r + 2 < R-1){ // DOWN
        if((maze[r + 1][c] == "X" && maze[r + 2][c] == "X")){
            downValid = true;
            numValidDirections++;
        }
    }
    if(r - 2 >= 1){ // UP
        if((maze[r - 1][c] == "X" && maze[r - 2][c] == "X")){
            upValid = true;
            numValidDirections++;
        }
    }
    if(c + 2 < C-1){ // RIGHT
        if((maze[r][c + 1] == "X" && maze[r][c + 2] == "X")){
            rightValid = true;
            numValidDirections++;
        }
    }
    if(c - 2 >= 1){ // LEFT
        if((maze[r][c - 1] == "X" && maze[r][c - 2] == "X")){
            leftValid = true;
            numValidDirections++;
        }
    }

    // If there is at least one valid direction
    if(rightValid || leftValid || downValid || upValid){
        bool validDirection = false;

        // Choose a random valid direction
        do{
            d = rand() % 4;
            switch(d){
            case 0:
                if(rightValid){
                    validDirection = true;
                }
                break;
            case 1:
                if(leftValid){
                    validDirection = true;
                }
                break;
            case 2:
                if(downValid){
                    validDirection = true;
                }
                break;
            case 3:
                if(upValid){
                    validDirection = true;
                }
                break;
            }
        }while(!validDirection);

        // If there is another valid direction, add to validPoints
        if(numValidDirections > 1){
            validPoints.push_back(p);
        }

        // Carve out two spaces in the direction and change position
        if(d == 2 || d == 3){
            maze[r + (d == 2 ? 1 : -1)][c] = " ";
            maze[r + (d == 2 ? 2 : -2)][c] = " ";
            p.y = r + (d == 2 ? 2 : -2);
        }else{
            maze[r][c + (d == 0 ? 1 : -1)] = " ";
            maze[r][c + (d == 0 ? 2 : -2)] = " ";
            p.x = c + (d == 0 ? 2 : -2);
        }

        // Recursive call with the new position
        generateMaze(maze, p, validPoints);
    }else{
        // Reached a dead end

        // If there are still points that possibly have valid directions
        if(validPoints.size() > 0){

            // Choose a random point
            unsigned randP = rand() % validPoints.size();
            bool validP = false;

            // Check to see if still valid
            while(!validP && validPoints.size() > 0){
                Point temp = validPoints.at(randP);
                int r = temp.y;
                int c = temp.x;
                if(r + 2 < R-1){
                    if((maze[r + 1][c] == "X" && maze[r + 2][c] == "X")){
                        validP = true;
                    }
                }
                if(r - 2 >= 1){
                    if((maze[r - 1][c] == "X" && maze[r - 2][c] == "X")){
                        validP = true;
                    }
                }
                if(c + 2 < C-1){
                    if((maze[r][c + 1] == "X" && maze[r][c + 2] == "X")){
                        validP = true;
                    }
                }
                if(c - 2 >= 1){
                    if((maze[r][c - 1] == "X" && maze[r][c - 2] == "X")){
                        validP = true;
                    }
                }

                // Is not still valid, delete from vector
                if(!validP){
                    validPoints.erase(validPoints.begin()+randP);
                    if(validPoints.size() > 0){
                        randP = rand() % validPoints.size();
                    }
                }
            }

            // Still have valid points after cleanup, jump to random point
            if(validPoints.size() > 0){
                p = validPoints.at(randP);

                // Recursive call with the new position
                generateMaze(maze, p, validPoints);
            }
        }
    }


    return p;
}
