#ifndef BOARD_H
#define BOARD_H

class Square;
#include <iostream>
#include <string>
#include <vector>

class Board {
   public:
      // Accessors

      /**
       * @return The Board
       */
      static Board& getBoard();

      /**
       * @param x    column of the square to return
       * @param y    row of the square to return
       * @return     reference to the square at the given location
       */
      Square& squareAt(int x, int y) const;

      /**
       * @param location column of the square to return
       * @return         reference to the square at the given location
       */
      Square& squareAt(std::string location) const;

      /**
       * Returns the distance between two squares as an int.
       * 
       * @param from    square to check from
       * @param to      square to check to
       * @return        distance between two squares as int.
       */
      int distanceBetween(Square& from, Square& to) const;

      /**
       * Check to see if the squares are 'verticle' and the path is clear
       * 
       * @param from    square to check from
       * @param to      square to check to
       * @return        true if squares are verticle and path is clear
       */
      bool isClearVerticle(Square& from, Square& to) const;

      /**
       * Check to see if the squares are 'horizontal' and the path is clear
       * 
       * @param from    square to check from
       * @param to      square to check to
       * @return        true if squares are horizontal and path is clear
       */
      bool isClearHorizontal(Square& from, Square& to) const;

      /**
       * Check to see if the squares are 'diagonal' and the path is clear
       * 
       * @param from    square to check from
       * @param to      square to check to
       * @return        true if squares are diagonal and path is clear
       */
      bool isClearDiagonal(Square& from, Square& to) const;

      /**
       * Display the board
       *
       * @param outStream  stream to display to 
       */
      void display(std::ostream& outStream) const;

   private:
        /*
        * Private constructor for singleton pattern.
        */
        Board();

        // Static class variables, one to hold the lone board and another to
        // define the board dimensions
        static Board _the_board;
        static const int _DIMENSION = 8;

        // A vector of vector of Square pointers for the board
        std::vector< std::vector<Square*> > _squares;

}; // Board
#endif
