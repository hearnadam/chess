#include "Square.h"

#include "Piece.h"

Square::Square(int x, int y):_x(x), _y(y), _occupant(nullptr) {}

void Square::setOccupier(Piece* piece) {
    _occupant = piece;

    // Sets piece's location to be this if the Piece pointer is not null.
    if (piece != nullptr) {
        piece->setLocation(this);
    }
}

const int Square::getX() const {
    return _x;
}

const int Square::getY() const {
    return _y;
}

const bool Square::occupied() const {
    return _occupant != nullptr;
}

Piece& Square::occupiedBy() const {
    return *_occupant;
}