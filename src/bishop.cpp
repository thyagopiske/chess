#include <vector>
#include <algorithm>
#include "bishop.h"

bool Bishop::isValidMove(std::string final_position, const Square board[][8]){

    std::vector<std::string> possible_moves = getPossibleMoves(board);

    if(std::find(possible_moves.begin(), possible_moves.end(), final_position) != possible_moves.end())
        return true;


    return false;
};

std::vector<std::string> Bishop::getPossibleMoves(const Square board[][8]){

    int piece_column = (int) getCurrentPosition()[0] - 'a';

    int piece_line = (int) getCurrentPosition()[1] - '1';

    std::vector<std::string> possible_moves;


    if(piece_line < 7)
    {
        //Upper right
        if(piece_column < 7){
            for(int i = piece_line + 1, j = piece_column + 1; (i < 8 && j < 8); i++, j++){
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
        }

       //Upper left
        if(piece_column > 0){
            for(int i = piece_line + 1, j = piece_column - 1; (i < 8 && j >= 0); i++, j--){
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
        }

    }

    if(piece_line > 0)
    {
        //Lower right
        if(piece_column < 7){
            for(int i = piece_line - 1, j = piece_column + 1; (i >= 0 && j < 8); i--, j++){
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
        }

        //Lower left
        if(piece_column > 0){
            for(int i = piece_line - 1, j = piece_column - 1; (i >= 0 && j >= 0); i--, j--){
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
        }

    }


    return possible_moves;
}
