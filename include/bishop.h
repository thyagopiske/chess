#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include <string>

class Bishop : public Piece{
    public:
        Bishop(std::string color) : Piece(color, 'B') {}
        bool isValidMove(const std::string& final_position, const Square board[][8]);
        std::vector<std::string> getPossibleMoves(const Square board[][8]);
};

#endif
