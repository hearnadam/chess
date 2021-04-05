#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen: public Piece {
    public:
        /**
         * @brief Constructs a new Queen object with specified color.
         * 
         * @param color of the piece.
         */
        Queen(std::string color);

        /**
         * @brief Destroy the Queen object.
         */
        virtual ~Queen();

        /**
         * @brief Returns true if the queen can move to the square passed in.
         * 
         * @param location the square to be checked if the queen can move to.
         * @return true if the queen can move there.
         * @return false if the queen can not move there.
         */
        virtual bool canMoveTo(Square& location) const;

        /**
         * @brief Returns an int of the value of the queen.
         * 
         * @return const int the value of the queen.
         */
        virtual const int value() const;

        /**
         * @brief Outputs the Queen's string representation to outStream.
         * 
         * @param outStream the ostream to output to.
         */
        virtual void display(std::ostream& outStream) const;

};
#endif
