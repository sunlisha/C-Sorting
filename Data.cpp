/*
 * Implementation of class Data
 *
 * author: S Thomas
 * date:   9/1/15
 */

#include "Data.h"
#include <assert.h>
#include <fstream>
#include <sstream>

using namespace std;

// Constructor 
// ------------------------------------------------------------------------
Data::Data(string filename) {

    // Read text data from filename, one line at the time
    ifstream infile(filename);
    string line;    
    if (!infile.is_open()) {
        cout << "Error opening file " << filename << endl;
        assert(0);
    }
    cout << "Reading data from file...\n";
    while ( getline(infile, line) ) {
        stringstream ssline( line );
        vector<string> elems;
        string stemp;
        // split line at '|' character into 3 parts
        while( getline(ssline, stemp, '|') )
             elems.push_back( stemp );        
        string name = elems[0];
        string address = elems[1];
        int    zip     = stoi( elems[2] );
        // create Contact objects
        array.push_back( Contact( name, address, zip ) );	// Save into array
        original.push_back( Contact( name,address,zip ) );	// and also in original
    }
    cout << "\tRead " << array.size() << " lines\n";
    infile.close();
}


// refresh(): reset array to original values. Assignment is overloaded 
//   with vector<string> so data is actually copied.
// ------------------------------------------------------------------------
void Data::refresh() {
    array = original;
}


// print(int start, int size): print array[start] to array[start+size] to
//   the screen.
// ------------------------------------------------------------------------
void Data::print(int start, int size) {
   cout << endl;
   for (int i = start; i < start+size; i++) {
      array[i].print();
   }
}
