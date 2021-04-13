#include "Piece.h"

#include "Square.h"
#include "Player.h"

Piece::Piece(std::string color):_color(color), _square(nullptr){}


void Piece::setLocation(Square* square) {
    _square = square;
}


bool Piece::moveTo(Player& byPlayer, Square& to) {
    bool moved = false;

    // Check geometry & move validity.
    if (this -> canMoveTo(to)) {

        // Check if destination is occupied.
        if (to.occupied()) {

            // Capture piece on destination.
            byPlayer.capture(to.occupiedBy());
        }

        // Get 'source' for move and remove its occupant. 
        this -> getLocation().setOccupier(nullptr);

        // Set destination to contain this piece & set this piece's location.
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
