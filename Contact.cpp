/*
 * Implementation of class Contact
 *
 * author: S Thomas
 * date:   9/1/15
 */

#include "Contact.h"
#include <assert.h>
#include <iostream>
#include <string>

using namespace std;

// Constructor 
// ------------------------------------------------------------------------
Contact::Contact(string namearg, string addressarg, int ziparg) {
   name = namearg;
   address = addressarg;
   zip  = ziparg;
}

bool operator> (const Contact& lhs, const Contact& rhs){
   return lhs.zip > rhs.zip;
}

bool operator< (const Contact& lhs, const Contact& rhs){
   return lhs.zip < rhs.zip;
}

// compareZip( other ): return -1 if thisone value is less than other.zip
//                      return 0 if thisone value is equal to other.zip
//                      return +1 if thisone value is greater than other.zip 
// ------------------------------------------------------------------------
int Contact::compareZip( Contact& thisone, Contact& other ) {
   int temp = thisone.zip - other.zip;
   return ( 0 < temp ) - ( temp < 0 );
}

// compareName( other ): return -1 if thisone value is less than other.name
//                       return 0 if thisone value is equal to other.name
//                       return +1 if thisone value is greater than other.name 
// ------------------------------------------------------------------------
int Contact::compareName( Contact& thisone, Contact& other ) {
   return (thisone.name).compare( other.name );
}

// compareAddress( other ): return -1 if thisone value is less than other.address
//                          return 0 if thisone value is equal to other.address
//                          return +1 if thisone value is greater than other.address 
// ------------------------------------------------------------------------
int Contact::compareAddress( Contact& thisone, Contact& other ) {
   return (thisone.address).compare( other.address );
}

// print():  print a representation of a Contact object
// ------------------------------------------------------------------------
void Contact::print( ) {
   cout << name << " | " << address << " | " << zip << endl;
}

