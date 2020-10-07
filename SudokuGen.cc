/******************************************************************
 * Name: SudokuGen.cc
 * Author: Samuel Oseh
 * Description: SudokuGen class method-function definitions
 * Purpose: This class generates a sudoku puzzle for an m x n array
 * ****************************************************************/

#include <iostream>
#include <random>
#include "include/SudokuGen.hh"

SudokuGen::SudokuGen() {
    setValidChoices();
    shuffleChoices( validChoices );
}

void SudokuGen::setValidChoices() {
    for ( unsigned int counter = 1; counter <= 9; ++counter ) {
        validChoices.push_back( counter );
    }
}

void SudokuGen::shuffleChoices( std::vector< int > &choices ) {
    std::default_random_engine engine ( static_cast< unsigned int > ( time(0) ) );
    std::uniform_int_distribution< unsigned int > randomInt( 0, choices.size() - 1 );

    for ( size_t i = 0; i < choices.size(); ++i ) {
        int swapIndex = randomInt( engine );
        for ( ; swapIndex == i; ) {
            swapIndex = randomInt( engine );
        }
        // swap
        int temp = choices[ i ];
        choices[ i ] = choices[ swapIndex ];
        choices[ swapIndex ] = temp;
    }
}

bool SudokuGen::generateBoard( const std::string &difficulty ) {
    std::array< int , 2 > empty = getNextEmpty( board );
    if ( empty[ 0 ] == -1 && empty [ 1 ] == -1 ) {
        setBoard( difficulty );
        return true;
    }

    for ( unsigned int counter = 0; counter < validChoices.size(); ++counter ) {
        if ( choiceIsValid( this->board, empty[ 0 ], empty[ 1 ], validChoices[ counter ] ) ) {
            board[ empty[ 0 ] ][ empty[ 1 ] ] = validChoices[ counter ];

            if ( generateBoard( difficulty ) )
                return true;
        }
        board[ empty[ 0 ] ][ empty[ 1 ] ] = 0;
    }
    return false;
}

std::array< std::array< int, 9 >, 9 > SudokuGen::setBoard( const std::string &difficulty ) {
    std::default_random_engine engine ( static_cast< unsigned int > ( time(0) ) );
    std::uniform_int_distribution< unsigned int > randomInt( 0, 8 );
    int row = 0, col = 0;
    int counter = 0;
    int limit = 0;
    if ( difficulty == "Easy" ) 
        limit = 25;
    else if ( difficulty == "Medium" )
        limit = 35;
    else if ( difficulty == "Hard" )
        limit = 45;
    else if ( difficulty == "Legend" )
        limit = 55;
    else {
        throw std::invalid_argument( "Invalid argument" );
    }
    while( counter < limit ) {
        row = randomInt( engine );
        col = randomInt( engine );
        if ( board[ row ][ col ] != 0 ) {
            board[ row ][ col ] = 0;
            ++counter;
        }
    }
    return board;
}