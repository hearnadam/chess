#include "Piece.h"

Piece::Piece(std::string color):_color(color), _square(nullptr){}


void Piece::setLocation(Square* square) {
    _square = square;
}


bool Piece::moveTo(Player& byPlayer, Square& to) {
    // TODO
    return false;
}


const std::string Piece::color() const {
    return _color;
}


const bool Piece::isOnBoard() const {
    return _square != nullptr;
}


const Square& Piece::getLocation() const {
    return *_square;
}
