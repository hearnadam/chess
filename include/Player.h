#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <set>
class Piece;
class King;

class Player {
    public:
        /**
         * @brief Construct a new Player with name given.
         * 
         * @param name the name of the player.
         */
        Player(std::string name);


        /**
         * @brief Destroy the Player object.
         */
        ~Player() = default;


        /**
         * @brief Set the player's Pieces.
         * 
         * @param pieces a set of Piece pointers the player owns.
         */
        void setPieces(std::set<Piece*>& pieces);


        /**
         * @brief Set the player's Opponent.
         * 
         * @param opponent rerference to other player.
         */
        void setOpponent(Player& opponent);


        /**
         * @brief Set the player's King.
         * 
         * @param king reference to player's king.
         */
        void setKing(King& king);


        /**
         * @brief Prompts player for move until valid move is given.
         * Moves piece and captures as necessary.
         * 
         * @return true if move was made.
         * @return false if move was not made.
         */
        bool makeMove();


        /**
         * @brief Captures opponent's piece and adds it to player's captured set.
         * 
         * @param aPiece the piece to capture.
         */
        void capture(Piece& aPiece);


        /**
         * @brief Get player's name.
         * 
         * @return const std::string& player's name.
         */
        const std::string& getName() const;


        /**
         * @brief Gets the total value of player's captured pieces.
         * 
         * @return const int the total value of player's captured pieces.
         */
        const int score() const;


        /**
         * @brief Get the player's pieces.
         * 
         * @return std::set<Piece*>& a set of player's pieces.
         */
        std::set<Piece*>& getPieces() const;


        /**
         * @brief Get player's opponent.
         * 
         * @return Player& player's opponent.
         */
        Player& getOpponent() const;


        /**
         * @brief Get the player's King.
         * 
         * @return King& player's King.
         */
        King& getKing() const;


        /**
         * @brief Checks if opponent has this player in check.
         * 
         * @return true if aPlayer is in check.
         * @return false if aPlayer is not in check.
         */
        bool inCheck();


    private:
        /**
         * @brief Private constructor to prevent compiler from creating a public one.
         */
        Player() = default;

        // Player's name.
        std::string _name;

        // Pointer to Player's king.
        King* _my_king;

        // Pointer to player's opponent.
        Player* _opponent;

        // The player's peices (that have not  been captured).
        std::set<Piece*>* _my_pieces;

        // The pieces captured by player.
        std::set<Piece*> _captured;

}; // Player
#endif
