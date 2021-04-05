#include "Bishop.h"

Bishop::Bishop(std::string color):Piece(color) {}

Bishop::~Bishop() {}

bool Bishop::canMoveTo(Square& location) const {
    return false;
}

const int Bishop::value() const {
    // TODO
    return 0;
}

void Bishop::display(std::ostream& outStream) const {
    outStream << Piece::color() << "B";
}