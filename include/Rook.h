#ifndef ROOK_H
#define ROOK_H

#include <string>
#include <iostream>

#include "RestrictedPiece.h"
class Square;

class Rook: public RestrictedPiece {
    public:
        /**
         * @brief Constructs a new Rook object with specified color.
         * 
         * @param color of the piece.
         */
        Rook(std::string color);

        /**
         * @brief Destroy the Rook object.
         */
        virtual ~Rook() = default;

        /**
         * @brief Returns true if the rook can move to the square passed in.
         * 
         * @param location the square to be checked if the rook can move to.
         * @return true if the rook can move there.
         * @return false if the rook can not move there.
         */
        virtual bool canMoveTo(Square& location) const;

        /**
         * @brief Returns an int of the value of the rook.
         * 
         * @return const int the value of the rook.
         */
        virtual const int value() const;

        /**
         * @brief Outputs the Rook's string representation to outStream.
         * 
         * @param outStream the ostream to output to.
         */
        virtual void display(std::ostream& outStream) const;

}; // Rook
#endif
