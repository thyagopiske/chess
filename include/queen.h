#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include <string>

class Queen : public Piece{
    public:
        Queen(std::string color) : Piece(color, 'Q') {}
        bool isValidMove(std::string move);
};

#endif
