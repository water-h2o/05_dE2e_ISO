#include <iostream>
#include "decompressInput.h"
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



void decompress_all_1e(stringvec allFilenames,
                             int n_events){
	
	string inputFolder  = "./resources/input_tracksets/";
	
	for(int i = 0; i < allFilenames.size(); i++){
	
		string filename_in = inputFolder + allFilenames[i];
		
		cout << "decompressing: ";
		cout << (double)i/(double)allFilenames.size() * 100;
		cout << "% done" << endl;
		
		decompress_file_1e(filename_in, n_events);
	}
	
	cout << "decompressing finished" << endl;
}

void decompress_all_0vbb(stringvec allFilenames,
                               int n_events){
	
	string inputFolder  = "./resources/input_tracksets/";
	
	for(int i = 0; i < allFilenames.size(); i++){
	
		string filename_in = inputFolder + allFilenames[i];
		
		cout << "decompressing: ";
		cout << (double)i/(double)allFilenames.size() * 100;
		cout << "% done" << endl;
		
		decompress_file_0vbb(filename_in, n_events);
	}
	
	cout << "decompressing finished" << endl;
}



// =====================================================================
// === HIGH LEVEL TOOLS ================================================
// =====================================================================



void decompress_file_1e(string filename_in, 
                           int n_events){
	
	ifstream file_in(filename_in);
	ofstream file_out;
	
	file_out.open("placeholder.txt");
	
	string outputFolder = "./resources/input_tracks/";
	
	int fname_multiplier = 0;
	int deposition_track = 0;
	string filename_out;
	
	string curr_line;
	while(std::getline(file_in, curr_line)){
		
		if(curr_line[0] == '#'){
			
			sentence curr_line_sentence;
			
			//cout << "Current file: " << curr_line << endl;
			
			split(curr_line, '#', curr_line_sentence);
			
			fname_multiplier = std::stoi(curr_line_sentence[1]);
			
			curr_line_sentence.clear();
			
		} else if(curr_line[0] == '>'){
			
			sentence curr_line_sentence;
			
			split(curr_line, ' ', curr_line_sentence);
			
			string   curr_branch_string = curr_line_sentence[0];
			sentence curr_branch_sentence;
			
			split(curr_branch_string, '>', curr_branch_sentence);
			
			int curr_branch = std::stoi(curr_branch_sentence[1]);
			
			//cout << "Entering branch " << curr_branch << endl;
			
			if (curr_branch <= n_events){
				
				file_out.close();
				
				deposition_track = 100*fname_multiplier + curr_branch;
				
				filename_out = outputFolder + "track_"     + \
				               to_string(deposition_track) + \
				               ".txt"; 
				               
				file_out.open(filename_out,
				              std::ofstream::out|std::ofstream::trunc);
				             
				file_out.exceptions(ofstream::badbit|ofstream::failbit);
			}
			
			file_out << curr_line << "\n";
			
			curr_line_sentence.clear();
			curr_branch_sentence.clear();
			
		} else {
		
			file_out << curr_line << "\n";
		} 
	}
	
	file_out.close();
}

void decompress_file_0vbb(string filename_in,
                             int n_events){
	
	ifstream file_in(filename_in);
	ofstream file_out;
	
	file_out.open("placeholder.txt");
	
	string outputFolder = "./resources/input_tracks/";
	
	int fname_multiplier = 0;
	int deposition_track = 0;
	string filename_out;
	
	string curr_line;
	while(std::getline(file_in, curr_line)){
		
		if(curr_line[0] == '#'){
			
			sentence curr_line_sentence;
			
			//cout << "Current file: " << curr_line << endl;
			
			split(curr_line, '#', curr_line_sentence);
			
			fname_multiplier = std::stoi(curr_line_sentence[1]);
			
			curr_line_sentence.clear();
			
		} else if(curr_line[0] == '>'){
			
			sentence curr_line_sentence;
			
			split(curr_line, ' ', curr_line_sentence);
			
			string   curr_branch_string = curr_line_sentence[0];
			sentence curr_branch_sentence;
			
			split(curr_branch_string, '>', curr_branch_sentence);
			
			int curr_branch = std::stoi(curr_branch_sentence[1]);
			
			//cout << "Entering branch " << curr_branch << endl;
			
			if (curr_branch <= 2 * n_events && curr_branch % 2 == 0){
				
				file_out.close();
				
				deposition_track = 100*fname_multiplier + curr_branch/2;
				
				filename_out = outputFolder + "track_"     + \
				               to_string(deposition_track) + \
				               ".txt"; 
				               
				file_out.open(filename_out,
				              std::ofstream::out|std::ofstream::trunc);
				             
				file_out.exceptions(ofstream::badbit|ofstream::failbit);
			}
			
			file_out << curr_line << "\n";
			
			curr_line_sentence.clear();
			curr_branch_sentence.clear();
			
		} else {
		
			file_out << curr_line << "\n";
		} 
	}
	
	file_out.close();
}



// =====================================================================
// === MID LEVEL TOOLS =================================================
// =====================================================================



// =====================================================================
// === LOW LEVEL TOOLS =================================================
// =====================================================================




