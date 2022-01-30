#include "king.h"


bool King::isValidMove(std::string final_position, const Square game_board[][8]){
    return true; //TEMP
};

std::vector<std::string> King::getPossibleMoves(const Square board[][8]){

    int piece_column = (int) getCurrentPosition()[0] - 'a';
    int piece_line = (int) getCurrentPosition()[1] - '1';

    std::vector<std::string> possible_moves;


    if(piece_line < 7)
    {
        //Moving up
        if(board[piece_line + 1][piece_column].pPiece != nullptr){
            if(board[piece_line + 1][piece_column].pPiece->getColor() != color)
                possible_moves.push_back(board[piece_line + 1][piece_column].coordinate);
        }
        else{
            possible_moves.push_back(board[piece_line + 1][piece_column].coordinate);
        }


        //Moving up right
        if(piece_column < 7)
        {
            if(board[piece_line + 1][piece_column + 1].pPiece != nullptr){
                if(board[piece_line + 1][piece_column + 1].pPiece->getColor() != color)
                    possible_moves.push_back(board[piece_line + 1][piece_column + 1].coordinate);
            }
            else{
                possible_moves.push_back(board[piece_line + 1][piece_column + 1].coordinate);
            }

        }


        //Moving up left
        if(piece_column > 0)
        {
            if(board[piece_line + 1][piece_column - 1].pPiece != nullptr){
                if(board[piece_line + 1][piece_column - 1].pPiece->getColor() != color)
                    possible_moves.push_back(board[piece_line + 1][piece_column - 1].coordinate);
            }
            else{
                possible_moves.push_back(board[piece_line + 1][piece_column - 1].coordinate);
            }
        }
    }

    if(piece_line > 0)
    {
        //Moving down
        if(board[piece_line - 1][piece_column].pPiece != nullptr){
            if(board[piece_line - 1][piece_column].pPiece->getColor() != color)
                possible_moves.push_back(board[piece_line - 1][piece_column].coordinate);
        }
        else{
            possible_moves.push_back(board[piece_line - 1][piece_column].coordinate);
        }

        //Moving down right
        if(piece_column < 7)
        {
            if(board[piece_line - 1][piece_column + 1].pPiece != nullptr){
                if(board[piece_line - 1][piece_column + 1].pPiece->getColor() != color)
                    possible_moves.push_back(board[piece_line - 1][piece_column + 1].coordinate);
            }
            else{
                possible_moves.push_back(board[piece_line - 1][piece_column + 1].coordinate);
            }
        }

        //Moving down left
        if(piece_column > 0)
        {
            if(board[piece_line - 1][piece_column - 1].pPiece != nullptr){
                if(board[piece_line - 1][piece_column - 1].pPiece->getColor() != color)
                    possible_moves.push_back(board[piece_line - 1][piece_column - 1].coordinate);
            }
            else{
                possible_moves.push_back(board[piece_line - 1][piece_column - 1].coordinate);
            }
        }
    }

    //Moving right
    if(piece_column < 7)
    {
        if(board[piece_line][piece_column + 1].pPiece != nullptr){
            if(board[piece_line][piece_column + 1].pPiece->getColor() != color)
                possible_moves.push_back(board[piece_line][piece_column + 1].coordinate);
        }
        else{
            possible_moves.push_back(board[piece_line][piece_column + 1].coordinate);
        }
    }

    //Moving left
    if(piece_column > 0)
    {
        if(board[piece_line][piece_column - 1].pPiece != nullptr){
            if(board[piece_line][piece_column - 1].pPiece->getColor() != color)
                possible_moves.push_back(board[piece_line][piece_column - 1].coordinate);
        }
        else{
            possible_moves.push_back(board[piece_line][piece_column - 1].coordinate);
        }
    }


    return possible_moves;
}
