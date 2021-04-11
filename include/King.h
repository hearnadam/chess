#ifndef KING_H
#define KING_H

#include <string>
#include <iostream>

// TODO: Remove
#include "RestrictedPiece.h"

class King: public RestrictedPiece {
    public:
        /**
         * @brief Constructs a new King object with specified color.
         * 
         * @param color of the piece.
         */
        King(std::string color);

        /**
         * @brief Destroy the King object.
         */
        virtual ~King() = default;

        /**
         * @brief Returns true if the king can move to the square passed in.
         * 
         * @param location the square to be checked if the king can move to.
         * @return true if the king can move there.
         * @return false if the king can not move there.
         */
        virtual bool canMoveTo(Square& location) const;

        /**
         * @brief Returns an int of the value of the king.
         * 
         * @return const int the value of the king.
         */
        virtual const int value() const;

        /**
         * @brief Outputs the King's string representation to outStream.
         * 
         * @param outStream the ostream to output to.
         */
        virtual void display(std::ostream& outStream) const;

}; // King
#endif
