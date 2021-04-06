#include <string>
#include <iostream>

// Classes that support Game behavior.
#include "Board.h"
#include "Square.h"
#include "Player.h"

// Piece classes
// #include "Piece.h" // TODO: Remove?
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"

// RestrictedPiece classes
// #include "RestrictedPiece.h" // TODO: Remove?
#include "Rook.h"
#include "Pawn.h"
#include "King.h"

void setupBoard(Board& board) {
    const std::string WHITE = "W";
    const std::string BLACK = "B";


    // Setup White Pieces
    board.squareAt(0,0).setOccupier(new Rook(WHITE));
    board.squareAt(1,0).setOccupier(new Knight(WHITE));
    board.squareAt(2,0).setOccupier(new Bishop(WHITE));
    board.squareAt(3,0).setOccupier(new Queen(WHITE));
    board.squareAt(4,0).setOccupier(new King(WHITE));
    board.squareAt(5,0).setOccupier(new Bishop(WHITE));
    board.squareAt(6,0).setOccupier(new Knight(WHITE));
    board.squareAt(7,0).setOccupier(new Rook(WHITE));

    for (int i = 0; i < 8; i++) {
        board.squareAt(i,1).setOccupier(new Pawn(WHITE));
    }


    // Setup Black Pieces
    board.squareAt(0,7).setOccupier(new Rook(BLACK));
    board.squareAt(1,7).setOccupier(new Knight(BLACK));
    board.squareAt(2,7).setOccupier(new Bishop(BLACK));
    board.squareAt(3,7).setOccupier(new Queen(BLACK));
    board.squareAt(4,7).setOccupier(new King(BLACK));
    board.squareAt(5,7).setOccupier(new Bishop(BLACK));
    board.squareAt(6,7).setOccupier(new Knight(BLACK));
    board.squareAt(7,7).setOccupier(new Rook(BLACK));

    for (int i = 0; i < 8; i++) {
        board.squareAt(i,6).setOccupier(new Pawn(BLACK));
    }
}

int main(int argc, char* argv[]) {
    Board& BOARD = Board::getBoard();

    // Initilize board and pieces state.
    setupBoard(BOARD);

    // Display Board to cout.
    BOARD.display(std::cout);

    return EXIT_SUCCESS;
}
