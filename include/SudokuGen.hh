#ifndef SUDOKUGEN_HH
#define SUDOKUGEN_HH
/******************************************************************
 * Name: SudokuGen.hh
 * Author: Samuel Oseh
 * Description: SudokuGen class method-function prototype
 * Purpose: This class generates a sudoku puzzle for an m x n array
 * ****************************************************************/

#include <vector>
#include <array>
#include "SudokuSolver.hh"

class SudokuGen : public SudokuSolver {
    public:
        SudokuGen();
        ~SudokuGen(){}
        bool generateBoard( const std::string &difficulty );
        std::array< std::array< int, 9 >, 9 > board{};
    private:
        std::vector< int > validChoices;

        // utility functions
        void setValidChoices();
        void shuffleChoices( std::vector< int > & );
        std::array< std::array< int, 9 >, 9 > setBoard( const std::string &difficulty );
};

#endif