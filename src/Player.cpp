#include "Player.h"

#include "Board.h"
#include "Square.h"
#include "Piece.h"
// class Piece;


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


    while (!madeMove) {
        std::string move;

        // Prompt user for move and get move string.
        std::cout << getName() << " make move: ";
        getline(std::cin, move);

        // validate and attempt move.
        if (move.length() >= 5) {
            try {
                // Board's vector backing validates squares are on the board.
                Square& s1 = Board::getBoard().squareAt(move);
                Square& s2 = Board::getBoard().squareAt(move.substr(3,5));

                // validate 'from' square is occupied.
                if (s1.occupied()) {

                    // Ensure player owns piece attempting to move.
                    Piece& p1 = s1.occupiedBy();
                    if (playersPieces.find(&p1) != playersPieces.end()) {

                        // Make move.
                        madeMove = p1.moveTo(*this, s2);
                    }
                }

            // Catch if square does not exist on board.
            } catch (const std::out_of_range& e) {
                madeMove = false;
            }
        }
    }

    return madeMove;
}


void capture(Piece& aPiece) {
    // TODO
    // _captured.insert(&aPiece);
    // aPiece.setLocation(nullptr);
    std::cout << "I am never called" << std::endl;
}


const std::string& Player::getName() const {
    return _name;
}


const int Player::score() const {
    // TODO
    return 0;
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

// TODO: Check this
// std::set<Piece*> _captured;
