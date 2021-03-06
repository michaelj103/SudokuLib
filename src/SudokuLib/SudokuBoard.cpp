//
//  SudokuBoard.cpp
//  SudokuSolver
//
//  Created by Michael Brandt on 4/25/20.
//  Copyright © 2020 Michael Brandt. All rights reserved.
//

#include "SudokuBoard.hpp"
#include <cassert>

using namespace std;

SudokuBoard::SudokuBoard(std::initializer_list<int> list): _board(81, 0) {
    assert(list.size() <= SudokuBoard::BoardSize);
    size_t i = 0;
    for (int x : list) {
        assert(x >= 0 && x <= SudokuBoard::RowSize);
        _board[i++] = x;
    }
}

SudokuBoard::SudokuBoard(): _board(81, 0) {}

static size_t _indexOf(size_t col, size_t row) {
    assert(col < SudokuBoard::RowSize && row < SudokuBoard::RowSize);
    return (row * SudokuBoard::RowSize) + col;
}

int SudokuBoard::at(size_t col, size_t row) const {
    size_t idx = _indexOf(col, row);
    return _board[idx];
}

void SudokuBoard::set(size_t col, size_t row, int val) {
    assert(val >= 0 && val <= SudokuBoard::RowSize);
    size_t idx = _indexOf(col, row);
    _board[idx] = val;
}

std::vector<bool> SudokuBoard::possibleEntriesAt(size_t col, size_t row) const {
    const int current = this->at(col, row);
    if (current != 0) {
        vector<bool> valid(RowSize, false);
        valid[current-1] = true;
        return valid;
    }
    
    //Check row and col
    vector<bool> excluded(RowSize, false);
    for (size_t i = 0; i < RowSize; ++i) {
        //Exclude other values in the row
        int rowComp = at(col, i);
        if (rowComp > 0) {
            excluded[rowComp-1] = true;
        }
        
        //Exclude other values in the col
        int colComp = at(i, row);
        if (colComp > 0) {
            excluded[colComp-1] = true;
        }
    }
    
    //Check the subsquare
    const size_t baseCol = col - (col % SubSquareSize);
    const size_t baseRow = row - (row % SubSquareSize);
    for (size_t rOff = 0; rOff < SubSquareSize; ++rOff) {
        for (size_t cOff = 0; cOff < SubSquareSize; ++cOff) {
            int comp = at(baseCol + cOff, baseRow + rOff);
            if (comp > 0) {
                excluded[comp-1] = true;
            }
        }
    }
    
    //flip excluded
    for (auto it = excluded.begin(); it != excluded.end(); ++it) {
        *it = !(*it);
    }
    return excluded;
}

bool SudokuBoard::firstEmptySpace(size_t &col, size_t &row) const {
    size_t start = _indexOf(col, row);
    for (size_t i = start; i < _board.size(); ++i) {
        if (_board[i] == 0) {
            //found empty
            col = i % RowSize;
            row = i / RowSize;
            return true;
        }
    }
    
    return false;
}

std::ostream &operator<<(std::ostream &os, const SudokuBoard &board) {
    for (size_t row = 0; row < SudokuBoard::RowSize; ++row) {
        for (size_t col = 0; col < SudokuBoard::RowSize; ++col) {
            os << board.at(col, row);
        }
        os << "\n";
    }
    
    return os;
}

