#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

using namespace std;

class Message{
private:
    // The name of the author of the message
    string author;

    // The subject of the message
    string subject;

    // The body of the message
    string body;

public:
    //default constructor
    Message();

    //Constructor with parameters
    Message(const string &athr,  // The author
            const string &sbjct, // The subject
            const string &body); // The body


    /******************************************************
     * display()
     *  Displays the message.
     ******************************************************/
    void display() const;
};


#endif // MESSAGE_H
