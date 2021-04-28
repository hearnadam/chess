#include "King.h"

#include "Square.h"

King::King(std::string color):RestrictedPiece(color) {}


bool King::canMoveTo(Square& location) const {
    int xDist = std::abs(getLocation().getX() - location.getX());
    int yDist = std::abs(getLocation().getY() - location.getY());

    // Validate that X distance is one to the left, right, or zero.
    // Validate that Y distance is one forwards, backwards, or zero.
    // Validate that king moves in at least one direction.
    return xDist <= 1 && yDist <= 1 && (xDist + yDist != 0);
}


const int King::value() const {
    // King should never be able to be captured. Score is irrelevant.
    return 69;
}


void King::display(std::ostream& outStream) const {
    outStream << Piece::color()[0] << "K";
}
