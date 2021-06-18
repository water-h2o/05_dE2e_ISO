#ifndef DE2ELEC_H
#define DE2ELEC_H

#include <vector>
#include <string>

#include "myTypedefs.h"

// === MAIN FUNCTIONS ==================================================

void dE2elec_all_files(stringvec allFilenames);

// === HIGH LEVEL TOOLS ================================================

void openLookupTable(std::string lookupTable_filename,
                           axis& energy_lookup,  // output
                        dataset& eYield_lookup); // output

void dE2elec_curr_file(std::string filename_in,
                       std::string filename_out,
                             axis& energy_lookup,  // input
                          dataset& eYield_lookup); // input

// === MID LEVEL TOOLS =================================================

int dE2elec_curr_E_dE(double curr_E,
                      double curr_dE,
                       axis& energy_lookup,  // input
                    dataset& eYield_lookup); // input

// === LOW LEVEL TOOLS =================================================



// === ERROR RETURNS ===================================================

// ERRORS GO HERE

#endif // DE2ELEC_H
