#include <iostream>
#include "generalTools.h"
#include "myTypedefs.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;



// =====================================================================
// === MAIN FUNCTION ===================================================
// =====================================================================



void split(const string& s, 
                    char c, 
               sentence& v 
          ){ // from O'reilly
	
	string::size_type i = 0;
	string::size_type j = s.find(c);

	while (j != string::npos) {
		
		v.push_back(s.substr(i, j-i));
		i = ++j;
		j = s.find(c, j);

		if (j == string::npos){
		
			v.push_back(s.substr(i, s.length()));
		}
	}
	
	if(v.size() < 1){ // if no matches, return the entire string
      
		v.push_back(s);
	}
}



// =====================================================================
// === HIGH LEVEL TOOLS ================================================
// =====================================================================







// =====================================================================
// === MID LEVEL TOOLS =================================================
// =====================================================================







// =====================================================================
// === LOW LEVEL TOOLS =================================================
// =====================================================================




