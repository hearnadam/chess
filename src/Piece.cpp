#include "Piece.h"

#include "Square.h"
#include "Player.h"

Piece::Piece(std::string color):_color(color), _square(nullptr){}


void Piece::setLocation(Square* square) {
    _square = square;
}


bool Piece::moveTo(Player& byPlayer, Square& to) {
    // TODO: Fix this
    bool moved = false;

    if (this -> canMoveTo(to)) {
        // TODO: Check for check


        if (to.occupied()) {
            // TODO: Check if this needs to be implimented
            Piece& toCapture = to.occupiedBy();
            byPlayer.capture(toCapture);
        }
        Square& oldSquare = this -> getLocation();

        oldSquare.setOccupier(nullptr);
        this -> setLocation(&to);
        to.setOccupier(this);

        moved = true;
    }

    return moved;
}


const std::string Piece::color() const {
    return _color;
}


const bool Piece::isOnBoard() const {
    return _square != nullptr;
}


Square& Piece::getLocation() const {
    return *_square;
}
