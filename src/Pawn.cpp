#include "Pawn.h"

Pawn::Pawn(std::string color):RestrictedPiece(color) {}

Pawn::~Pawn() {}

void Pawn::setLocation(Square* square) {
    // TODO
    Piece::setLocation(square);
}

bool Pawn::canMoveTo(Square& location) const {
    return false;
}

const int Pawn::value() const {
    // TODO
    return 0;
}

void Pawn::display(std::ostream& outStream) const {
    outStream << Piece::color() << "P";
}