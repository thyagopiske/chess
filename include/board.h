#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <memory>
#include "piece.h"
#include "square.h"

class Board{
    std::string whos_turn = "white";
    public:
        Board();
        Square board[8][8];
        void display();
        void movePiece(const std::string& player_move);
        bool isMove(const std::string& player_move);
        bool isKingInCheck();
        void switchTurn();
};

#endif
