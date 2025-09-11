#ifndef HEADER_H
#define HEADER_H

#include <string>


constexpr int numStudents = 10;
constexpr int numTests = 5;
// Function prototypes

void head(); // Print professor, student, and assignment info

void getdata_MR (); //Gets data from text file, stores to scores_MR

void calcdata_MR (); // Averages data from scores_Mr, stores  to averages_MR

void printdata_MR(); // Prints numStudents, scores_Mr and averages_MR into a table
#endif