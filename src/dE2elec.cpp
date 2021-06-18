#include <iostream>
#include "dE2elec.h"
#include "myTypedefs.h"
#include "generalTools.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;



// =====================================================================
// === MAIN FUNCTION ===================================================
// =====================================================================



void dE2elec_all_files(stringvec allFilenames){
	
	string  lookupTable_filename = "./resources/lookupTable/"; 
	lookupTable_filename        += "chargeYieldLog.txt";
	
	axis    energy_lookup;
	dataset eYield_lookup;
	
	openLookupTable(lookupTable_filename, 
	                energy_lookup, 
	                eYield_lookup);
	
	cout << "generated lookup table" << endl;
	
	string inputFolder  = "./resources/input_tracks/";
	string outputFolder = "./resources/output/";
	
	for(int i = 0; i < allFilenames.size(); i++){
	
		string filename_in  = inputFolder  + allFilenames[i];
		string filename_out = outputFolder + allFilenames[i];
		
		cout << "converting to e- : ";
		cout << (double)i/(double)allFilenames.size() * 100;
		cout << "% done" << endl;
		
		dE2elec_curr_file(filename_in, 
		                  filename_out, 
		                  energy_lookup, 
		                  eYield_lookup);
	}
	
	cout << "converting finished" << endl;
}



// =====================================================================
// === HIGH LEVEL TOOLS ================================================
// =====================================================================



void openLookupTable(std::string lookupTable_filename,
                           axis& energy_lookup, // output
                        dataset& eYield_lookup  // output
                    ){

	ifstream file_in(lookupTable_filename);

	string curr_line;
	while(std::getline(file_in, curr_line)){
		
		sentence curr_line_sentence;
		
		split(curr_line, '\t', curr_line_sentence);
		
		energy_lookup.push_back(std::stod(curr_line_sentence[0]));
		eYield_lookup.push_back(std::stod(curr_line_sentence[1]));
		
		double curr_energy = std::stod(curr_line_sentence[0]);
		
		cout << "curr_energy = " << curr_energy << endl;
		
		curr_line_sentence.clear();
	}
}

void dE2elec_curr_file(std::string filename_in,
                       std::string filename_out,
                             axis& energy_lookup, // input
                          dataset& eYield_lookup  // input
                      ){

	ifstream file_in(filename_in );
	ofstream file_out;
	
	file_out.open(filename_out,
	              std::ofstream::out | std::ofstream::trunc);
	              
	file_out.exceptions(ofstream::badbit | ofstream::failbit);
	
	string placeholder0 = "pHold0";
	string x, y, z; 
	string elec_str;
	string placeholder5 = "pHold5";
	
	double E, dE;
	
	string curr_line;
	while(std::getline(file_in, curr_line)){
		
		if(curr_line[0] == '#'){
			
			//cout << "Current file: " << curr_line << endl;
			
		} else if(curr_line[0] == '>'){
			
			sentence curr_line_sentence;
			
			split(curr_line, ' ', curr_line_sentence);
			
			//cout << "Entering branch " << curr_line_sentence[0] << endl;
			
			curr_line_sentence.clear();
			
		} else {
		
			sentence curr_line_sentence;
			
			split(curr_line, ' ', curr_line_sentence);
			
			x  = curr_line_sentence[1];
			y  = curr_line_sentence[2];
			z  = curr_line_sentence[3];
			E  = std::stod(curr_line_sentence[5]);
			dE = std::stod(curr_line_sentence[6]);
			
			int elec = dE2elec_curr_E_dE(E + dE, 
			                             dE,
			                             energy_lookup, 
			                             eYield_lookup);
			                             
			elec_str = to_string(elec);
			
			file_out << placeholder0 << "\t";
			file_out << x            << "\t";
			file_out << y            << "\t";
			file_out << z            << "\t";
			file_out << elec_str     << "\t";                       
			file_out << placeholder5 << "\n";
			
			curr_line_sentence.clear();
		} 
	}
	
	file_out.close();
}



// =====================================================================
// === MID LEVEL TOOLS =================================================
// =====================================================================



int dE2elec_curr_E_dE(double curr_E,
                      double curr_dE,
                       axis& energy_lookup, // input
                    dataset& eYield_lookup  // input
                     ){

	int out;

	double energy_lookup_L, energy_lookup_R;
	double eYield_lookup_L, eYield_lookup_R;
	bool foundEnergy_lookup_R = false;
	
	idx i = 0;
	while(!foundEnergy_lookup_R){
		
		if(energy_lookup[i] < curr_E){
			
			i++;
			
		} else {
			
			foundEnergy_lookup_R = true;
		}
	}
	
	energy_lookup_L = energy_lookup[i-1]; 
	energy_lookup_R = energy_lookup[i];
	eYield_lookup_L = eYield_lookup[i-1];
	eYield_lookup_R = eYield_lookup[i];
	
	double energy_gap = energy_lookup_R - energy_lookup_L;
	double eYield_gap = eYield_lookup_R - eYield_lookup_L;
	
	double curr_E_remainder = curr_E - energy_lookup_L;
	double curr_E_fraction  = curr_E_remainder / energy_gap;
	
	double eYield_interpol = eYield_gap * curr_E_fraction;
	
	out = int((eYield_lookup_L + eYield_interpol) * curr_dE);
	
	return out;
}



// =====================================================================
// === LOW LEVEL TOOLS =================================================
// =====================================================================




