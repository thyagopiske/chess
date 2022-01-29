#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include <string>

class Bishop : public Piece{
    public:
        Bishop(std::string color) : Piece(color, 'B') {}
        bool isValidMove(std::string move);
};

#endif
