#include "Piece.h"

#include "Square.h"
#include "Player.h"
#include "King.h"

Piece::Piece(std::string color):_color(color), _square(nullptr){}


void Piece::setLocation(Square* square) {
    _square = square;
}


// TODO: Rework moveTo
bool Piece::moveTo(Player& byPlayer, Square& to) {
    bool moved = false;

    // Both these variables are created in case movement puts king in check.
    // These allow for the pieces to be put back.
    Piece* toCapture = nullptr;
    Square& oldLocation = getLocation();

    // Check geometry & move validity.
    if (canMoveTo(to)) {

        // Check if destination is occupied.
        if (to.occupied()) {

            // Ensure that this player does not own piece on destination ('to').
            if (!(byPlayer.getPieces().find(&to.occupiedBy())
                    != byPlayer.getPieces().end())) {

                // Store piece to capture later if move is deemed possible.
                toCapture = &to.occupiedBy();

                // Remove piece from board to prepare for this piece's movement.
                to.occupiedBy().setLocation(nullptr);
                moved = true;
            }
        } else {
            moved = true;
        }

        // If no piece was occupying destination, or it was opponents piece.
        if (moved) {
            // Get 'source' for move and remove its occupant. 
            getLocation().setOccupier(nullptr);

            // Set destination to contain this piece & set this piece's location.
            to.setOccupier(this);

            // Validate that this move does not put player's king in check.
            if (checkForCheck(byPlayer)) {

                // Put back move since player would be in check.
                moved = false;

                if (toCapture) {
                }
                oldLocation.setOccupier(this);

            }

            // If destination was occupied
            if(toCapture) {

                // Put back opponent's piece that was removed from board.
                if(!moved) {
                    to.setOccupier(toCapture);


                // Else, move made, capture opponent's piece.
                } else {
                    byPlayer.capture(*toCapture);
                }
            }

        }
    }

    return moved;
}


bool Piece::checkForCheck(Player& aPlayer) {
    bool inCheck = false;
    Square& kingLocation = aPlayer.getKing().getLocation();
    // std::cout << "Check for check" << std::endl;
    

    for(auto itr = aPlayer.getOpponent().getPieces().cbegin(); !inCheck
        && itr != aPlayer.getOpponent().getPieces().cend(); itr++) {

        if ((*itr)->isOnBoard()) {
            inCheck = (*itr)->canMoveTo(kingLocation);
            if (inCheck) {
                (*itr)->display(std::cout);
                std::cout << std::endl;
            }
        }
    }

    return inCheck;
}


const std::string Piece::color() const {
    return _color;
}


const bool Piece::isOnBoard() const {
    return _square != nullptr;
}


Square& Piece::getLocation() const {
    return *_square;
}
