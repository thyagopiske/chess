#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <string>

class Pawn : public Piece{
    public:
        Pawn(std::string color) : Piece(color, 'p') {}
        bool isValidMove(std::string final_position, const Square game_board[][8]);
        std::vector<std::string> getPossibleMoves(const Square board[][8]);
};

#endif
