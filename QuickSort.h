#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortAlgorithm.h"

// QuickSort implements the SortAlgorithm interface
class QuickSort : public SortAlgorithm {
public:
    void sort(Data*, int, int (*)(Contact&, Contact&));	// implementation of sort function
private:
    void quickSort(Data* data, int first, int last, int (*compar)(Contact&, Contact&));
    int partition(Data* data, int first, int last, int (*compar)(Contact&, Contact&));
    void swap(Contact& s1, Contact& s2);
};

#endif
