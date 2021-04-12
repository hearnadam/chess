#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>

class Square;
class Player;

class Piece {
    public:
        /**
         * @brief Construct a new Piece object with the color passed in.
         * 
         * @param color the color of the piece to be constructed.
         */
        Piece(std::string color);

        /**
         * @brief Destroy the Piece object.
         */
        virtual ~Piece() = default;

        /**
         * @brief Set the square the piece is on.
         * 
         * @param square the square where it will be set.
         */
        virtual void setLocation(Square* square);

        /**
         * @brief Move this piece to the square specified if possible.
         * 
         * @param byPlayer the player moving the piece.
         * @param to the square the piece is being moved to.
         * @return true if the piece moved.
         * @return false if the piece did not move.
         */
        virtual bool moveTo(Player& byPlayer, Square& to);


        /**
         * @brief Returns the color of the piece as a const.
         * 
         * @return const std::string color of piece.
         */
        const std::string color() const;

        /**
         * @brief Returns true if the piece is on the board.
         * 
         * @return true if piece is on board.
         * @return false if piece is not on the board.
         */
        const bool isOnBoard() const;

        /**
         * @brief Gets the location of the piece.
         * 
         * @return Square& the reference to the square the piece is on.
         */
        Square& getLocation() const;


        /**
         * @brief Returns true if the piece can move to the square passed in.
         * 
         * @param location the square to be checked if the piece can move to.
         * @return true if the piece can move there.
         * @return false if the piece can not move there.
         */
        virtual bool canMoveTo(Square& location) const = 0;

        /**
         * @brief Returns an int of the value of the piece.
         * 
         * @return const int the value of the piece.
         */
        virtual const int value() const = 0;

        /**
         * @brief Outputs the piece's string representation to outStream.
         * 
         * @param outStream the ostream to output to.
         */
        virtual void display(std::ostream& outStream) const = 0;

    private:
        /**
         * @brief Construct a new Piece object
         */
        Piece() = default;
        // The string representation of the piece color.
        const std::string _color;

        // Where the piece things it is.
        Square* _square;

}; // Piece
#endif
