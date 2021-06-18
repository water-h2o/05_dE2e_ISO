# ISO scenario converter from deposited energy into ionization electrons

Uses the NEST charge yield to convert incident particle energy **E** and deposited energy **dE** into a number of produced drift electrons for each interaction along the 0νββ and 1e tracks.

## Requirements

C++17, Eigen 3, CERN ROOT

## Usage

1. Place into `./resources/input_tracksets` sets of 100 0νββ or 1e tracks produced by ANTS2 during simulation *(Two 0νββ tracksets are provided as an example)*.
2. In `main.cpp`, toggle the `is0vbb` variable, on Line 42.
3. Run `$ make` and `$ ./test`.




