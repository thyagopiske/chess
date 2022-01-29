#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <memory>

class Piece{
    protected:
        const std::string color;
        const char symbol;
        std::string currentPosition;
    public:
        Piece(std::string color, char symbol) : color(color), symbol(symbol) {}
        virtual bool isValidMove(std::string move) =0;
        char getSymbol() const;
        std::string getColor() const;
        std::string getCurrentPosition() const;
        void setCurrentPosition(std::string position);
};

#endif
