#ifndef MYTYPEDEFS_H
#define MYTYPEDEFS_H

#include <utility> // std::pair, std::make_pair
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <functional>
#include <memory>



// == TYPEDEFS =========================================================



typedef std::vector<std::string> stringvec; // used only in getFilesInDir.h

typedef std::vector<std::string>        a_column;
typedef std::map<std::string, a_column> a_cell;
typedef std::vector<std::string>        sentence; // vector of short strings
typedef std::vector<double>             a_signal;
typedef std::vector<double>             axis;
typedef std::vector<double>             dataset;


typedef double nanosec; // units of time (nanoseconds)
typedef double amp_arb; // units of amplitude (arbitrary amplitude unit)
typedef double ampNsec; // units of area (amp_arb x nanosec)
typedef int    idx;     // for indices

#endif // MYTYPEDEFS_H
