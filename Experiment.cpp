/*
 * Implementation of class Experiment
 *
 * author: S Thomas
 * date:   9/1/15
 */

#include <sys/time.h>
#include <fstream>
#include <assert.h>
#include "Experiment.h"
#include "Data.h"

int const repetitions = 25; // do runs of size 1K, 2K, .. 25K

// Constructor 
// ------------------------------------------------------------------------
Experiment::Experiment(Data* d) {
    assert( d != 0 );
    data = d;		// Save Data object
}

// addAlgorithm(alg): Add SortAlgorithm alg to the experiment
// ------------------------------------------------------------------------
void Experiment::addAlgorithm(SortAlgorithm* alg) {
    assert( alg != 0 );
    algorithm.push_back(alg); 	// Save ptr into vector
}

// get_timestamp(): returns current time stamp in seconds
// ------------------------------------------------------------------------
timestamp_t Experiment::get_timestamp () {
    struct timeval now;
    gettimeofday (&now, NULL);
    return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

// Experiment(): runs a timing experiment for all 
//               the algorithms added to the experiment.
//
//   - Run sorts on array sizes of 1000 to 100000
//   - The timing results are stored in the 2D array timings[alg #][size]
// ------------------------------------------------------------------------
void Experiment::run() {
    timestamp_t startTime;		// start time
    timestamp_t endTime;		// end time
    
    cout << "\nRunning timing experiments on arrays of size 1K to 25K\n" << endl;

    // Allocate storage for the timing output and problem size
    timings = new double* [algorithm.size()];
    for (int i = 0; i < algorithm.size(); i++) {
        timings[i] = new double[25];
    }

    // Run each algorithm in sequence
    for( int k=0; k<algorithm.size(); k++ ){
        int N = 0;
        for( int run=0; run<repetitions; run++ ){
            // increase the number of values to sort by increments of 1000
            N = N + 1000;

	    data->refresh();
		    
	    // Time the sorting algorithm 
	    startTime = get_timestamp();	  // start the timer
             
            // sort on Name and then Zip
	    (algorithm[k])->sort(data, N, Contact::compareName);
	    (algorithm[k])->sort(data, N, Contact::compareZip);

            endTime = get_timestamp();	  // stop the timer

            // verify results by printing first 10 contacts
            cout << "\nFirst 10 records after sorting\n"; 
            data->print(0,10);
            
	    // Average number of elapsed seconds over the trials
            timings[k][run] = (endTime - startTime) / 1000000.0L;
            cout << "Sorted " << N << " records using algorithm [" << k << "]" << endl;
	}
    }
}

// save(filename): save all timing results to filename
// file format is:
// problemSize  timing-Alg0  timing-Alg1 ...
// ------------------------------------------------------------------------
void Experiment::save(string filename) {
    ofstream outfile;
    outfile.open(filename);
    if ( !outfile.is_open() ) {
        cout << "Error opening file " << filename << endl;
        assert(0);        
    }

    cout << "Writing results to file " << filename << endl;
    for (int i = 0; i < repetitions; i++) {
        outfile << 1000*(i+1);
        for (int k = 0; k < algorithm.size(); k++) {
            outfile << " " << timings[k][i];
        }
        outfile << endl;
    }
    outfile.close();
}
