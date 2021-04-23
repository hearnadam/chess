#include "Player.h"

#include "Board.h"
#include "Square.h"
#include "Piece.h"


Player::Player(std::string name):_name(name), _my_pieces(new std::set<Piece*>()) {}


void Player::setPieces(std::set<Piece*>& pieces) {
    _my_pieces = &pieces;
}


void Player::setOpponent(Player& opponent) {
    _opponent = &opponent;
}


void Player::setKing(King& king) {
    _my_king = &king;
}


bool Player::makeMove() {
    bool madeMove = false;
    std::set<Piece *>& playersPieces = getPieces();
    std::string userMove;


    // Loop until a move is made.
    while (!madeMove) {


        // Prompt user for move and get move string.
        std::cout << getName() << " make move: ";
        getline(std::cin, userMove);


        // validate inputted string is 5 or more characters
        if (userMove.length() >= 5) {

            // In try block to catch exception if user inputs bad data.
            try {
                // Board's vector backing validates squares are on the board.
                // Pass in substring of 'move' string to get 'from' and 'to'.
                Square& from = Board::getBoard().squareAt(userMove.substr(0,2));
                Square& to = Board::getBoard().squareAt(userMove.substr(3,5));

                // validate 'from' square is occupied.
                if (from.occupied()) {

                    // Ensure player owns piece attempting to move.
                    if (playersPieces.find(&from.occupiedBy())
                            != playersPieces.end()) {

                        // Tell piece to make move.
                        madeMove = from.occupiedBy().moveTo(*this, to);
                    }
                }

            // Catch if square does not exist on board.
            } catch (const std::out_of_range& e) {
                madeMove = false;
            }
        }

        // Alert user move was invalid if move was not made.
        if (!madeMove) {
            std::cout << "Invalid Move. Try Again." << std::endl;
        }
    }

    return madeMove;
}


void Player::capture(Piece& aPiece) {
    _captured.insert(&aPiece);
    aPiece.setLocation(nullptr);
}


const std::string& Player::getName() const {
    return _name;
}


const int Player::score() const {
    // TODO: Check Correctness
    int score = 0;

    // Loop through all captured pieces and sum.
    for(Piece* captured : _captured) {
        score += captured->value();
    }

    return score;
}


std::set<Piece*>& Player::getPieces() const {
    return *_my_pieces;
}


Player& Player::getOpponent() const {
    return *_opponent;
}


King& Player::getKing() const {
    return *_my_king;
}
