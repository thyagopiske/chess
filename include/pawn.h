#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <string>

class Pawn : public Piece{
    public:
        Pawn(std::string color) : Piece(color, 'p') {}
        bool isValidMove(std::string move);
};

#endif
