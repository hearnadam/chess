#include "Pawn.h"

#include "Board.h"
#include "Square.h"
#include "Queen.h"

Pawn::Pawn(std::string color):RestrictedPiece(color), _delegate(nullptr) {}

Pawn::~Pawn() {
    // Delete delegate if it exists.
    if (_delegate) {
        delete _delegate;
    }
}


void Pawn::setLocation(Square* square) {
    // Set (this) pawn location.
    Piece::setLocation(square);

    // Set delegate's location if it exists.
    if (_delegate) {
        _delegate->setLocation(square);
    }
}


bool Pawn::moveTo(Player& byPlayer, Square& to) {
    bool moved = RestrictedPiece::moveTo(byPlayer, to);
    if (moved) {
        //  If Pawn reaches color dependant end of board, create delegate.
        if ((color()[0] == 'W' && to.getY() == 7)
            || (color()[0] == 'B' && to.getY() == 0)) {

                // Create new Queen of this color and set delegate to it.
                _delegate = new Queen(color());

                // Set delegate's location to be the same as this pawn.
                _delegate->setLocation(&getLocation());
        }
    }
    return moved;
}



bool Pawn::canMoveTo(Square& location) const {
    int xDist;
    int yDist;

    // Set default return value to be false.
    bool canMove = false;

    // Calculate distances
    if (color()[0] == 'W') {
        xDist = location.getX() - getLocation().getX();
        yDist = location.getY() - getLocation().getY();
    } else {
        xDist = getLocation().getX() - location.getX();
        yDist = getLocation().getY() - location.getY();
    }


    // if pawn has delegate, rely on delegate's canMoveTo function.
    if (_delegate) {
        canMove = _delegate->canMoveTo(location);

    // Limit pawn movement to be forwards based on color.
    } else if (yDist == 1 || yDist == 2) {

        // If occupied, limit movement to one diagonal space.
        if (location.occupied()) {

            // Limit movement to one diagonol space
            if ((xDist == -1 || xDist == 1) && yDist == 1) {
                canMove = true;
            }

        // Verify path is vertical & clear.
        } else if (Board::getBoard().isClearVerticle(getLocation(), location)) {

            // regardless of position allow 1 space movement.
            if (yDist == 1) {
                canMove = true;

            // if pawn has not moved, allow 2 space movement.
            } else if (!hasMoved() && (yDist == 2)) {
                canMove = true;
            }
        }
    }

    return canMove;
}


const int Pawn::value() const {
    return 1;
}


void Pawn::display(std::ostream& outStream) const {
    // if pawn has delegate, rely on delegate's display function.
    if (_delegate) {
        _delegate->display(outStream);

    // else print pawn color and symbol.
    } else {
        outStream << Piece::color()[0] << "P";
    }
}
