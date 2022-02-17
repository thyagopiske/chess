#ifndef ROOK_H
#define ROOK_H

#include <string>
#include "piece.h"
#include "square.h"

class Rook : public Piece{
    bool has_moved = false;
    public:
        Rook(std::string color) : Piece(color, 'R') {}
        std::vector<std::string> getPossibleMoves(const Square board[][8]) const;
        bool getHasMoved() const;
        void setHasMovedToTrue();
};

#endif
