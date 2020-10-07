#ifndef SUDOKUSOLVER_HH
#define SUDOKUSOLVER_HH
/******************************************************************
 * Name: SudokuGen.hh
 * Author: Samuel Oseh
 * Description: SudokuGen class method-function prototype
 * Purpose: This class generates a sudoku puzzle for an 9 x 9 array
 * ****************************************************************/

#include <array>

class SudokuSolver {
    public:
        SudokuSolver(){}
        SudokuSolver( const std::array< std::array< int, 9 >, 9 > &board );
        ~SudokuSolver(){}
        bool solve();
        void printBoard( std::array< std::array< int, 9 >, 9 > &board ) const;
    protected:
        std::array< std::array< int, 9 >, 9 > board;
        bool isRowValid( std::array< std::array< int, 9 >, 9 > &board, int, int, int );
        bool isColValid( std::array< std::array< int, 9 >, 9 > &board, int, int, int );
        bool isBlockValid( std::array< std::array< int, 9 >, 9 > &board, int, int, int );
        bool choiceIsValid( std::array< std::array< int, 9 >, 9 > &board, int, int, int );
        std::array< int , 2 > getNextEmpty( std::array< std::array< int, 9 >, 9 > &board );
};

#endif