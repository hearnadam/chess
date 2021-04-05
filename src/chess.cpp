// #include <string>
#include <iostream>
#include "Board.h"
#include "Square.h"

#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"


int main(int argc, char* argv[]) {
    const Board& BOARD = Board::getBoard();
    const std::string WHITE = "W";
    const std::string BLACK = "B";


    // Setup White Pieces
    BOARD.squareAt(0,0).setOccupier(new Rook(WHITE));
    BOARD.squareAt(1,0).setOccupier(new Knight(WHITE));
    BOARD.squareAt(2,0).setOccupier(new Bishop(WHITE));
    BOARD.squareAt(3,0).setOccupier(new Queen(WHITE));
    BOARD.squareAt(4,0).setOccupier(new King(WHITE));
    BOARD.squareAt(5,0).setOccupier(new Bishop(WHITE));
    BOARD.squareAt(6,0).setOccupier(new Knight(WHITE));
    BOARD.squareAt(7,0).setOccupier(new Rook(WHITE));

    for (int i = 0; i < 8; i++) {
        BOARD.squareAt(i,1).setOccupier(new Pawn(WHITE));
    }


    // Setup Black Pieces
    BOARD.squareAt(0,7).setOccupier(new Rook(BLACK));
    BOARD.squareAt(1,7).setOccupier(new Knight(BLACK));
    BOARD.squareAt(2,7).setOccupier(new Bishop(BLACK));
    BOARD.squareAt(3,7).setOccupier(new Queen(BLACK));
    BOARD.squareAt(4,7).setOccupier(new King(BLACK));
    BOARD.squareAt(5,7).setOccupier(new Bishop(BLACK));
    BOARD.squareAt(6,7).setOccupier(new Knight(BLACK));
    BOARD.squareAt(7,7).setOccupier(new Rook(BLACK));

    for (int i = 0; i < 8; i++) {
        BOARD.squareAt(i,6).setOccupier(new Pawn(BLACK));
    }

    // Display Board to cout.
    BOARD.display(std::cout);

    return EXIT_SUCCESS;
}
