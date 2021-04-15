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
    // TODO: Check if I need to explicitely call this.
    // Piece::~Piece();
}

void Pawn::setLocation(Square* square) {
    // Set (this) pawn location.
    Piece::setLocation(square);

    // Set delegate's location if it exists.
    if (_delegate != nullptr) {
        _delegate -> setLocation(square);

        // If delegate is null and square is not null.
    } else if (square != nullptr) {
        //  If Pawn reaches color dependant end of board, create delegate.
        if ((this -> color()[0] == 'W' && square -> getY() == 7)
            || (this -> color()[0] == 'B' && square -> getY() == 0)) {

                // Auto set delegate to be queen of this color.
                _delegate = new Queen(this -> color());
        }
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
    } else if ((color()[0] == 'W' && yDist < 3 && yDist > 0)
                || (color()[0] == 'B' && yDist < 0 && yDist > -3)) {

        // If occupied limit movement to one diagnol space
        if (location.occupied()) {

            // Ensure movement is only one forward and one to the side.
            if ((xDist == -1 || xDist == 1) && (yDist == -1 || yDist == 1)) {

                // Ensure color of pawn to capture is not the same as this pawn.
                if (location.occupiedBy().color()[0] != this -> color()[0]) {
                    canMoveTo = true;
                }
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

    // else print pawn color and symbol.
    } else {
        outStream << Piece::color()[0] << "P";
    }
}
