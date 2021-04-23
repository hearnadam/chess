#include "King.h"

#include "Square.h"

King::King(std::string color):RestrictedPiece(color) {}


bool King::canMoveTo(Square& location) const {
    // Validate that X distance is one to the left, right, or zero.
    // Validate that Y distance is one forwards, backwards, or zero.
    return std::abs(getLocation().getX() - location.getX()) <= 1
            && std::abs(getLocation().getY() - location.getY()) <= 1;
}


const int King::value() const {
    // King should never be able to be captured. Score is irrelevant.
    return -1;
}


void King::display(std::ostream& outStream) const {
    outStream << Piece::color()[0] << "K";
}
