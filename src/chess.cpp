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


Player* setup(Board& board) {
    const std::string WHITE = "W";
    const std::string BLACK = "B";

    Player* whitePlayer = new Player("White");
    Player* blackPlayer = new Player("Black");

    std::set<Piece*>& whitePieces = whitePlayer -> getPieces();
    std::set<Piece*>& blackPieces = blackPlayer -> getPieces();

    // Set opponents
    whitePlayer -> setOpponent(*blackPlayer);
    blackPlayer -> setOpponent(*whitePlayer);

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

    // Set White Piece Locations
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            Square& aSquare = board.squareAt(j,i);
            aSquare.occupiedBy().setLocation(&aSquare);
            whitePieces.insert(&aSquare.occupiedBy());
        }
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

    // Set Black Piece Locations
    for (int i = 6; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Square& aSquare = board.squareAt(j,i);
            aSquare.occupiedBy().setLocation(&aSquare);
            blackPieces.insert(&aSquare.occupiedBy());
        }
    }
    return whitePlayer;
}


int main(int argc, char* argv[]) {
    Board& BOARD = Board::getBoard();
    bool gameOver = false;


    // Initilize board and pieces state.
    Player* _currentPlayer = setup(BOARD);

    // Loop until game is finished
    while (!gameOver) {
        // Display Board at every valid move
        BOARD.display(std::cout);

        // Get player to make move, then switch players
        _currentPlayer -> makeMove();
        _currentPlayer = &_currentPlayer -> getOpponent();
    }


    return EXIT_SUCCESS;
}
