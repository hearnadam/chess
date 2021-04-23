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

    // Not that .at when used on a vector has bound protections.
    // This should throw 'out_of_range' exception if x or y is out of bounds.
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


    // Always start on bottom of the board and go towards the top.
    // Loop until 'to' is reached, or path is not clear.
    for (int y = lowerY + 1; y < upperY && isClear; y++) {

        // check if the square the loop is on is occupied, if so
        // path is not clear and loop is exited
        if (squareAt(from.getX(), y).occupied()) {
            isClear = false;
        }
    }

    return isClear;
}


bool Board::isClearHorizontal(Square& from, Square& to) const {
    // Ensures path is horizontal by from & to are in the same row.
    bool isClear = from.getY() == to.getY();

    // Sets bounds for the loop.
    int leftX = std::min(from.getX(), to.getX());
    int rightX = std::max(from.getX(), to.getX());

    // Always start on left side of the board and go towards the right.
    // Loop until 'to' is reached, or path is not clear.
    for (int x = leftX + 1; (x < rightX && isClear); x++) {
        
        // check if the square the loop is on is occupied, if so
        // path is not clear and loop is exited
        if (squareAt(x, from.getY()).occupied()) {
            isClear = false;
        }
    }

    return isClear;
}


bool Board::isClearDiagonal(Square& from, Square& to) const {
    // These temp values are an annoyance, but they make life very easy
    // They allow for checking all directions of diagonols geometry in one line.
    int lowerY = std::min(from.getY(), to.getY());
    int upperY = std::max(from.getY(), to.getY());
    int leftX = std::min(from.getX(), to.getX());
    int rightX = std::max(from.getX(), to.getX());

    // Check geometry
    bool isClear = ((upperY - lowerY) == (rightX - leftX));

    // The following block is CLEVER code. Be careful if you choose to make changes
    // Brackets scope x to be only valid in the loop.
    {
    // Start with the X that the piece begins at.
    int x = from.getX();

    // Start with the lower Y ALWAYS, this allows all checks to happen from
    // top to bottom. If you cahnge this, you must incriment in an if statemnt.
    // Loop conditions avoids x since they are incrimented syncronously.
    for (int y = lowerY + 1; (y < upperY && isClear);y++) {

        // Incrimenting occurs before the rest of the code to prevent having
        // to duplicate this code block outside of the loop. This initial
        // incrementing/decrementing avoids checking the starting square.
        // If diagonal goes from left to right, incriment the X
        if (from.getX() < to.getX()) {
            x++;

        // If diagonal goes from right to left, decrement the X
        } else {
            x--;
        }

        // Finally, check if the square the loop is on is occupied, if so
        // path is not clear and loop is exited
        if (squareAt(x, y).occupied()) {
            isClear = false;
        }

    }
    }

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
