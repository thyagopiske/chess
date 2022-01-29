#ifndef KING_H
#define KING_H

#include "piece.h"
#include <string>

class King : public Piece{
    public:
        King(std::string color) : Piece(color, 'K') {}
        bool isValidMove(std::string move);
};

#endif
