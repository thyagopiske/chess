#include "piece.h"
#include "string.h"

char Piece::getSymbol() const { return symbol; };

std::string Piece::getColor() const { return color; };

std::string Piece::getCurrentPosition() const { return current_position; };

void Piece::setCurrentPosition(std::string position) { current_position = position; };
