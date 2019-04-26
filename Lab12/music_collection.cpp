/****************************************************************
 * AUTHOR        : Zachary Norman & Zhuowen Chen
 * ASSIGNMENT    : Lab 12
 * CLASS         : CS03A
 * SECTION       : MW: 1-2:25, TH: 1-3:05
 * DUE DATE      : 4/10/19
 ****************************************************************/
#include "music_collection.h"

// default value of max is a conservative 100
Music_collection::Music_collection()
{
    number = 0;
    max = 100;
    collection = new Tune[max];
}

// sets max to n
Music_collection::Music_collection( int n ){
    number = 0;
    max = n;
    collection = new Tune[max];
}

// overloaded copy constructor
Music_collection::Music_collection( const Music_collection &m){
    number = m.number;
    max = m.max;

    collection = new Tune[max];

    // Made a deep copy, make sure values are not shared
    for(int i = 0; i < number; i++){
        collection[i] = m.collection[i];
    }
}

// returns true if add was successful,
// returns false if not enough room to add
bool Music_collection::add_tune( const Tune &t ){
    if(number == max){
        return false;
    }else{
        collection[number] = t;
        number++;
        return true;
    }
}

// sets the Tune at position index in collection to t,
// returns true if index < number
bool Music_collection::set_tune( int index, const Tune &t ){
    if(index >= number){
        return false;
    }else{
        collection[index] = t;
        return true;
    }
}

// overloaded assignment operator
void Music_collection::operator=( const Music_collection &m ){
    number = m.number;
    max = m.max;

    Tune* temp = collection; // Going to be overwritten, prepare to delete
    collection = new Tune[max];

    // Make a deep copy
    for(int i = 0; i < number; i++){
        collection[i] = m.collection[i];
    }

    delete[] temp;


}

// Destructor
Music_collection::~Music_collection(){
    delete[] collection;
}

// overloaded stream insertion operator
// outputs the title of each Tune in the collection on a separate line
ostream& operator<<( ostream &out, const Music_collection &m ){
    for(int i = 0; i < m.number; i++){
        out << m.collection[i].get_title() << endl;
    }
    return out;
}


Tune::Tune(){
    title = "";
}

Tune::Tune( const string &n ){
    title = n;
}

const string& Tune::get_title() const{
    return title;
}
