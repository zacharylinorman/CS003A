#include "message.h"
#include <iostream>

using namespace std;

Message::Message()
{
    author = "";
    subject = "";
    body = "";
}

//Constructor with parameters
Message::Message(const string &athr,  // The author
                 const string &sbjct, // The subject
                 const string &body){ // The body
    author = athr;
    subject = sbjct;
    this->body = body;

}

/******************************************************
 * display()
 *  Displays the message.
 ******************************************************/
void Message::display() const{
    cout << subject << endl;
    cout << "from " << author << ": " << body << endl;
}
