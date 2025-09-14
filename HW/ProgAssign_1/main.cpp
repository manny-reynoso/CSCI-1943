#include <fstream>   // ifstream for reading files
#include <sstream>   // istringstream for parsing a line
#include <iostream>  // cout/cerr
#include <cstdlib>   // std::exit (remove if you switch to bool/throw style)
#include "header.h"

using namespace std; 

// ----------------------------------------------------------
// head()
// Prints the required assignment info block at the top.
// ----------------------------------------------------------
void head() {
    cout << "Programmer: Manny Reynoso\n"
         << "Course Name: CSCI 1943\n"
         << "Program Name: PProg Assign 1\n"
         << "Group Number: E01\n"
         << "Instructor's Name : David Sylvester\n"
         << "Due Date and time: 09/16/25 23:59\n\n";
}

// ----------------------------------------------------------
// getdata_MR(...)
// Reads the text file line-by-line and fills scores[row][col].
//
// File format (one student per line):
//   Name: s1 s2 s3 s4 s5
// Example:
//   Emma: 75 80 100 90 82
//   Ben:  100 90 95 80 92
//
// We *ignore the name* and parse exactly 5 ints
// after the colon. Blank lines are skipped. Malformed lines are
// skipped to keep it simple. If we read fewer than nrows lines,
// we print an error and exit.
// ----------------------------------------------------------
void getdata_MR(const std::string& filename,
                int scores[][numTests],
                int nrows, int ncols)
{
    std::ifstream fin(filename);
    if (!fin) { std::cerr << "Can't open " << filename << "\n"; std::exit(1); }

    std::string line;
    int row = 0;

    // Read until we fill nrows or run out of lines
    while (row < nrows && std::getline(fin, line)) {
        // Skip lines that are purely whitespace
        if (line.find_first_not_of(" \t\r") == std::string::npos) continue;

        // Find the colon that separates the name from the scores
        std::size_t colon = line.find(':');
        if (colon == std::string::npos) continue; // no colon? skip this line (simple handling)

        // Parse exactly ncols integers after the colon
        std::istringstream iss(line.substr(colon + 1));

        for (int col = 0; col < ncols; ++col) {
            if (!(iss >> scores[row][col])) {
                std::cerr << "Not enough scores on line " << (row + 1) << "\n";
                std::exit(1);
            }
        }
        ++row; // move to next student/row
    }

    // If we didn’t get all rows, the file is short or had too many bad lines
    if (row < nrows) {
        std::cerr << "Expected " << nrows << " data lines, got " << row << "\n";
        std::exit(1);
    }
}

// ----------------------------------------------------------
// main()
// Declares the three required local arrays, calls getdata_MR,
// and prints a quick sanity check so the team can see the data
// actually loaded. Your teammates will later replace the sanity
// print with calcdata_MR + printdata_MR.
// ----------------------------------------------------------
int main() {
    head(); // 1) Required header output

    // 2) Required local arrays (names, scores, averages)
    std::string students_MR[numStudents] = {
        "Anna","Ben","Emma","Jack","Lily","Max","Nora","Sam","Kate","Leo"
    };

    // Zero-initialize the 2D scores array (10x5)
    int scores_MR[numStudents][numTests] = {};
    // Averages to be computed by teammates (int truncation)
    int averages_MR[numStudents] = {};

    // 3) Read the data file. Ensure "scores.txt" sits in the working directory.
    //    Each non-empty line should look like:   Name: n1 n2 n3 n4 n5
    getdata_MR("scores.txt", scores_MR, numStudents, numTests);

    // 4) TEMP sanity print: verify that scores loaded correctly.
    //    (Teammates will later remove this and call calc/print instead.)
    for (int i = 0; i < numStudents; ++i) {
        std::cout << students_MR[i] << ": ";
        for (int j = 0; j < numTests; ++j) {
            std::cout << scores_MR[i][j] << (j + 1 < numTests ? ' ' : '\n');
        }
    }

    // 5) NEXT STEPS for teammates (see checklist below):
    // calcdata_MR(scores_MR, averages_MR, numStudents, numTests);
    // printdata_MR(students_MR, scores_MR, averages_MR, numStudents, numTests);

    return 0;
}
