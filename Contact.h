/*
 * Definition of class Contact
 * A Contact is represented by a triple (name, address, zip)
 *
 * author: S Thomas
 * date:   9/1/15
 */

#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string> 
#include <vector>

using namespace std;

class Contact {
private:
    string name;
    string address;
    int zip;
    
public:
    friend bool operator< (const Contact&, const Contact&);
    friend bool operator> (const Contact&, const Contact&);
    Contact( string, string, int ); // constructor 
    void print();     
    static int compareZip( Contact&, Contact&);     // return -1/0/1
    static int compareName( Contact&, Contact&);
    static int compareAddress( Contact&, Contact&);
};



#endif
