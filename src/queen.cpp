#include "queen.h"


bool Queen::isValidMove(std::string final_position, const Square game_board[][8]){
    return true; //TEMP
};

std::vector<std::string> Queen::getPossibleMoves(const Square board[][8]){

    int piece_column = (int) getCurrentPosition()[0] - 'a';
    int piece_line = (int) getCurrentPosition()[1] - '1';

    std::vector<std::string> possible_moves;

    // ---------- Diagonal moves ----------

    //Upper right
    for(int i = piece_line + 1, j = piece_column + 1; i < 8; i++, j++){
        if(board[i][j].pPiece != nullptr)
        {
            if(board[i][j].pPiece->getColor() == color)
                break;

            possible_moves.push_back(board[i][j].coordinate);
            break;
        }
        else{
            possible_moves.push_back(board[i][j].coordinate);
        }
    }

    //Lower right
    for(int i = piece_line - 1, j = piece_column + 1; i >= 0; i--, j++){
        if(board[i][j].pPiece != nullptr)
        {
            if(board[i][j].pPiece->getColor() == color)
                break;

            possible_moves.push_back(board[i][j].coordinate);
            break;
        }
        else{
            possible_moves.push_back(board[i][j].coordinate);
        }
    }

    //Upper left
    for(int i = piece_line + 1, j = piece_column - 1; i < 8; i++, j--){
        if(board[i][j].pPiece != nullptr)
        {
            if(board[i][j].pPiece->getColor() == color)
                break;

            possible_moves.push_back(board[i][j].coordinate);
            break;
        }
        else{
            possible_moves.push_back(board[i][j].coordinate);
        }
    }

    //Lower left
    for(int i = piece_line - 1, j = piece_column - 1; i < 8; i--, j--){
        if(board[i][j].pPiece != nullptr)
        {
            if(board[i][j].pPiece->getColor() == color)
                break;

            possible_moves.push_back(board[i][j].coordinate);
            break;
        }
        else{
            possible_moves.push_back(board[i][j].coordinate);
        }
    }


    // ---------- Vertical and horizontal moves ----------


    //Moving up
    for(int i = piece_line + 1; i < 8; i++){
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


    //Moving down

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
