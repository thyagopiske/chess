#ifndef ROOK_H
#define ROOK_H

#include <string>
#include "piece.h"
#include "square.h"

class Rook : public Piece{
    public:
        Rook(std::string color) : Piece(color, 'R') {}
        bool isValidMove(std::string final_position, const Square game_board[][8]);
        std::vector<std::string> getPossibleMoves(const Square board[][8]);
};

#endif
