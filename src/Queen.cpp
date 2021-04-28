#include "Queen.h"

#include "Board.h"

Queen::Queen(std::string color):Piece(color) {}


bool Queen::canMoveTo(Square& location) const {

    // Queen can move in any line, verticle, horizontal, or diagonal.
    // C++ lazy execution should only require the 2nd function to be called
    // if the first is false, and so on.
    return Board::getBoard().isClearVerticle(getLocation(), location)
            || Board::getBoard().isClearHorizontal(getLocation(), location)
            || Board::getBoard().isClearDiagonal(getLocation(), location);
}


const int Queen::value() const {
    return 9;
}


void Queen::display(std::ostream& outStream) const {

    // Display Queen color, then symbol.
    outStream << Piece::color()[0] << "Q";
}
