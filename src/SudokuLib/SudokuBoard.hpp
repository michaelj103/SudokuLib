//
//  SudokuBoard.hpp
//  SudokuSolver
//
//  Created by Michael Brandt on 4/25/20.
//  Copyright © 2020 Michael Brandt. All rights reserved.
//

#ifndef SudokuBoard_hpp
#define SudokuBoard_hpp

#include <array>
#include <initializer_list>

class SudokuBoard {
public:
    SudokuBoard(std::initializer_list<int>);
    
    int at(size_t col, size_t row) const;
    void set(size_t col, size_t row, int val);
    
    static const size_t BoardSize = 81;
    
private:
    std::array<int, BoardSize> _board;
};

#endif /* SudokuBoard_hpp */
