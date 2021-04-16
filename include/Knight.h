#ifndef KNIGHT_H
#define KNIGHT_H

#include <string>
#include <iostream>

#include "Piece.h"
class Square;


class Knight: public Piece {
    public:
        /**
         * @brief Constructs a new Knight object with specified color.
         * 
         * @param color of the piece.
         */
        Knight(std::string color);

        /**
         * @brief Destroy the Knight object.
         */
        virtual ~Knight() = default;

        /**
         * @brief Returns true if the knight can move to the square passed in.
         * 
         * @param location the square to be checked if the knight can move to.
         * @return true if the knight can move there.
         * @return false if the knight can not move there.
         */
        virtual bool canMoveTo(Square& location) const;

        /**
         * @brief Returns an int of the value of the knight.
         * 
         * @return const int the value of the knight.
         */
        virtual const int value() const;

        /**
         * @brief Outputs the Knight's string representation to outStream.
         * 
         * @param outStream the ostream to output to.
         */
        virtual void display(std::ostream& outStream) const;

}; // Knight
#endif
