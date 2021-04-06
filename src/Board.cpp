#include "Board.h"
#include "Square.h"
#include "Piece.h"

// Constructor
Board::Board() {
    for (int i = 0; i < _DIMENSION; i++) {
        std::vector<Square*> column;
        for (int j = 0; j < _DIMENSION; j++) {
            column.push_back(new Square(j, i));
       }
       _squares.push_back(column);
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
    // Output top letters
    outStream << "    a    b    c    d    e    f    g    h" << std::endl;
    for (int column = _DIMENSION - 1; column >= 0; column--) {
        outStream << "  -----------------------------------------" << std::endl;
        // Output left border of row
        outStream << column + 1 << " |";

        // Output Piece in square, or Output empty cell.
        for (int row = 0; row < _DIMENSION; row++) {

            // Output contents of square.
            if (squareAt(row, column).occupied()) {
                outStream << " ";
                Piece& occupant = squareAt(row, column).occupiedBy();
                occupant.display(outStream);
                outStream << " ";

            // Output empty square contents.
            } else {
                outStream << "    ";
            }

            // Output right border of square (& row).
            outStream << "|";
        }

        // Output number and new line.
        outStream << " " << column + 1 << std::endl;
   }

   // Output bottom of board.
    outStream << "  -----------------------------------------" << std::endl;
    outStream << "    a    b    c    d    e    f    g    h" << std::endl;
}


Board& Board::getBoard() {
    return _the_board;
}


Board Board::_the_board;
