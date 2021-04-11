#include "Square.h"
#include "Piece.h"

Square::Square(int x, int y):_x(x), _y(y), _occupant(nullptr) {}

void Square::setOccupier(Piece* piece) {
    // TODO: CALL SETLOCATION
    _occupant = piece;
    if (_occupant != nullptr) {
        _occupant->setLocation(this);
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