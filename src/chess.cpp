#include <string>
#include <iostream>

// Classes that support Game behavior.
#include "Board.h"
#include "Square.h"
#include "Player.h"

// Piece classess
#include "Queen.h"
#include "Knight.h"
#include "Bishop.h"

// RestrictedPiece classes
#include "Rook.h"
#include "Pawn.h"
#include "King.h"

void setupBoard(Board& board, Player& whitePlayer, Player& blackPlayer) {
    const std::string WHITE = "White";
    const std::string BLACK = "Black";

    // Setup White Pieces
    board.squareAt(0,0).setOccupier(new Rook(WHITE));
    board.squareAt(1,0).setOccupier(new Knight(WHITE));
    board.squareAt(2,0).setOccupier(new Bishop(WHITE));
    board.squareAt(3,0).setOccupier(new Queen(WHITE));
    board.squareAt(4,0).setOccupier(new King(WHITE));
    board.squareAt(5,0).setOccupier(new Bishop(WHITE));
    board.squareAt(6,0).setOccupier(new Knight(WHITE));
    board.squareAt(7,0).setOccupier(new Rook(WHITE));

    // Setup White pawns and add to White set.
    for (int i = 0; i < 8; i++) {
        board.squareAt(i, 1).setOccupier(new Pawn(WHITE));
        whitePlayer.getPieces().insert(& board.squareAt(i, 1).occupiedBy());

    }

    // Set White Piece Locations
    for (int i = 0; i < 8; i++) {
        whitePlayer.getPieces().insert(& board.squareAt(i, 0).occupiedBy());
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

    // Setup Black pawns and add to Black set.
    for (int i = 0; i < 8; i++) {
        board.squareAt(i, 6).setOccupier(new Pawn(BLACK));
        blackPlayer.getPieces().insert(& board.squareAt(i, 6).occupiedBy());

    }

    // Add Top row of Black Pieces to set.
    for (int i = 0; i < 8; i++) {
        blackPlayer.getPieces().insert(& board.squareAt(i, 7).occupiedBy());
    }
}


int main(int argc, char* argv[]) {
    bool gameOver = false;
    Board& theBoard = Board::getBoard();

    // Initilize Players & current player reference.
    Player whitePlayer = Player("White");
    Player blackPlayer = Player("Black");
    Player& currentPlayer = whitePlayer;

    // Initilize board and pieces state.
    setupBoard(theBoard, whitePlayer, blackPlayer);

    // Set players' opponents.
    whitePlayer.setOpponent(blackPlayer);
    blackPlayer.setOpponent(whitePlayer);


    // Loop until game is finished
    while (!gameOver) {
        // Display Board at every valid move
        theBoard.display(std::cout);

        // Get player to make move, then switch players
        gameOver = !currentPlayer.makeMove();
        currentPlayer = currentPlayer.getOpponent();
    }


    return EXIT_SUCCESS;
}
