#include "Bishop.h"

#include "Board.h"

Bishop::Bishop(std::string color):Piece(color) {}


bool Bishop::canMoveTo(Square& location) const {

    // Bishop can move in any diagonal line.
    return Board::getBoard().isClearDiagonal(getLocation(), location);
}


const int Bishop::value() const {
    return 3;
}


void Bishop::display(std::ostream& outStream) const {

    // Display Bishop color, then symbol.
    outStream << Piece::color()[0] << "B";
}