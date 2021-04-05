#include "Player.h"

Player::Player(std::string name):_name(name) {}

void Player::setPieces(std::set<Piece*>& pieces) {
    // TODO
}

void Player::setOpponent(Player& opponent) {
    // TODO
}

void Player::setKing(King& king) {
    // TODO
}

bool Player::makeMove() {
    return false;
}

void capture(Piece& aPiece) {
    // TODO
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

std::set<Piece*> _my_pieces;
