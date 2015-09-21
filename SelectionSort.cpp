#include "SelectionSort.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

void SelectionSort::sort(Data* data, int n, int (*compar)(Contact&, Contact&)) {
    
    int i,j;
    int min;
	
   	//Iterates Position that is currently being changed
   	for(int j = 0; j < n;j++){
   		min = j;
   		//Internal comparison loop
   		for(int i = j+1; i < n; i++){
   			//If current element is the min
   			//if(data->array[min] > data->array[i]){
                        if( compar( data->array[min], data->array[i]) > 0 ) {
   				min = i;
   			}
   		}

   		//Swap the new smallest with current element
   		if(min != j){
   			swap(data->array[j],data->array[min]);
   		}
   	} 
    // look at final sort results
    //cout << "After selectionsort" << endl;
    //for( int i=0; i<10; i++ )
        //data->array[i].print();
}

void SelectionSort::swap(Contact& s1, Contact& s2) {
    Contact tmp( "", "", 0);
    tmp = s1;
    s1 = s2;
    s2 = tmp;
}
