#include "Queen.h"

Queen::Queen(std::string color):Piece(color) {}


bool Queen::canMoveTo(Square& location) const {
    return false;
}


const int Queen::value() const {
    // TODO
    return 0;
}


void Queen::display(std::ostream& outStream) const {
    outStream << Piece::color() << "Q";
}
