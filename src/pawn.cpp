#include <vector>
#include <algorithm>
#include "pawn.h"

std::vector<std::string> Pawn::getPossibleMoves(const Square board[][8]) const{

    /**Turns char 'a' into int 0, char 'b' into int 1... etc
    in order to represent the columns as numbers between 0 and 7 instead of chars between a and h.**/
    int piece_column = (int) getCurrentPosition()[0] - 'a';
    int piece_line = (int) getCurrentPosition()[1] - '1';

    std::vector<std::string> possible_moves;

    //Case: white pawn
    if(piece_line < 7){
        if(board[piece_line][piece_column].pPiece->getColor() == "white"){
            //Moving up
            if(piece_line == 1) {
                //First move: can move 1 or 2 squares forward
                for(int i = piece_line + 1; i < 4; i++)
                {
                    if(board[i][piece_column].pPiece != nullptr){
                        break;
                    }
                    else{
                        possible_moves.push_back(board[i][piece_column].coordinate);
                    }
                }
            }
            if(piece_line >= 2){
                //Second+ move: can only move 1 square forward
                if(board[piece_line + 1][piece_column].pPiece == nullptr){
                    possible_moves.push_back(board[piece_line + 1][piece_column].coordinate);
                }

            }
            //Moving diagonally (right) to capture opponent piece
            if(piece_column < 7){
                if(board[piece_line + 1][piece_column + 1].pPiece != nullptr)
                    if(board[piece_line + 1][piece_column + 1].pPiece->getColor() == "black"){
                        possible_moves.push_back(board[piece_line + 1][piece_column + 1].coordinate);
                    }
            }
            //Moving diagonally (left) to capture opponent piece
            if(piece_column > 0){
                if(board[piece_line + 1][piece_column - 1].pPiece != nullptr)
                    if(board[piece_line + 1][piece_column - 1].pPiece->getColor() == "black"){
                         possible_moves.push_back(board[piece_line + 1][piece_column - 1].coordinate);
                    }
            }
        }
    }

    //Case: black pawn
    if(piece_line > 0){
        if(board[piece_line][piece_column].pPiece->getColor() == "black"){
            //Moving up
            if(piece_line == 6) {
                //First move: can move 1 or 2 squares forward
                for(int i = piece_line - 1; i > 3; i--)
                {
                    if(board[i][piece_column].pPiece != nullptr){
                        break;
                    }
                    else{
                        possible_moves.push_back(board[i][piece_column].coordinate);
                    }
                }
            }
            if(piece_line <= 5){
                //Second+ move: can only move 1 square forward
                if(board[piece_line - 1][piece_column].pPiece == nullptr){
                    possible_moves.push_back(board[piece_line - 1][piece_column].coordinate);
                }

            }
            //Moving diagonally (right) to capture opponent piece
            if(piece_column > 0){
                if(board[piece_line - 1][piece_column - 1].pPiece != nullptr)
                    if(board[piece_line - 1][piece_column - 1].pPiece->getColor() == "white"){
                        possible_moves.push_back(board[piece_line - 1][piece_column - 1].coordinate);
                    }
            }
            //Moving diagonally (left) to capture opponent piece
            if(piece_column < 7){
                if(board[piece_line - 1][piece_column + 1].pPiece != nullptr)
                    if(board[piece_line - 1][piece_column + 1].pPiece->getColor() == "white"){
                         possible_moves.push_back(board[piece_line - 1][piece_column + 1].coordinate);
                    }
            }
        }
    }

    return possible_moves;
}
