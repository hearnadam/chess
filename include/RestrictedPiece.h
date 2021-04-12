#ifndef RESTRICTEDPIECE_H
#define RESTRICTEDPIECE_H

#include <string>
#include <iostream>

#include "Piece.h"
class Square;
class Player;

class RestrictedPiece: public Piece {
    public:
        /**
         * @brief Construct a new RestrictedPiece object with the color passed in.
         * 
         * @param color the color of the piece to be constructed.
         */
        RestrictedPiece(std::string color);


        /**
         * @brief Destroy the RestrictedPiece object.
         */
        virtual ~RestrictedPiece() = default;


        /**
         * @brief Move this piece to the square specified if possible.
         * Sets flag if piece does move.
         * 
         * @param byPlayer the player moving the piece.
         * @param to the square the piece is being moved to.
         * @return true if the piece moved.
         * @return false if the piece did not move.
         */
        virtual bool moveTo(Player& byPlayer, Square& to);


    protected:
        /**
         * @brief Returns true if a Restricted Piece has moved.
         * 
         * @return true if a Restricted Piece has moved.
         * @return false  if a Restricted Piece has not moved.
         */
        const bool hasMoved() const;


    private:
        // boolean to keep track if RestrictedPiece has moved.
        bool _moved;


}; // RestrictedPiece
#endif
