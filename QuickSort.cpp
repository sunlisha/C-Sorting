#include "QuickSort.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

void QuickSort::sort(Data* data, int n, int (*compar)(Contact&, Contact&)) {
	int first,last;
	first = 0;
	last = n-1;
	quickSort(data, first, last, (*compar));
}

void QuickSort::quickSort(Data* data, int first, int last, int (*compar)(Contact&, Contact&)) {
	if (first < last) {
		int middle = partition(data, first, last, (*compar));
		if (first < middle - 1) {
			quickSort(data, first, middle - 1, (*compar));
		}
		if (middle + 1 < last) {
			quickSort(data, middle + 1, last, (*compar));
		}
	}
}

int QuickSort::partition(Data* data, int first, int last, int (*compar)(Contact&, Contact&)) {
	// initialize random seed:
	srand (time(NULL));
	Contact pivot( "", "", 0);
	int i,j;
	Contact pivotCandidate1("","",0);
	Contact pivotCandidate2("","",0);
	Contact pivotCandidate3("","",0);
	int rand1,rand2,rand3;
	rand1 = rand() % (last-first+1) + first;
	rand2 = rand() % (last-first+1) + first;
	rand3 = rand() % (last-first+1) + first;
	pivotCandidate1 = data->array[rand1];
	pivotCandidate2 = data->array[rand2];
	pivotCandidate3 = data->array[rand3];
	if (compar(pivotCandidate2, pivotCandidate1) <= 0
		&& compar(pivotCandidate1, pivotCandidate3) <= 0) {
		pivot = pivotCandidate1;
		i = rand1;
	}
	else if (compar(pivotCandidate1, pivotCandidate2) <= 0
			&& compar(pivotCandidate2, pivotCandidate3) <= 0) {
		pivot = pivotCandidate2;
		i = rand2;
	}
	else {
		pivot = pivotCandidate3;
		i = rand3;
	}
	swap(data->array[first],data->array[i]);
	i = first;
	for (j = i + 1; j < last + 1; j++) {
		if (compar( data->array[j], pivot) <= 0) {
			i++;
			swap(data->array[j], data->array[i]);
		}
	}
	swap(data->array[first], data->array[i]);
	return i;
}

void QuickSort::swap(Contact& s1, Contact& s2) {
    Contact tmp( "", "", 0);
    tmp = s1;
    s1 = s2;
    s2 = tmp;
}



