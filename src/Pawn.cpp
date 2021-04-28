#include "Pawn.h"

#include "Board.h"
#include "Square.h"
#include "Queen.h"

Pawn::Pawn(std::string color):RestrictedPiece(color), _delegate(nullptr) {}

Pawn::~Pawn() {
    // Delete delegate if it exists when pawn is deleted.
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

    // If move was successful, and delegate does not exist, then create delegate
    if (moved && !_delegate) {

        //  If Pawn reaches end of board, create delegate.
        // Since pawns cannot move backwards, color is irrelevant here.
        if (to.getY() == 0 || to.getY() == 7) {

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

    // if pawn has delegate, rely on delegate's canMoveTo function.
    if (_delegate) {
        canMove = _delegate->canMoveTo(location);

    // Limit pawn movement to be forwards based on color.
    } else {
        // Calculate distances based on the direction the pawns should move.
        if (color()[0] == 'W') {
            xDist = location.getX() - getLocation().getX();
            yDist = location.getY() - getLocation().getY();
        } else {
            xDist = getLocation().getX() - location.getX();
            yDist = getLocation().getY() - location.getY();
        }

        if (yDist == 1 || yDist == 2) {

            // If destination is occupied, limit movement to one diagonal space.
            if (location.occupied()) {

                // Limit movement to one diagonol space.
                // Movement can be left or right, hence the absolute value.
                if (std::abs(xDist) == 1 && yDist == 1) {
                    canMove = true;
                }

            // Verify path is vertical & clear of any pieces in the way.
            } else if (Board::getBoard().isClearVerticle(getLocation(), location)) {

                // regardless of pawn state, allow 1 space movement.
                if (yDist == 1) {
                    canMove = true;

                // if pawn has not moved, allow 2 space movement.
                } else if (!hasMoved() && (yDist == 2)) {
                    canMove = true;
                }
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
