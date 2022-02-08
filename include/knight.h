#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include <string>

class Knight : public Piece{
    public:
        Knight(std::string color) : Piece(color, 'N') {}
        bool isValidMove(const std::string& final_position, const Square board[][8]);
        std::vector<std::string> getPossibleMoves(const Square board[][8]);
};

#endif
