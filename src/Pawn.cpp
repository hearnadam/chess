#include "Pawn.h"

#include "Board.h"
#include "Square.h"

Pawn::Pawn(std::string color):RestrictedPiece(color), _delegate(nullptr) {}

Pawn::~Pawn() {
    // TODO: Take care of delegate
}

void Pawn::setLocation(Square* square) {
    Piece::setLocation(square);
    if (_delegate != nullptr) {
        _delegate -> setLocation(square);
    }
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
    } else if ((color()[0] == 'W' && yDist > 0) || (color()[0] == 'B' && yDist < 0)) {

        // If occupied limit movement to one diagnol space
        if (location.occupied()) {

            // Ensure movement is only one forward and one to the side.
            if ((xDist == -1 || xDist == 1) && (yDist == -1 || yDist == 1)) {
                canMoveTo = true;
            }

        // If vertical is clear, ensure distance is acceptable.
        } else if (Board::getBoard().isClearVerticle(thisLocation, location)) {

            // regardless of position allow 1 space movement if clear.
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

    // else print color and symbol.
    } else {
        outStream << Piece::color()[0] << "P";
    }
}
