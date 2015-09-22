/*
 * Driver function for Exercise 1
 *
 * author: S Thomas
 * date:   9/1/15
 */

#include <iostream>
#include <string>
#include "Data.h"
#include "Experiment.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;

int main() {
    
    // Read file web2random which contains 235886 word entries
    Data data("contacts");
    cout << "\nOriginal data [0-9]" << endl;
    data.print(0,10);
 
    Experiment experiment(&data);

    // Add the algortithms to the experiment
    // The columns in Result.txt will be in the same order as the calls to AddAlgorithm()
    experiment.addAlgorithm(new SelectionSort());
    experiment.addAlgorithm(new MergeSort());
    experiment.addAlgorithm(new QuickSort());
    
    experiment.run();
    experiment.save("Results.txt");
}


