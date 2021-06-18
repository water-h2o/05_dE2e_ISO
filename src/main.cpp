#include <iostream>

#include <vector>
#include <string>

#include <algorithm>
#include <iterator>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <numeric> // for std::accumulate

#include "myTypedefs.h"
#include "generalTools.h"
#include "decompressInput.h"
#include "dE2elec.h"
#include "getFilesInDir.h"

using namespace std;

# ifndef __CINT__

// =====================================================================
// == FUNCTION FORESHADOWING ===========================================
// =====================================================================







// =====================================================================
// == THE MAIN FUNCTION ITSELF =========================================
// =====================================================================



int main(int argc, char *argv[]){

	int n_events_per_trackset = 100;
	bool is0vbb = true; // true --> 0vbb ; false --> 1e 

	// -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
	// -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
	// -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -

	stringvec v_tracksets;
	read_directory("./resources/input_tracksets", v_tracksets);
	sort(v_tracksets.begin(), v_tracksets.end());

	cout << "finished reading the input tracksets." << endl;
	
	if(is0vbb){ // tracksets are 0vbb
	
		decompress_all_0vbb(v_tracksets,n_events_per_trackset);
	
	} else {    // tracksets are 1e
	
		decompress_all_1e  (v_tracksets,n_events_per_trackset);
	}
	
	// -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
	// -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
	// -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -
	
	stringvec v_tracks;
	read_directory("./resources/input_tracks", v_tracks);
	sort(v_tracks.begin(), v_tracks.end());

	cout << "finished reading the input tracks." << endl;
	
	dE2elec_all_files(v_tracks);
	
	return 0;
}



// =====================================================================
// == HIGH LEVEL FUNCTIONS =============================================
// =====================================================================







// =====================================================================
// == MID LEVEL FUNCTIONS ==============================================
// =====================================================================







// =====================================================================
// == LOW LEVEL FUNCTIONS ==============================================
// =====================================================================







# endif
