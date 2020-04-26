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

const std::vector<SudokuBoard> &SudokuSolver::allSolutions() const {
    return _solutions;
}

static bool _solveHelper(SudokuBoard &boardState, vector<SudokuBoard> &solutions, size_t currentCol, size_t currentRow, size_t maxAllowedSolutions) {
    //find the first empty square
    size_t x = currentCol;
    size_t y = currentRow;
    if (!boardState.firstEmptySpace(x, y)) {
        //No empty spaces left, current state is a solution
        solutions.emplace_back(boardState);
        return true;
    }
    
    bool foundAnySolutions = false;
    vector<bool> available = boardState.possibleEntriesAt(x, y);
    for (int i = 0; i < SudokuBoard::RowSize; ++i) {
        if (available[i]) {
            boardState.set(x, y, i+1);
            bool solutionHere = _solveHelper(boardState, solutions, x, y, maxAllowedSolutions);
            boardState.set(x, y, 0);
            
            if (solutionHere) {
                foundAnySolutions = true;
                if (solutions.size() >= maxAllowedSolutions) {
                    break;
                }
            }
        }
    }
    
    return foundAnySolutions;
}

bool SudokuSolver::solve(size_t maxAllowedSolutions) {
    assert(maxAllowedSolutions > 0);
    _solutions.clear(); //clear in case of multiple calls
    _solveHelper(_backingBoard, _solutions, 0, 0, maxAllowedSolutions);
    _solved = true;
    return _solutions.size() > 0;
}
