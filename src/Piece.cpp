#include "Piece.h"

#include "Square.h"
#include "Player.h"

Piece::Piece(std::string color):_color(color), _square(nullptr){}


void Piece::setLocation(Square* square) {
    _square = square;
}


bool Piece::moveTo(Player& byPlayer, Square& to) {
    bool moved = true;

    // Check geometry & move validity.
    if (canMoveTo(to)) {

        // Check if destination is occupied.
        if (to.occupied()) {
            if (color()[0] != to.occupiedBy().color()[0]) {

                // TODO: move this to after move is made.
                // Capture piece on destination.
                byPlayer.capture(to.occupiedBy());

            } else {
                // Cannot capture your own pieces
                moved = false;
            }
        }

        // If captured or no piece was occupying space
        if (moved) {
            // Get 'source' for move and remove its occupant. 
            getLocation().setOccupier(nullptr);

            // Set destination to contain this piece & set this piece's location.
            to.setOccupier(this);

            // TODO: CHECK FOR CHECK
        }
    } else {
        moved = false;
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
