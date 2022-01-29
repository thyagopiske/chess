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

//Initializes the Board
Board::Board(){
    for(int line=0; line<8; line++){
        for(int column=0; column<8; column++){
            board[line][column].coordinate.push_back('a' + column);
            board[line][column].coordinate.push_back('1' + line);


            //White Pieces
            if(line == 1)
            {
                board[line][column].currentPiece = std::make_unique<Pawn>("white");
                board[line][column].currentPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].currentPiece->getSymbol();
            }

            if(line==0  && (column == 0 || column == 7))
            {

                board[line][column].currentPiece = std::make_unique<Rook>("white");
                board[line][column].currentPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].currentPiece->getSymbol();
            }

            if(line == 0  && (column == 1 || column == 6))
            {
                board[line][column].currentPiece = std::make_unique<Knight>("white");
                board[line][column].currentPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].currentPiece->getSymbol();
            }

            if(line == 0  && (column == 2 || column == 5))
            {
                board[line][column].currentPiece = std::make_unique<Bishop>("white");
                board[line][column].currentPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].currentPiece->getSymbol();
            }

            if(line == 0  && column == 3)
            {
                board[line][column].currentPiece = std::make_unique<Queen>("white");
                board[line][column].currentPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].currentPiece->getSymbol();
            }
            if(line == 0  && column == 4)
            {
                board[line][column].currentPiece = std::make_unique<King>("white");
                board[line][column].currentPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].currentPiece->getSymbol();
            }

            //Black Pieces
            if(line == 6)
            {
                board[line][column].currentPiece = std::make_unique<Pawn>("black");
                board[line][column].currentPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].currentPiece->getSymbol();
            }

            if(line == 7  && (column == 0 || column == 7))
            {

                board[line][column].currentPiece = std::make_unique<Rook>("black");
                board[line][column].currentPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].currentPiece->getSymbol();
            }

            if(line == 7  && (column == 1 || column == 6))
            {
                board[line][column].currentPiece = std::make_unique<Knight>("black");
                board[line][column].currentPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].currentPiece->getSymbol();
            }

            if(line == 7  && (column == 2 || column == 5))
            {
                board[line][column].currentPiece = std::make_unique<Bishop>("black");
                board[line][column].currentPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].currentPiece->getSymbol();
            }

            if(line == 7  && column == 3)
            {
                board[line][column].currentPiece = std::make_unique<Queen>("black");
                board[line][column].currentPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].currentPiece->getSymbol();
            }

            if(line == 7  && column == 4)
            {
                board[line][column].currentPiece = std::make_unique<King>("black");
                board[line][column].currentPiece->setCurrentPosition(board[line][column].coordinate);
                board[line][column].symbol = board[line][column].currentPiece->getSymbol();
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

bool Board::isMove(const std::string& playerMove)
{

    if(playerMove.size() != 5) { std::cout << "Invalid move(1)\n"; return false; }

    if(
        (playerMove[0] < 'a' || playerMove[0] > 'h') ||
        (playerMove[1] < '1' || playerMove[1] > '8') ||
        (playerMove[3] < 'a' || playerMove[3] > 'h') ||
        (playerMove[4] < '1' || playerMove[4] > '8') ||
        (playerMove[2] != ' ')
    ) { std::cout << "Invalid move(2)\n"; return false; }

    std::string initialPiecePosition = playerMove.substr(0,2);

    int i, j;
    bool foundCoordinate = false;
    for(i=0; i<8; i++){
        for(j=0; j<8; j++){
            if(initialPiecePosition == board[i][j].coordinate){
                foundCoordinate = true;
                break;
            }
        }
        if(foundCoordinate) break;
    }


    if(board[i][j].currentPiece == nullptr){
        std::cout << "There is no " << " piece on " << initialPiecePosition << std::endl;
        return false;
    }
    else if(whosTurn != board[i][j].currentPiece->getColor()){
        std::cout << "There is no " << whosTurn << " piece on " << initialPiecePosition << std::endl;
        return false;
    }

    return true;
}

void Board::switchTurn() { whosTurn = (whosTurn == "white"? "black" : "white"); }
