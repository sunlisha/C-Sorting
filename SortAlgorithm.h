/*
 * Definition of Interface SortAlgorithm
 *   All sorting algorithms must inherit from this class and implement
 *   sort() exactly as specified below.
 *
 * author: S Thomas
 * date:   9/1/2015
 */

#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#include <vector>
#include <string>
#include "Data.h"
#include "Contact.h"

using namespace std;

// SortAlgorithm is an interface (or abstract class).
// Any algorithm inheriting from this class must implement function sort() 
class SortAlgorithm {
public:
    // Define sort() as a pure virtual function. That is, it must be 
    // implemented by a subclass.
    //virtual void sort(Data*, int) = 0;
    virtual void sort(Data*, int, int (*)(Contact&,Contact&) ) = 0;
};

#endif
