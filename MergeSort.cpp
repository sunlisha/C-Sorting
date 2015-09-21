#include "MergeSort.h"
#include "Contact.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

void MergeSort::sort(Data* data, int n, int (*compar)(Contact&, Contact&)) {
    int first = 0; //p is first index
    int last = n-1; //r is last index
    mergeSort(data, first, last, (*compar));
}

void MergeSort::mergeSort(Data* data, int first, int last, int (*compar)(Contact&, Contact&)) {
  if (first < last) { //more than one item
    int middle = (first + last)/2; //divide into two subarrays
    mergeSort(data, first, middle, (*compar));
    mergeSort(data, middle+1, last, (*compar));
    merge(data, first, middle, last, (*compar));
  }
  return;
}

void MergeSort::merge(Data *data, int first, int middle, int last, int (*compar)(Contact&, Contact&)) {
    int n1 = middle - first + 1; //length of left array
    int n2 = last - middle; //length of right array
    vector<Contact> L (n1 + 1, Contact("", "", 0)); //initialize vector of dummy Contacts
    vector<Contact> R (n2 + 1, Contact("", "", 0)); //initialize vector of dummy Contacts
    for (int i = 0; i < n1; i++) { //copy left Contacts into left vector
      L[i] = data->array[first+i];
    }
    for (int j = 0; j < n2; j++) { //copy right Contacts into right vector
      R[j] = data->array[middle+1+j];
    }

    L[n1] = Contact("zzzz", "address", 99999); //last value equal to high value to be sentinel value
    R[n2] = Contact("zzzz", "address", 99999);

    vector<Contact> A ((last - first) + 1, Contact("", "", 0)); //initialize vector to hold sorted array
    int i = 0;
    int j = 0;

    for (int k = 0; k < (last - first) + 1; k++) { //merge them back      
      if (compar( L[i], R[j]) <= 0) { //if L[i] is smaller or equal       
        A[k] = L[i];        
        i++;       
      }
      else {
        A[k] = R[j];
        j++;        
      }
    }

    int m = 0;

    for (int n = first; n < last + 1; n++) {//copy back to array
      data->array[n] = A[m];
      m++;
    }
    return;
}