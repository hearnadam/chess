#include "Knight.h"

Knight::Knight(std::string color):Piece(color) {}


bool Knight::canMoveTo(Square& location) const {
    return false;
}


const int Knight::value() const {
    // TODO
    return 0;
}


void Knight::display(std::ostream& outStream) const {
    outStream << Piece::color() << "N";
}
