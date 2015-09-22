/*
 * Definition of class Data
 * Data 
 *
 * author: S Thomas
 * date:   9/1/15
 */

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>
#include <vector>
#include "Contact.h"

using namespace std;

class Data {
private:
    string dataFile;
    vector<Contact> original; // Original copy of the input data 
    
public:
    vector<Contact> array;    // Data that can be modified
    void refresh();
    void print( int, int );   // print [start...start+n]
    Data( string );           // constructor
};

#endif
