#include <iostream>
#include "include/SudokuGen.hh"
#include "include/SudokuSolver.hh"

int main() {
    SudokuGen s;
    s.generateBoard( "Legend" );
    s.printBoard( s.board );
    std::cout << "\n\nSOLVED===========================================\n\n";
    SudokuSolver so( s.board );
    so.solve();
}