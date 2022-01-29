#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include <string>

class Rook : public Piece{
    public:
        Rook(std::string color) : Piece(color, 'R') {}
        bool isValidMove(std::string move);
};

#endif
