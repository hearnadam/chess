#include "Board.h"
#include "Square.h"
#include "Piece.h"

// Constructor
Board::Board() {
   for (int i = 0; i < _DIMENSION; i++) {
       for (int j = 0; j < _DIMENSION; j++) {
           _board[i][j] = new Square(j, i);
       }
   }
}


// Accessors
Square& Board::squareAt(int x, int y) const {
    return *_board[y][x];
}


Square& Board::squareAt(std::string location) const {
    // TODO
    return *_board[0][0];
}


bool Board::isClearVerticle(Square& from, Square& to) const {
    // TODO
    return true;
}


bool Board::isClearHorizontal(Square& from, Square& to) const {
    // TODO
    return true;
}


bool Board::isClearDiagonal(Square& from, Square& to) const {
    // TODO
    return true;
}


void Board::display(std::ostream& outStream) const {
   // Iterate over the squares and display them
    outStream << "    a    b    c    d    e    f    g    h" << std::endl;
    for (int i = _DIMENSION - 1; i >= 0; i--) {
        outStream << "  -----------------------------------------" << std::endl;
        outStream << _DIMENSION - i << " |";
        for (int j = 0; j < _DIMENSION; j++) {
            if (_board[i][j] -> occupied()) {
                outStream << " ";
                Piece& occupant = _board[i][j] -> occupiedBy();
                occupant.display(outStream);
                outStream << " ";
            } else {
                outStream << "    ";
            }
            outStream << "|";
        }
        
        outStream << " " << _DIMENSION - i << std::endl;
   }
    outStream << "  -----------------------------------------" << std::endl;
    outStream << "    a    b    c    d    e    f    g    h" << std::endl;
}


Board& Board::getBoard() {
   // Return the board
    return _the_board;
}

Board Board::_the_board;
