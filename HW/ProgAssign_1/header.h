#ifndef HEADER_H
#define HEADER_H

#include <string>

// Compile-time sizes used for arrays and function params
const int numStudents = 10;
const int numTests    = 5;

// Prints the assignment header block
void head();

// Reads the data file and fills the 2D scores array
// Expected line format:  Name: s1 s2 s3 s4 s5
void getdata_MR(const std::string& filename,
                int scores[][numTests],
                int nrows, int ncols);

// (Teammates will add these to the header later)
// void calcdata_MR(const int scores[][numTests], int averages[], int nrows, int ncols);
// void printdata_MR(const std::string students[], const int scores[][numTests],
//                   const int averages[], int nrows, int ncols);

#endif // HEADER_H
