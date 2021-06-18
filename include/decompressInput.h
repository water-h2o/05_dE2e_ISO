#ifndef DECOMPRESSINPUT_H
#define DECOMPRESSINPUT_H

#include <vector>
#include <string>

#include "myTypedefs.h"

// === MAIN FUNCTIONS ==================================================

void decompress_all_1e  (stringvec allFilenames,
                               int n_events);

void decompress_all_0vbb(stringvec allFilenames,
                               int n_events);

// === HIGH LEVEL TOOLS ================================================

void decompress_file_1e  (std::string filename,
                                  int n_events);

void decompress_file_0vbb(std::string filename,
                                  int n_events);

// === MID LEVEL TOOLS =================================================



// === LOW LEVEL TOOLS =================================================



// === ERROR RETURNS ===================================================

// ERRORS GO HERE

#endif // DECOMPRESSINPUT_H
