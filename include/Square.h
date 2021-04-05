/*
 * TODO: A bogus Square class just for compilation purposes
 */
#ifndef SQUARE_H
#define SQUARE_H

class ostream;
class Piece;

class Square { 
    public:
        Square(int x, int y);

        ~Square();

        void setOccupier(Piece* piece);

        const int getX() const;

        const int getY() const;

        const bool occupied() const;

        Piece& occupiedBy() const;

    private:
        int _x;
        int _y;
        Piece* _occupant;
};
#endif
