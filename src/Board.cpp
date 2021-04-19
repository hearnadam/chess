#include <string>
#include <iostream>

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


// Square Accessors
Square& Board::squareAt(int x, int y) const {
    return *_squares.at(y).at(x);
}


Square& Board::squareAt(std::string location) const {
    // translate chars into ints using the nature of char.
    return squareAt(location[0] - 'a', location[1] - '1');
}


// Geometry & clear path checkers.
bool Board::isClearVerticle(Square& from, Square& to) const {
    // Ensures path is vertical.
    bool isClear = from.getX() == to.getX();

    // Sets bounds for the loop.
    int lowerY = std::min(from.getY(), to.getY());
    int upperY = std::max(from.getY(), to.getY());


    // Ensure path is clear.
    for (int y = lowerY + 1; y < upperY && isClear; y++) {
        // If a square is occupied path is NOT clear.  
        if (squareAt(from.getX(), y).occupied()) {
            isClear = false;
        }
    }

    return isClear;
}


bool Board::isClearHorizontal(Square& from, Square& to) const {
    // Ensures path is horizontal.
    bool isClear = from.getY() == to.getY();

    // Sets bounds for the loop.
    int leftX = std::min(from.getX(), to.getX());
    int rightX = std::max(from.getX(), to.getX());

    // Ensure path is clear
    for (int x = leftX + 1; x < rightX && isClear; x++) {
        // If a square is occupied path is NOT clear.  
        if (squareAt(x, from.getY()).occupied()) {
            isClear = false;
        }
    }

    return isClear;
}


bool Board::isClearDiagonal(Square& from, Square& to) const {
    int lowerY = std::min(from.getY(), to.getY());
    int upperY = std::max(from.getY(), to.getY());
    int leftX = std::min(from.getX(), to.getX());
    int rightX = std::max(from.getX(), to.getX());
    bool isClear = ((upperY - lowerY) == (rightX - leftX));

    // TODO: Fix this formatting
    // Ensure path is clear
    {
    int y = lowerY + 1;
    for (int x = leftX + 1; (x < rightX && y < upperY) && isClear;x++) {
        // If a square is occupied path is NOT clear.  
        if (squareAt(x, y).occupied()) {
            isClear = false;
        }
        y++;
    }
    }

    // for (std::pair<int, int> indices(leftX + 1, lowerY + 1); indices.first < rightX && isClear; indices.first++ ) {

    // }
    return isClear;
}


// Display board
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


// Board accessor
Board& Board::getBoard() {
    return _the_board;
}


Board Board::_the_board;
