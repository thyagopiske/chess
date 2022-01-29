#include "piece.h"
#include "string.h"

char Piece::getSymbol() const { return symbol; };

std::string Piece::getColor() const { return color; };

std::string Piece::getCurrentPosition() const { return currentPosition; };

void Piece::setCurrentPosition(std::string position) { currentPosition = position; };
