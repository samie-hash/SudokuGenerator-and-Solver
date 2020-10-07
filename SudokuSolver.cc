/******************************************************************
 * Name: SudokuSolver.cc
 * Author: Samuel Oseh
 * Description: SudokuSolver class method-function definitions
 * Purpose: This class solves a sudoku puzzle for an 9 x 9 array
 * ****************************************************************/

#include <iostream>
#include "include/SudokuSolver.hh"

SudokuSolver::SudokuSolver ( const std::array< std::array< int, 9 >, 9 > &board  ) {
    this->board = board;
}

bool SudokuSolver::solve() {
    std::array< int , 2 > empty = getNextEmpty( board );
    if ( empty[ 0 ] == -1 && empty [ 1 ] == -1 ) {
        printBoard( board );
        return true;
    }

    for ( unsigned int guess = 1; guess < 10; ++guess ) {
        if ( choiceIsValid( board, empty[ 0 ], empty[ 1 ], guess ) ) {
            board[ empty[ 0 ] ][ empty[ 1 ] ] = guess ;

            if ( solve() )
                return true;
        }
        board[ empty[ 0 ] ][ empty[ 1 ] ] = 0;
    }
    return false;
}

std::array< int , 2 > SudokuSolver::getNextEmpty( std::array< std::array< int, 9 >, 9 > &board ) {
    for ( int row = 0; row < board.size(); ++row ) {
        for ( int col = 0; col < board.size(); ++col ) {
            if ( board[ row ][ col ] == 0 ) {
                std::array< int, 2 > empty { row, col };
                return empty;
            }
        }
    }
    std::array< int, 2 > empty { -1, -1 };
    return empty;
}

bool SudokuSolver::choiceIsValid( std::array< std::array< int, 9 >, 9 > &board, int row, int column, int guess ) {
    // row wise check
    bool result = isRowValid( board, row, column, guess );

    // columnwise check
    if ( result == true )
        result = isColValid( board, row, column, guess );

    // block check
    if ( result == true )
        result = isBlockValid( board, row, column, guess );

    return result;
} 
bool SudokuSolver::isRowValid( std::array< std::array< int, 9 >, 9 > &board, int row, int column, int guess ) {
    for ( unsigned int counter = 0; counter < board.size(); ++counter ) {
        if ( board[ counter ][ column ] == guess )
            return false;
    }
    return true;
}

bool SudokuSolver::isColValid( std::array< std::array< int, 9 >, 9 > &board, int row, int column, int guess ) {
    for ( unsigned int counter = 0; counter < board.size(); ++counter ) {
        if ( board[ row ][ counter ] == guess )
            return false;
    }
    return true;
}

bool SudokuSolver::isBlockValid( std::array< std::array< int, 9 >, 9 > &board,  int row, int column, int guess ) {
    int segmentX = 3 * ( row / 3 );
    int segmentY = 3 * ( column / 3 );

    for ( unsigned int i = segmentX; i < segmentX + 3; ++i ) {
        for ( unsigned int j = segmentY; j < segmentY + 3; ++j ) {
            if ( board[ i ][ j ] == guess )
                return false;
        }
    }
    return true;
}
void SudokuSolver::printBoard( std::array< std::array< int, 9 >, 9 > &board ) const {
     for ( unsigned int counter = 97; counter < 106; ++counter )
        std::cout << "       " << static_cast< char >( counter );
    std::cout << std::endl;
    for ( unsigned int row = 0; row < board.size(); ++row ) {
        std::cout << "  |-------|-------|-------|-------|-------|-------|-------|-------|-------|" << std::endl;
        std::cout << ( row + 1 ) << " ";
        for ( unsigned  int column = 0; column < board.size(); ++column ) {
            if ( board[ row ][ column ]  == 0 )
                std::cout << "|       ";  
            else
                std::cout << "|   " << board[ row ][ column ] << "   ";
        }
        std::cout << "|";
        std::cout << std::endl;
        std::cout << "  |       |       |       |       |       |       |       |       |       |" << std::endl;
    }
    std::cout << "  |-------|-------|-------|-------|-------|-------|-------|-------|-------|" << "\n\n";
}