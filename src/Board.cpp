#include "Board.h"
#include "Square.h"
#include "Piece.h"

// Constructor
Board::Board() {
    for (int i = 0; i < _DIMENSION; i++) {
        std::vector<Square*> v;
        for (int j = 0; j < _DIMENSION; j++) {
            v.push_back(new Square(j, i));
       }
       _squares.push_back(v);
    }
}


// Accessors
Square& Board::squareAt(int x, int y) const {
    return *_squares.at(y).at(x);
}


Square& Board::squareAt(std::string location) const {
    // TODO
    return *_squares.at(0).at(0);
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
            if (_squares[i][j] -> occupied()) {
                outStream << " ";
                Piece& occupant = _squares[i][j] -> occupiedBy();
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
    return _the_board;
}

Board Board::_the_board;
