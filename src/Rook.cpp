#include "Rook.h"

#include "Board.h"

Rook::Rook(std::string color):RestrictedPiece(color) {}


bool Rook::canMoveTo(Square& location) const {
    bool canMove = false;

    if (Board::getBoard().isClearVerticle(getLocation(), location)) {
        canMove = true;
    } else if (Board::getBoard().isClearHorizontal(getLocation(), location)) {
        canMove = true;
    }

    return canMove;
}


const int Rook::value() const {
    return 5;
}


void Rook::display(std::ostream& outStream) const {
    outStream << Piece::color()[0] << "R";
}
