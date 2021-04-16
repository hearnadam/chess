#ifndef PAWN_H
#define PAWN_H

#include <string>
#include <iostream>

#include "RestrictedPiece.h"
class Square;
class Piece;


class Pawn: public RestrictedPiece {
    public:
        /**
         * @brief Constructs a new Pawn object with specified color.
         * 
         * @param color of the piece.
         */
        Pawn(std::string color);

        /**
         * @brief Destroy the Pawn object.
         */
        virtual ~Pawn();

        /**
         * @brief Set the square the piece is on.
         * 
         * @param square the square where it will be set.
         */
        virtual void setLocation(Square* square);


        /**
         * @brief Move this pawn to the square specified if possible.
         * If pawn reaches end of board sucessfully, upgrade to queen.
         * 
         * @param byPlayer the player moving the piece.
         * @param to the square the piece is being moved to.
         * @return true if the piece moved.
         * @return false if the piece did not move.
         */
        virtual bool moveTo(Player& byPlayer, Square& to);


        /**
         * @brief Returns true if the pawn can move to the square passed in.
         * 
         * @param location the square to be checked if the pawn can move to.
         * @return true if the pawn can move there.
         * @return false if the pawn can not move there.
         */
        virtual bool canMoveTo(Square& location) const;

        /**
         * @brief Returns an int of the value of the pawn.
         * 
         * @return const int the value of the pawn.
         */
        virtual const int value() const;

        /**
         * @brief Outputs the Pawn's string representation to outStream.
         * 
         * @param outStream the ostream to output to.
         */
        virtual void display(std::ostream& outStream) const;

    private:
        Piece* _delegate;

}; // Pawn
#endif
