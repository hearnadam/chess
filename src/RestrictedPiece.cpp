#include "RestrictedPiece.h"

RestrictedPiece::RestrictedPiece(std::string color):Piece(color), _moved(false){}


bool RestrictedPiece::moveTo(Player& byPlayer, Square& to) {
    bool moved = Piece::moveTo(byPlayer, to);
    if (!hasMoved()) {
        _moved = moved;
    }
    return moved;
}


const bool RestrictedPiece::hasMoved() const {
    return _moved;
}
