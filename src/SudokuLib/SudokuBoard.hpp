//
//  SudokuBoard.hpp
//  SudokuSolver
//
//  Created by Michael Brandt on 4/25/20.
//  Copyright © 2020 Michael Brandt. All rights reserved.
//

#ifndef SudokuBoard_hpp
#define SudokuBoard_hpp

#include <vector>
#include <initializer_list>
#include <iostream>

class SudokuBoard {
public:
    SudokuBoard(std::initializer_list<int>);
    SudokuBoard();
    
    // get or set a position. 0 means empty
    int at(size_t col, size_t row) const;
    void set(size_t col, size_t row, int val);
    
    static const size_t SubSquareSize = 3;
    static const size_t RowSize = SubSquareSize * SubSquareSize;
    static const size_t BoardSize = RowSize * RowSize;
    
    /// n is valid at the given position if array[n-1] == true. If the given position is filled, that is the only valid entry
    std::vector<bool> possibleEntriesAt(size_t col, size_t row) const;
    bool firstEmptySpace(size_t &col, size_t &row) const;
    
private:
    std::vector<int> _board;
};

std::ostream &operator<<(std::ostream &os, const SudokuBoard &board);

#endif /* SudokuBoard_hpp */
