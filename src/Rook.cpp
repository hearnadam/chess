#include "Rook.h"

Rook::Rook(std::string color):RestrictedPiece(color) {}

Rook::~Rook() {}

bool Rook::canMoveTo(Square& location) const {
    return false;
}

const int Rook::value() const {
    // TODO
    return 0;
}

void Rook::display(std::ostream& outStream) const {
    outStream << Piece::color() << "R";
}