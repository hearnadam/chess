#include "Bishop.h"

#include "Board.h"

Bishop::Bishop(std::string color):Piece(color) {}


bool Bishop::canMoveTo(Square& location) const {
    return Board::getBoard().isClearDiagonal(getLocation(), location);
}


const int Bishop::value() const {
    return 3;
}


void Bishop::display(std::ostream& outStream) const {
    outStream << Piece::color()[0] << "B";
}