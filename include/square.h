#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

struct Square{
    std::string coordinate;
    std::unique_ptr<Piece> currentPiece = nullptr;
    char symbol = ' ';
};

#endif // SQUARE_H_INCLUDED
