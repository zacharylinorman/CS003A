#include "bboard.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//CONSTRUCTORS
BBoard::BBoard()
{
    User def;
    currentUser = def;
}

BBoard::BBoard(const string &ttl)
{
    User def;
    currentUser = def;
    title = ttl;
}

// PRIVATE FUNCTIONS
/******************************************************
 * display()
 *  Displays the list of messages
 ******************************************************/
void BBoard::display() const{

    // Loop through the messages
    for(unsigned i = 0; i < messageList.size(); i++){
        cout << "--------------------"
                "---------------------------" << endl;
        cout << "Message #" << i + 1 << " : ";
        messageList.at(i).display();
    }
    cout << "--------------------"
            "---------------------------" << endl;
}

/******************************************************
 * addMessage()
 *  Adds a new message to the bulletin board with user
 *  input
 ******************************************************/
void BBoard::addMessage(){
    // VARIABLES
    string subject, // Subject of message
            body;   // Message body

    // RECIEVE SUBJECT FROM USER
    cout << "Enter Subject: ";
    cin.get();
    getline(cin, subject);

    // RECEIVE BODY FROM USER
    cout << "Enter Body: ";
    getline(cin, body);

    // Add message to message list
    Message message(currentUser.get_username(), subject, body);
    messageList.push_back(message);
    cout << "Message Recorded!" << endl;
}

/******************************************************
 * setup()
 *  This function reads the input file to setup the
 *  list of users.
 ******************************************************/
void BBoard::setup(const string &inputFile){ // The name of the input file
    // VARIABLES
    ifstream in; // Input stream

    // Open the file
    in.open(inputFile.c_str());
    if(in){

        // VARIABLES
        string name,    // Temp name
                pass;   // Temp pass
        while(in >> name){ // Go through all users
            in >> pass;

            // Add new user to list
            User temp(name, pass);
            userList.push_back(temp);
        }
    }
}

/******************************************************
 * login()
 *  This function receives login information from the
 *  user, and only sets the current user when valid
 *  login info is given
 ******************************************************/
void BBoard::login(){
    // VARIABLES
    string userNameInput, // Input for user name
            passInput;    // Input for password

    cout << "Welcome!" << endl;

    // Continue until valid login
    do{
        // RECEIVE USER NAME
        cout << "Enter your username (\"Q\" or \"q\" to quit): ";
        cin >> userNameInput;
        cout << endl;

        // If not quit
        if(!(userNameInput == "Q" || userNameInput == "q")){

            // RECEIVE PASSWORD
            cout << "Enter your password: ";
            cin >> passInput;
            cout << endl;

            // VARIABLES & DECLARATION - bool to see if login is valid
            bool validLogin = false;

            // Loop through users to check if valid info
            for(unsigned i = 0; i < userList.size(); i++){
                if(userList.at(i).check(userNameInput, passInput)){
                    validLogin = true;

                    // Set the current user
                    currentUser = userList.at(i);
                    break;
                }
            }
            if(!validLogin){
                cout << "Invalid Username or Password!" << endl;
            }
        }else{ // User entered q or Q
            cout << "Bye!";
            break;
        }
    }while(currentUser.get_username() == "");
}

/******************************************************
 * run()
 *  This function runs the menu loop to give the user
 *  options on what to do with the bulletin board
 ******************************************************/
void BBoard::run(){

    // Make sure user logged in
    if(currentUser.get_username() != ""){

        // VARIABLES
        string action; // The user's menu choice

        cout << "Welcome back " << currentUser.get_username()
             << "!" << endl;
        cout << endl;

        // Continue as long as user does not enter q or Q
        do{
            action = "";

            // Display menu
            cout << "Menu" << endl;
            cout << "  - Display Messages ('D' or 'd')" << endl;
            cout << "  - Add New Message ('N' or 'n')" << endl;
            cout << "  - Quit ('Q' or 'q')" << endl;

            // RECEIVE action
            cout << "Choose an action: ";
            cin >> action;
            cout << endl;

            // Different menu choices
            if(action == "D" || action == "d"){ // Display messages

                // Make sure there are messages
                if(messageList.size() > 0){

                    // If there are then display them
                    display();
                    cout << endl;
                }else{
                    cout << "Nothing to display" << endl;
                }
            } else if(action == "N" || action == "n"){ // New message
                addMessage();
                cout << endl;
            } else if(action == "Q" || action == "q"){ // Quit
                cout << "Bye!" << endl;
                exit(0);
            }
        }while(!(action == "Q" || action == "q"));
    }
}
