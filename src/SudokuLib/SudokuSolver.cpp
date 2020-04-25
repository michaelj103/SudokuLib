//
//  SudokuSolver.cpp
//  SudokuSolver
//
//  Created by Michael Brandt on 4/25/20.
//  Copyright © 2020 Michael Brandt. All rights reserved.
//

#include "SudokuSolver.hpp"
#include <cassert>

using namespace std;

SudokuSolver::SudokuSolver(const SudokuBoard &board) : _backingBoard(board) {}

size_t SudokuSolver::solutionCount() const {
    assert(_solved);
    return _solutions.size();
}

const std::vector<const SudokuBoard> &SudokuSolver::allSolutions() const {
    return _solutions;
}

void _solveHelper(SudokuBoard &boardState, vector<const SudokuBoard> &solutions, size_t maxAllowedSolutions) {
    
}

bool SudokuSolver::solve(size_t maxAllowedSolutions) {
    assert(maxAllowedSolutions > 0);
    _solutions.clear(); //clear in case of multiple calls
    _solveHelper(_backingBoard, _solutions, maxAllowedSolutions);
    _solved = true;
    return _solutions.size() > 0;
}
