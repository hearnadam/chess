#ifndef BISHOP_H
#define BISHOP_H

#include <string>
#include <iostream>

#include "Piece.h"
class Location;
class Square;

class Bishop: public Piece {
    public:
        /**
         * @brief Constructs a new Bishop object with specified color.
         * 
         * @param color of the piece.
         */
        Bishop(std::string color);

        /**
         * @brief Destroy the Bishop object.
         */
        virtual ~Bishop() = default;

        /**
         * @brief Returns true if the bishop can move to the square passed in.
         * 
         * @param location the square to be checked if the bishop can move to.
         * @return true if the bishop can move there.
         * @return false if the bishop can not move there.
         */
        virtual bool canMoveTo(Square& location) const;

        /**
         * @brief Returns an int of the value of the bishop.
         * 
         * @return const int the value of the bishop.
         */
        virtual const int value() const;

        /**
         * @brief Outputs the Bishop's string representation to outStream.
         * 
         * @param outStream the ostream to output to.
         */
        virtual void display(std::ostream& outStream) const;

}; // Bishop
#endif
