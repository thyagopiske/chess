#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include <string>

class Knight : public Piece{
    public:
        Knight(std::string color) : Piece(color, 'N') {}
        std::vector<std::string> getPossibleMoves(const Square board[][8]) const;
};

#endif
