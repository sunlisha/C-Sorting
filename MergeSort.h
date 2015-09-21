#ifndef MERGESORT_H
#define MERGESORT_H

#include "SortAlgorithm.h"
#include "Contact.h"

// SelectionSort implements the SortAlgorithm interface
class MergeSort : public SortAlgorithm {
public:
    void sort(Data*, int, int (*)(Contact&, Contact&));	// implementation of sort function
private:
	void mergeSort(Data* data, int p, int r, int (*compar)(Contact&, Contact&));
    void merge(Data *data, int p, int q, int r, int (*compar)(Contact&, Contact&)); // it's own private function, not part of the interface
};

#endif
