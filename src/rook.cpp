#include <vector>
#include <algorithm>
#include "rook.h"

std::vector<std::string> Rook::getPossibleMoves(const Square board[][8]){

    /**Turns char 'a' into int 0, char 'b' into int 1... etc
    in order to represent the columns as numbers between 0 and 7 instead of chars between a and h.**/
    int piece_column = (int) getCurrentPosition()[0] - 'a';

    int piece_line = (int) getCurrentPosition()[1] - '1';

    std::vector<std::string> possible_moves;

    //Moving up
    if(piece_line < 7)
        for(int i = piece_line + 1; i < 8; i++){
            if(board[i][piece_column].pPiece != nullptr)
            {
                if(board[i][piece_column].pPiece->getColor() == color)
                    break;

                possible_moves.push_back(board[i][piece_column].coordinate);
                break;
            }
            else{ //if it's an empty square, add it to "possible_moves"
                possible_moves.push_back(board[i][piece_column].coordinate);
            }
        }


    //Moving down
    if(piece_line > 0)
        for(int i = piece_line - 1; i >= 0; i--){
            if(board[i][piece_column].pPiece != nullptr)
            {
                if(board[i][piece_column].pPiece->getColor() == color)
                    break;

                possible_moves.push_back(board[i][piece_column].coordinate);
                break;
            }
            else{
                possible_moves.push_back(board[i][piece_column].coordinate);
            }
        }


    //Moving right
    if(piece_column < 7)
        for(int j = piece_column + 1; j < 8; j++){
            if(board[piece_line][j].pPiece != nullptr)
            {
                if(board[piece_line][j].pPiece->getColor() == color)
                    break;

                possible_moves.push_back(board[piece_line][j].coordinate);
                break;
            }
            else{
                possible_moves.push_back(board[piece_line][j].coordinate);
            }
        }


    //Moving left
    if(piece_column > 0)
        for(int j = piece_column - 1; j >= 0; j--){
            if(board[piece_line][j].pPiece != nullptr)
            {
                if(board[piece_line][j].pPiece->getColor() == color)
                    break;

                possible_moves.push_back(board[piece_line][j].coordinate);
                break;
            }
            else{
                possible_moves.push_back(board[piece_line][j].coordinate);
            }
        }

    return possible_moves;
}

void Rook::setHasMovedToTrue() { has_moved = true; }

bool Rook::getHasMoved() { return has_moved; }
