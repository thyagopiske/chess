#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
#include <memory>
#include "square.h"

class Piece{
    protected:
        const std::string color;
        const char symbol;
        std::string current_position;
    public:
        Piece(std::string color, char symbol) : color(color), symbol(symbol) {}
        virtual bool isValidMove(std::string final_position, const Square board[][8]) =0;
        virtual std::vector<std::string> getPossibleMoves(const Square board[][8]) =0;
        char getSymbol() const;
        std::string getColor() const;
        std::string getCurrentPosition() const;
        void setCurrentPosition(std::string position);
};

#endif
