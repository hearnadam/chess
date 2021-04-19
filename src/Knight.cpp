#include "Knight.h"

Knight::Knight(std::string color):Piece(color) {}


bool Knight::canMoveTo(Square& location) const {
    // TODO
    return false;
}


const int Knight::value() const {
    return 3;
}


void Knight::display(std::ostream& outStream) const {
    outStream << Piece::color()[0] << "N";
}
