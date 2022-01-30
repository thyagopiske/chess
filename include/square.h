#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

class Piece;

struct Square{
    std::string coordinate;
    std::unique_ptr<Piece> pPiece = nullptr;
    char symbol = ' ';
};

#endif // SQUARE_H_INCLUDED
