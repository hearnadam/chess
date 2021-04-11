#include "King.h"

King::King(std::string color):RestrictedPiece(color) {}


bool King::canMoveTo(Square& location) const {
    // TODO
    return false;
}


const int King::value() const {
    // TODO
    return 0;
}


void King::display(std::ostream& outStream) const {
    outStream << Piece::color()[0] << "K";
}
