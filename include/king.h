#ifndef KING_H
#define KING_H

#include "piece.h"
#include <string>

class King : public Piece{
    public:
        King(std::string color) : Piece(color, 'K') {}
        bool isValidMove(const std::string& final_position, const Square board[][8]);
        std::vector<std::string> getPossibleMoves(const Square board[][8]);
};

#endif
