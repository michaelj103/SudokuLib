//
//  SudokuBoard.cpp
//  SudokuSolver
//
//  Created by Michael Brandt on 4/25/20.
//  Copyright © 2020 Michael Brandt. All rights reserved.
//

#include "SudokuBoard.hpp"
#include <cassert>

SudokuBoard::SudokuBoard(std::initializer_list<int> list) {
    assert(list.size() <= SudokuBoard::BoardSize);
    size_t i = 0;
    for (int x : list) {
        _board[i++] = x;
    }
}

static size_t _indexOf(size_t col, size_t row) {
    assert(col < 9 && row < 9);
    return (row * 9) + col;
}

int SudokuBoard::at(size_t col, size_t row) const {
    size_t idx = _indexOf(col, row);
    return _board[idx];
}

void SudokuBoard::set(size_t col, size_t row, int val) {
    assert(val >= 0 && val <= 9);
    size_t idx = _indexOf(col, row);
    _board[idx] = val;
}
