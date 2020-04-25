//
//  SudokuSolver.hpp
//  SudokuSolver
//
//  Created by Michael Brandt on 4/25/20.
//  Copyright © 2020 Michael Brandt. All rights reserved.
//

#ifndef SudokuSolver_hpp
#define SudokuSolver_hpp

#include <vector>
#include "SudokuBoard.hpp"

class SudokuSolver {
public:
    SudokuSolver(const SudokuBoard &board);
    SudokuSolver() = delete;
    
    bool solve(size_t maxAllowedSolutions = 10);
    size_t solutionCount() const;
    const std::vector<const SudokuBoard> &allSolutions() const;
    
private:
    bool _solved;
    SudokuBoard _backingBoard;
    std::vector<const SudokuBoard> _solutions;
};

#endif /* SudokuSolver_hpp */
