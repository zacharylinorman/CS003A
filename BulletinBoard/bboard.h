#ifndef BBOARD_H
#define BBOARD_H

#include <string>
#include <vector>
#include "user.h"
#include "message.h"

using namespace std;

class BBoard{
private:
    // Title of the bulletin board
    string title;

    // List of users
    vector<User> userList;

    // Current user using the board
    User currentUser;

    // List of messages
    vector<Message> messageList;

    // PRIVATE FUNCTIONS

    /******************************************************
     * display()
     *  Displays the list of messages
     ******************************************************/
    void display() const;

    /******************************************************
     * addMessage()
     *  Adds a new message to the bulletin board with user
     *  input
     ******************************************************/
    void addMessage();
public:
    // CONSTRUCTORS
    BBoard();
    BBoard(const string &ttl); // Title

    // PUBLIC FUNCTIONS
    /******************************************************
     * setup()
     *  This function reads the input file to setup the
     *  list of users.
     ******************************************************/
    void setup(const string &inputFile); // The name of the input file

    /******************************************************
     * login()
     *  This function receives login information from the
     *  user, and only sets the current user when valid
     *  login info is given
     ******************************************************/
    void login();

    /******************************************************
     * run()
     *  This function runs the menu loop to give the user
     *  options on what to do with the bulletin board
     ******************************************************/
    void run();
};

#endif // BBOARD_H
