#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <string>

class Pawn : public Piece{
    public:
        Pawn(std::string color) : Piece(color, 'p') {}
        std::vector<std::string> getPossibleMoves(const Square board[][8]) const;
};

#endif
