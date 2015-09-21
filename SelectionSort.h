/*
 * Definition of class SelectionSort
 *
 * author: S Thomas
 * date:   9/1/15
 */

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "SortAlgorithm.h"

// SelectionSort implements the SortAlgorithm interface
class SelectionSort : public SortAlgorithm {
public:
    void sort(Data*, int, int (*)(Contact&, Contact&));	// implementation of sort function
private:
    void swap(Contact&, Contact&); // it's own private function, not part of the interface
};

#endif
