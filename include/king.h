#ifndef KING_H
#define KING_H

#include "piece.h"
#include <string>

class King : public Piece{
    bool has_moved = false;
    public:
        King(std::string color) : Piece(color, 'K') {}
        std::vector<std::string> getPossibleMoves(const Square board[][8]) const;
        bool getHasMoved() const;
        void setHasMovedToTrue();
};

#endif
