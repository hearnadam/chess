#include "Rook.h"

#include "Board.h"

Rook::Rook(std::string color):RestrictedPiece(color) {}


bool Rook::canMoveTo(Square& location) const {

    // Rook can move in any line verticle or horizontal.
    // C++ lazy execution should only require the 2nd function to be called
    // if the first is false.
    return Board::getBoard().isClearVerticle(getLocation(), location)
            || Board::getBoard().isClearHorizontal(getLocation(), location);
}


const int Rook::value() const {
    return 5;
}


void Rook::display(std::ostream& outStream) const {

    // Display Rook color, then symbol.
    outStream << Piece::color()[0] << "R";
}
