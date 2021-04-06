#include "Bishop.h"

Bishop::Bishop(std::string color):Piece(color) {}


bool Bishop::canMoveTo(Square& location) const {
    // TODO
    return false;
}


const int Bishop::value() const {
    // TODO
    return 0;
}


void Bishop::display(std::ostream& outStream) const {
    outStream << Piece::color() << "B";
}