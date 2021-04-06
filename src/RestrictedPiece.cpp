#include "RestrictedPiece.h"

RestrictedPiece::RestrictedPiece(std::string color):Piece(color), _moved(false){}


bool RestrictedPiece::moveTo(Player& byPlayer, Square& to) {
    // TODO
    return false;
}


const bool RestrictedPiece::hasMoved() const {
    return _moved;
}
