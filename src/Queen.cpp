#include "Queen.h"

#include "Board.h"

Queen::Queen(std::string color):Piece(color) {}


bool Queen::canMoveTo(Square& location) const {
    bool canMove = false;

    if (Board::getBoard().isClearVerticle(getLocation(), location)) {
        canMove = true;
    } else if (Board::getBoard().isClearVerticle(getLocation(), location)) {
        canMove = true;
    } else if (Board::getBoard().isClearDiagonal(getLocation(), location)) {
        canMove = true;
    }

    return canMove;
}


const int Queen::value() const {
    return 9;
}


void Queen::display(std::ostream& outStream) const {
    outStream << Piece::color()[0] << "Q";
}
