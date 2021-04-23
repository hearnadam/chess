#include "Knight.h"

#include "Square.h"

Knight::Knight(std::string color):Piece(color) {}


bool Knight::canMoveTo(Square& location) const {
    // Knights can move in any direction, therefore absolute values are used to
    // measure distances.
    int yDist = std::abs(getLocation().getY() - location.getY());
    int xDist = std::abs(getLocation().getX() - location.getX());


    // Ensure movement is in L shape.
    // Potential L: is 1 to the side and 2 forwards or backwards
    // Other Potential L: is 2 to the side and 1 forwards or backwards
    return ((xDist == 1 && yDist == 2) || (xDist == 2 && yDist == 1));
}


const int Knight::value() const {
    return 3;
}


void Knight::display(std::ostream& outStream) const {
    outStream << Piece::color()[0] << "N";
}
