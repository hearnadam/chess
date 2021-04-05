/*
 * TODO: Fix Comments
 */
#ifndef SQUARE_H
#define SQUARE_H

class ostream;
class Piece;

class Square { 
    public:
        /**
         * @brief Construct a new Square object with x & y given.
         * 
         * @param x row.
         * @param y column.
         */
        Square(int x, int y);


        /**
         * @brief Destroy the Square object.
         */
        ~Square() = default;


        /**
         * @brief Set the Square's occupier.
         * 
         * @param piece pointer to a piece object.
         */
        void setOccupier(Piece* piece);


        /**
         * @brief Get x.
         * 
         * @return const int x.
         */
        const int getX() const;


        /**
         * @brief Get y.
         * 
         * @return const int y.
         */
        const int getY() const;


        /**
         * @brief Returns true if square is occupied.
         * 
         * @return true if square is occupied.
         * @return false if square is not occupied.
         */
        const bool occupied() const;


        /**
         * @brief Returns a reference to the square's occupant.
         * 
         * @return Piece& a reference to the square's occupant.
         */
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
