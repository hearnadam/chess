#include "Pawn.h"

#include "Board.h"
#include "Square.h"
#include "Queen.h"

Pawn::Pawn(std::string color):RestrictedPiece(color), _delegate(nullptr) {}

Pawn::~Pawn() {
    // Delete delegate if it exists.
    if (_delegate != nullptr) {
        delete _delegate;
    }
}


void Pawn::setLocation(Square* square) {
    // Set (this) pawn location.
    Piece::setLocation(square);

    // Set delegate's location if it exists.
    if (_delegate != nullptr) {
        _delegate -> setLocation(square);
    }
}


bool Pawn::moveTo(Player& byPlayer, Square& to) {
    bool moved = RestrictedPiece::moveTo(byPlayer, to);
    if (moved) {
        //  If Pawn reaches color dependant end of board, create delegate.
        if ((this -> color()[0] == 'W' && to.getY() == 7)
            || (this -> color()[0] == 'B' && to.getY() == 0)) {

                // Auto set delegate to be queen of this color.
                _delegate = new Queen(this -> color());
        }
    }
    return moved;
}



bool Pawn::canMoveTo(Square& location) const {
    Square& thisLocation = this -> getLocation();

    // Set default return value to be false.
    bool canMoveTo = false;

    // Calculate distances
    int xDist = location.getX() - this -> getLocation().getX();
    int yDist = location.getY() - this -> getLocation().getY();


    // if pawn has delegate, rely on delegate's canMoveTo function.
    if (_delegate != nullptr) {
        canMoveTo = _delegate -> canMoveTo(location);

    // Limit pawn movement to be forwards based on color.
    } else if ((color()[0] == 'W' && (yDist == 1 || yDist == 2))
                || (color()[0] == 'B' && (yDist == -1 || yDist == -2))) {

        // If occupied, limit movement to one diagonal space.
        if (location.occupied()) {

            // Limit movement to one diagonol space
            if ((xDist == -1 || xDist == 1) && (yDist == -1 || yDist == 1)) {
                canMoveTo = true;
            }

        // Verify path is vertical & clear.
        } else if (Board::getBoard().isClearVerticle(thisLocation, location)) {

            // regardless of position allow 1 space movement.
            if (yDist == 1 || yDist == -1) {
                canMoveTo = true;

            // if pawn has not moved, allow 2 space movement.
            } else if (!hasMoved() && (yDist == 2 || yDist == -2)) {
                canMoveTo = true;
            }
        }
    }

    return canMoveTo;
}


const int Pawn::value() const {
    // TODO
    return 0;
}


void Pawn::display(std::ostream& outStream) const {
    // if pawn has delegate, rely on delegate's display function.
    if (_delegate != nullptr) {
        _delegate -> display(outStream);

    // else print pawn color and symbol.
    } else {
        outStream << Piece::color()[0] << "P";
    }
}
