#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include <string>

class Queen : public Piece{
    public:
        Queen(std::string color) : Piece(color, 'Q') {}
        bool isValidMove(const std::string& final_position, const Square board[][8]);
        std::vector<std::string> getPossibleMoves(const Square board[][8]);
};

#endif
