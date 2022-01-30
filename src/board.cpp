#include <iostream>
#include <string>
#include "piece.h"
#include "pawn.h"
#include "board.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <memory>
#include <vector>

//Initializes the Board
Board::Board(){
    for(int line=0; line<8; line++){
        for(int column=0; column<8; column++){
            board[line][column].coordinate.push_back('a' + column);
            board[line][column].coordinate.push_back('1' + line);


            //White Pieces
            if(line == 1)
            {
                board[line][column].pPiece = std::make_unique<Pawn>("white");
                board[line][column].pPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].pPiece->getSymbol();
            }

            if(line==0  && (column == 0 || column == 7))
            {

                board[line][column].pPiece = std::make_unique<Rook>("white");
                board[line][column].pPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].pPiece->getSymbol();
            }

            if(line == 0  && (column == 1 || column == 6))
            {
                board[line][column].pPiece = std::make_unique<Knight>("white");
                board[line][column].pPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].pPiece->getSymbol();
            }

            if(line == 0  && (column == 2 || column == 5))
            {
                board[line][column].pPiece = std::make_unique<Bishop>("white");
                board[line][column].pPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].pPiece->getSymbol();
            }

            if(line == 0  && column == 3)
            {
                board[line][column].pPiece = std::make_unique<Queen>("white");
                board[line][column].pPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].pPiece->getSymbol();
            }
            if(line == 0  && column == 4)
            {
                board[line][column].pPiece = std::make_unique<King>("white");
                board[line][column].pPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].pPiece->getSymbol();
            }

            //Black Pieces
            if(line == 6)
            {
                board[line][column].pPiece = std::make_unique<Pawn>("black");
                board[line][column].pPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].pPiece->getSymbol();
            }

            if(line == 7  && (column == 0 || column == 7))
            {

                board[line][column].pPiece = std::make_unique<Rook>("black");
                board[line][column].pPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].pPiece->getSymbol();
            }

            if(line == 7  && (column == 1 || column == 6))
            {
                board[line][column].pPiece = std::make_unique<Knight>("black");
                board[line][column].pPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].pPiece->getSymbol();
            }

            if(line == 7  && (column == 2 || column == 5))
            {
                board[line][column].pPiece = std::make_unique<Bishop>("black");
                board[line][column].pPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].pPiece->getSymbol();
            }

            if(line == 7  && column == 3)
            {
                board[line][column].pPiece = std::make_unique<Queen>("black");
                board[line][column].pPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].pPiece->getSymbol();
            }

            if(line == 7  && column == 4)
            {
                board[line][column].pPiece = std::make_unique<King>("black");
                board[line][column].pPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].pPiece->getSymbol();
            }

        }
    }
}

void Board::display()
{
    for(int i=7; i>=0; i--){
        for(int j=0; j<8; j++){
            std::cout << board[i][j].symbol;
        }

        std::cout << "\n";
    }

}

bool Board::isMove(const std::string& player_move)
{

    if(player_move.size() != 5) { std::cout << "Invalid move(1)\n"; return false; }

    if(
        (player_move[0] < 'a' || player_move[0] > 'h') ||
        (player_move[1] < '1' || player_move[1] > '8') ||
        (player_move[3] < 'a' || player_move[3] > 'h') ||
        (player_move[4] < '1' || player_move[4] > '8') ||
        (player_move[2] != ' ')
    ) { std::cout << "Invalid move(2)\n"; return false; }

    std::string initial_position = player_move.substr(0,2);

    int i, j;
    bool found_coordinate = false;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            if(initial_position == board[i][j].coordinate){
                found_coordinate = true;
                break;
            }
        }
        if(found_coordinate) break;
    }


    if(board[i][j].pPiece == nullptr){
        std::cout << "There is no " << " piece on " << initial_position << std::endl;
        return false;
    }
    else if(whos_turn != board[i][j].pPiece->getColor()){
        std::cout << "There is no " << whos_turn << " piece on " << initial_position << std::endl;
        return false;
    }

    return true;
}

void Board::switchTurn() { whos_turn = (whos_turn == "white"? "black" : "white"); }

void Board::movePiece(const std::string& player_move){
    std::string initial_position = player_move.substr(0,2);
    std::string final_position = player_move.substr(3,2);

    int i1, j1;
    bool found_coordinate = false;
    for(i1=0; i1<8; i1++){
        for(j1=0; j1<8; j1++){
            if(initial_position == board[i1][j1].coordinate){
                found_coordinate = true;
                break;
            }
        }
        if(found_coordinate) break;
    }

    int i2, j2;
    found_coordinate = false;
    for(i2=0; i2<8; i2++){
        for(j2=0; j2<8; j2++){
            if(final_position == board[i2][j2].coordinate){
                found_coordinate = true;
                break;
            }
        }
        if(found_coordinate) break;
    }

    board[i2][j2].pPiece = std::move(board[i1][j1].pPiece);
    board[i2][j2].pPiece->setCurrentPosition(final_position);
    board[i2][j2].symbol = board[i2][j2].pPiece->getSymbol();
    board[i1][j1].symbol = ' ';


}

bool Board::isKingInCheck()
{
    //Find the king's position
    int i, j;
    bool found_coordinate = false;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            if(board[i][j].pPiece != nullptr)
            {
                if(board[i][j].pPiece->getColor() == whos_turn && board[i][j].pPiece->getSymbol() == 'K'){
                    found_coordinate = true;
                    break;
                }
            }
        }
        if(found_coordinate) break;
    }

    //Now board[i][j].pPiece->getCurrentPosition() represents the king's square


    //Verify if there's any opponent piece threatening the king's square
    for(auto& line : board)
        for(auto& square : line)
            if(square.pPiece != nullptr)
                if(square.pPiece->getColor() != whos_turn)
                    if(!square.pPiece->getPossibleMoves(board).empty())
                        for(auto& possible_move : square.pPiece->getPossibleMoves(board))
                            if(possible_move == board[i][j].pPiece->getCurrentPosition())
                                return true;



    return false;
}
