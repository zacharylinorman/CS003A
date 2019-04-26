#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User{
private:
    string username;
    string password;

public:
    //creates a user with empty name and password.
    User();

    // creates a user with given username and password.
    User(const string& uname,   // Username
         const string& pass);   // Password

    //returns the username
    string get_username() const;

    // returns true if the stored username/password matches with the
    // parameters. Otherwise returns false.
    // Note that, even though a User with empty name and password is
    // actually a valid User object (it is the default User), this
    // function must still return false if given a empty uname string.
    bool check(const string &uname,       // Username
               const string &pass) const; // Password

    // sets a new password. This function will not be used in the
    // current assignment.
    void set_password(const string &newpass); // New password
};


#endif // USER_H
