/*
 * TODO: Fix Comments
 */
#ifndef SQUARE_H
#define SQUARE_H

class ostream;
class Piece;

class Square { 
    public:
        Square(int x, int y);

        ~Square() = default;

        void setOccupier(Piece* piece);

        const int getX() const;

        const int getY() const;

        const bool occupied() const;

        Piece& occupiedBy() const;

    private:
        /**
         * @brief Private constructor to prevent compiler from creating a public one.
         */
        Square() = default;

        // row
        int _x;
        // column
        int _y;

        // Reference to the piece that occupies this Square.
        Piece* _occupant;
}; // Square
#endif
