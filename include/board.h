#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <memory>
#include "piece.h"
#include "square.h"

class Board{
    std::string whos_turn = "white";
    void printBlackSquares(const bool isTherePiece, const char symbol=' ', const std::string& piece_color=" ") const;
    void printWhiteSquares(const bool isTherePiece, const char symbol=' ', const std::string& piece_color=" ") const;
    bool putOwnKingInCheck(const std::string& initial_position, const std::string& final_position);
    std::vector<std::string> getThreateningPiecesPosition() const;
    bool canLongCastle();
    bool canShortCastle();
    public:
        Board();
        Square board[8][8];
        void display() const;
        void movePiece(const std::string& player_move);
        bool isMove(const std::string& player_move);
        bool isKingInCheck();
        bool isCheckmate();
        void switchTurn();
        bool isDraw();
        std::string getWhosTurn() const;
};

#endif
