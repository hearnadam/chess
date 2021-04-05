#ifndef PLAYER_H
#define PLAYER_H

#include <string>;
#include <set>;
#include "Piece.h";
class King;

class Player {
    public:
        Player(std::string name);

        void setPieces(std::set<Piece*>& pieces);

        void setOpponent(Player& opponent);

        void setKing(King& king);

        bool makeMove();

        void capture(Piece& aPiece);

        const std::string& getName() const;

        const int score() const;

        std::set<Piece*>& getPieces() const;

        Player& getOpponent() const;

        King& getKing() const;
    private:
        std::string _name;
        Player* _opponent;

        std::set<Piece*> _my_pieces;
        std::set<Piece*> _captured;
        Piece* _my_king;

};
#endif
