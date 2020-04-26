//
//  main.cpp
//  SudokuSolver
//
//  Created by Michael Brandt on 4/25/20.
//  Copyright © 2020 Michael Brandt. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

#include "SudokuSolver.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    SudokuBoard board;
    size_t row = 0;
    
    string line;
    while (row < SudokuBoard::RowSize && getline(cin, line)) {
        istringstream iss(line);
        size_t col = 0;
        char x;
        while (col < SudokuBoard::RowSize && iss >> x) {
            if (x > '0' && x <= '9') {
                int val = x - '0';
                assert(val > 0 && val <= 9);
                board.set(col, row, val);
            }
            
            col++;
        }
        row++;
    }
    
    SudokuSolver solver(board);
    if (solver.solve()) {
        size_t solutionCount = solver.solutionCount();
        cout << "Found " << solutionCount << " solution" << (solutionCount == 1 ? "" : "s") << endl;
        const vector<SudokuBoard> solutions = solver.allSolutions();
        for (const SudokuBoard &board : solutions) {
            cout << board << endl;
        }
    } else {
        cout << "No solutions" << endl;
    }
    
    return 0;
}
