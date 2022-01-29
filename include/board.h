#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <memory>
#include "piece.h"
#include "square.h"

class Board{
    std::string whosTurn="white";
    public:
        Board();
        Square board[8][8];
        void display();
        bool isMove(const std::string& _move);
        void switchTurn();
};

#endif
