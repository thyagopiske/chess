#include <vector>
#include <algorithm>
#include "knight.h"

bool Knight::isValidMove(const std::string& final_position, const Square board[][8]){
    return true; //TEMP
};

std::vector<std::string> Knight::getPossibleMoves(const Square board[][8]){

    int piece_column = (int) getCurrentPosition()[0] - 'a';

    int piece_line = (int) getCurrentPosition()[1] - '1';

    std::vector<std::string> possible_moves;

    //Moving up
    if(piece_line <= 5){
        //To the right
        if(piece_column <= 6){
            if(board[piece_line + 2][piece_column + 1].pPiece != nullptr)
            {
                if(board[piece_line + 2][piece_column + 1].pPiece->getColor() == color)
                {
                    possible_moves.push_back(board[piece_line + 2][piece_column + 1].coordinate);
                }

            }
            else{
                possible_moves.push_back(board[piece_line + 2][piece_column + 1].coordinate);
            }
        }
        // To the left
        if(piece_column >= 1){
            if(board[piece_line + 2][piece_column - 1].pPiece != nullptr)
            {
                if(board[piece_line + 2][piece_column - 1].pPiece->getColor() == color)
                {
                    possible_moves.push_back(board[piece_line + 2][piece_column - 1].coordinate);
                }

            }
            else{
                possible_moves.push_back(board[piece_line + 2][piece_column - 1].coordinate);
            }
        }
    }

    //Moving down
    if(piece_line >= 2){
        //To the right
        if(piece_column <= 6){
            if(board[piece_line - 2][piece_column + 1].pPiece != nullptr)
            {
                if(board[piece_line - 2][piece_column + 1].pPiece->getColor() == color)
                {
                    possible_moves.push_back(board[piece_line - 2][piece_column + 1].coordinate);
                }

            }
            else{
                possible_moves.push_back(board[piece_line - 2][piece_column + 1].coordinate);
            }
        }
        //To the left
        if(piece_column >= 1){
            if(board[piece_line - 2][piece_column - 1].pPiece != nullptr)
            {
                if(board[piece_line - 2][piece_column - 1].pPiece->getColor() == color)
                {
                    possible_moves.push_back(board[piece_line - 2][piece_column - 1].coordinate);
                }

            }
            else{
                possible_moves.push_back(board[piece_line - 2][piece_column - 1].coordinate);
            }
        }
    }

    //Moving to the right
    if(piece_column <= 5){
        //And then up
        if(piece_line <= 6){
            if(board[piece_line + 1][piece_column + 2].pPiece != nullptr)
            {
                if(board[piece_line + 1][piece_column + 2].pPiece->getColor() == color)
                {
                    possible_moves.push_back(board[piece_line + 1][piece_column + 2].coordinate);
                }

            }
            else{
                possible_moves.push_back(board[piece_line + 1][piece_column + 2].coordinate);
            }
        }
        //And then down
        if(piece_line >= 1) {
            if(board[piece_line - 1][piece_column + 2].pPiece != nullptr)
            {
                if(board[piece_line - 1][piece_column + 2].pPiece->getColor() == color)
                {
                    possible_moves.push_back(board[piece_line - 1][piece_column + 2].coordinate);
                }

            }
            else{
                possible_moves.push_back(board[piece_line - 1][piece_column + 2].coordinate);
            }
        }
    }

    //Moving to the left
    if(piece_column >= 2){
        //And then up
        if(piece_line <= 6){
            if(board[piece_line + 1][piece_column - 2].pPiece != nullptr){
                if(board[piece_line + 1][piece_column - 2].pPiece->getColor() == color)
                {
                    possible_moves.push_back(board[piece_line + 1][piece_column - 2].coordinate);
                }
            }
            else{
                possible_moves.push_back(board[piece_line + 1][piece_column - 2].coordinate);
            }
        }
        //And then down
        if(piece_line >= 1) {
            if(board[piece_line - 1][piece_column - 2].pPiece != nullptr)
            {
                if(board[piece_line - 1][piece_column - 2].pPiece->getColor() == color){
                    possible_moves.push_back(board[piece_line - 1][piece_column - 2].coordinate);
                }

            }
            else{
                possible_moves.push_back(board[piece_line - 1][piece_column - 2].coordinate);
            }
        }
    }

    return possible_moves;
}
