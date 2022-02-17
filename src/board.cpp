#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
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

    //Printing the letters above the board
    std::cout << "                                                 " << std::endl;
    std::cout << "   a     b     c     d     e     f     g     h   " << std::endl;
    std::cout << "                                                 " << std::endl;


    //Printing the square pattern and pieces on the board
/*
        -- each column of the board is composed of 6 rectangles (alternating dark and light color)
            - light: ASCII table character - (char) 219 - white rectangle
            - dark: " " character (cmd�s background color)
        -- character's width = (character's height)/2 -> square dimension = 6 x 3 characters
        -- each sub line is composed of 48 (6 characters x 8 columns) rectangles
        -- each rank (board line) is composed of 3 sub lines
*/

    for(int line_coordinate=7; line_coordinate>=0; line_coordinate--){
        for(int subline=0; subline<3; subline++){
            if(line_coordinate%2 == 0){ //odd ranks on the chess board begin with black squares
                for(int column_coordinate=0; column_coordinate<8; column_coordinate++){
                    if(subline == 1){
                        if(board[line_coordinate][column_coordinate].pPiece != nullptr){
                            if(column_coordinate %2 ==0 ){
                                printBlackSquares(true, board[line_coordinate][column_coordinate].symbol, board[line_coordinate][column_coordinate].pPiece->getColor());
                            }
                            else{
                                printWhiteSquares(true, board[line_coordinate][column_coordinate].symbol, board[line_coordinate][column_coordinate].pPiece->getColor());
                            }
                        }
                        else{
                            if(column_coordinate %2 ==0 ){
                                printBlackSquares(false);
                            }
                            else{
                                printWhiteSquares(false);
                            }
                        }
                    }

                    if(subline != 1){
                        if(column_coordinate %2 ==0 ){
                            printBlackSquares(false);
                        }
                        else{
                            printWhiteSquares(false);
                        }
                    }
                }

                std::cout << std::endl;
            }
            if(line_coordinate%2 != 0){ //even ranks on the chess board begin with white squares
                for(int column_coordinate=0; column_coordinate<8; column_coordinate++){
                        if(subline == 1){
                            if(board[line_coordinate][column_coordinate].pPiece != nullptr){
                                if(column_coordinate %2 ==0 ){
                                    printWhiteSquares(true, board[line_coordinate][column_coordinate].symbol, board[line_coordinate][column_coordinate].pPiece->getColor());
                                }
                                else{
                                    printBlackSquares(true, board[line_coordinate][column_coordinate].symbol, board[line_coordinate][column_coordinate].pPiece->getColor());
                                }
                            }
                            else{
                                if(column_coordinate %2 ==0 ){
                                    printWhiteSquares(false);
                                }
                                else{
                                    printBlackSquares(false);
                                }
                            }
                        }


                        if(subline != 1){
                            if(column_coordinate %2 ==0 ){
                                printWhiteSquares(false);
                            }
                            else{
                                printBlackSquares(false);
                            }
                        }
                    }

                std::cout << std::endl;
            }
        }
    }
}


bool Board::isMove(const std::string& player_move)
{
    if(player_move.size() != 5) { std::cout << "Invalid move(1)\n"; return false; }

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


    if(
        (player_move[0] < 'a' || player_move[0] > 'h') ||
        (player_move[1] < '1' || player_move[1] > '8') ||
        (player_move[3] < 'a' || player_move[3] > 'h') ||
        (player_move[4] < '1' || player_move[4] > '8') ||
        (player_move[2] != ' ')
    ) { std::cout << "Invalid move(2)\n"; return false; }


    if(board[i1][j1].pPiece == nullptr){
        std::cout << "There is no " << " piece on " << initial_position << std::endl;
        return false;
    }
    else if(whos_turn != board[i1][j1].pPiece->getColor()){
        std::cout << "There is no " << whos_turn << " piece on " << initial_position << std::endl;
        return false;
    }


    if(putOwnKingInCheck(initial_position, final_position)){
        std::cout << "You cannot put your own king in check!\n";
        return false;
    }

    //TEMP
    for(auto& possible_move : board[i1][j1].pPiece->getPossibleMoves(board))
            std::cout << possible_move;
    std::cout << std::endl;

    if(board[i1][j1].pPiece->getSymbol() == 'K' && i1==i2){
        if(j2 == j1+2){
            if(!canShortCastle()) return false;

            return true;
         }
        if(j2 == j1-2){
            if(!canLongCastle()) return false;

            return true;
        }
    }

    for(auto& possible_move : board[i1][j1].pPiece->getPossibleMoves(board))
        if(possible_move == board[i2][j2].coordinate)
            return true;

    std::cout << "Invalid move!" << std::endl;

    return false;
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

    if(board[i1][j1].pPiece->getSymbol() == 'K' && (j2 == j1+2 || j2 == j1-2)){
        if(j2 == j1+2){
            if(whos_turn == "white"){
                //moves the king
                board[i2][j2].pPiece = std::move(board[i1][j1].pPiece);
                board[i2][j2].pPiece->setCurrentPosition(final_position);
                board[i2][j2].symbol = board[i2][j2].pPiece->getSymbol();
                board[i1][j1].symbol = ' ';

                //moves the rook
                board[0][5].pPiece = std::move(board[0][7].pPiece);
                board[0][5].pPiece->setCurrentPosition("f1");
                board[0][5].symbol = 'R';
                board[0][7].symbol = ' ';

            }

            if(whos_turn == "black"){
                //moves the king
                board[i2][j2].pPiece = std::move(board[i1][j1].pPiece);
                board[i2][j2].pPiece->setCurrentPosition(final_position);
                board[i2][j2].symbol = board[i2][j2].pPiece->getSymbol();
                board[i1][j1].symbol = ' ';

                //moves the rook
                board[7][5].pPiece = std::move(board[7][7].pPiece);
                board[7][5].pPiece->setCurrentPosition("f8");
                board[7][5].symbol = 'R';
                board[7][7].symbol = ' ';
            }
         }
        if(j2 == j1-2){
            if(whos_turn == "white"){
                //moves the king
                board[i2][j2].pPiece = std::move(board[i1][j1].pPiece);
                board[i2][j2].pPiece->setCurrentPosition(final_position);
                board[i2][j2].symbol = board[i2][j2].pPiece->getSymbol();
                board[i1][j1].symbol = ' ';

                //moves the rook
                board[0][3].pPiece = std::move(board[0][0].pPiece);
                board[0][3].pPiece->setCurrentPosition("d1");
                board[0][3].symbol = 'R';
                board[0][0].symbol = ' ';
            }

            if(whos_turn == "black"){
                //moves the king
                board[i2][j2].pPiece = std::move(board[i1][j1].pPiece);
                board[i2][j2].pPiece->setCurrentPosition(final_position);
                board[i2][j2].symbol = board[i2][j2].pPiece->getSymbol();
                board[i1][j1].symbol = ' ';

                //moves the rook
                board[7][3].pPiece = std::move(board[7][0].pPiece);
                board[7][3].pPiece->setCurrentPosition("d8");
                board[7][3].symbol = 'R';
                board[7][0].symbol = ' ';
            }
        }
    }
    else{

        if(board[i1][j1].pPiece->getSymbol() == 'K'){
            auto& king = dynamic_cast<King&>(*board[i1][j1].pPiece);
            if(!king.getHasMoved())
                king.setHasMovedToTrue();
        }

        if(board[i1][j1].pPiece->getSymbol() == 'R'){
            auto& rook = dynamic_cast<Rook&>(*board[i1][j1].pPiece);
            if(!rook.getHasMoved())
                rook.setHasMovedToTrue();
        }

        board[i2][j2].pPiece = std::move(board[i1][j1].pPiece);
        board[i2][j2].pPiece->setCurrentPosition(final_position);
        board[i2][j2].symbol = board[i2][j2].pPiece->getSymbol();
        board[i1][j1].symbol = ' ';

    }

}

bool Board::isKingInCheck()
{
    return !getThreateningPiecesPosition().empty();
}

bool Board::putOwnKingInCheck(const std::string& initial_position, const std::string& final_position){

    // ----------- check if the player is trying to put his own king in check -----------

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

    //tries to make the move
    std::unique_ptr<Piece> pAuxiliar = nullptr;
    if(board[i2][j2].pPiece != nullptr){
        pAuxiliar = std::move(board[i2][j2].pPiece);
    }

    board[i2][j2].pPiece = std::move(board[i1][j1].pPiece);
    board[i2][j2].pPiece->setCurrentPosition(final_position);
    board[i2][j2].symbol = board[i2][j2].pPiece->getSymbol();
    board[i1][j1].symbol = ' ';

    if(isKingInCheck()){
        //undo the move
        board[i1][j1].pPiece = std::move(board[i2][j2].pPiece);
        board[i1][j1].pPiece->setCurrentPosition(initial_position);
        board[i1][j1].symbol = board[i1][j1].pPiece->getSymbol();

        if(pAuxiliar != nullptr){
            board[i2][j2].pPiece = std::move(pAuxiliar);
            board[i2][j2].pPiece->setCurrentPosition(final_position);
            board[i2][j2].symbol = board[i2][j2].pPiece->getSymbol();
        }
        else{
            board[i2][j2].symbol = ' ';
        }

        return true;
    }
    else{

        //undo the move
        board[i1][j1].pPiece = std::move(board[i2][j2].pPiece);
        board[i1][j1].pPiece->setCurrentPosition(initial_position);
        board[i1][j1].symbol = board[i1][j1].pPiece->getSymbol();

        if(pAuxiliar != nullptr){
            board[i2][j2].pPiece = std::move(pAuxiliar);
            board[i2][j2].pPiece->setCurrentPosition(final_position);
            board[i2][j2].symbol = board[i2][j2].pPiece->getSymbol();
        }
        else{
            board[i2][j2].symbol = ' ';
        }

        return false;
    }

}

bool Board::isCheckmate(){

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

    if(getThreateningPiecesPosition().size() == 1){
        std::string threatening_piece_position = getThreateningPiecesPosition()[0];

        int i1, j1;
        bool found_coordinate = false;
        for(i1=0; i1<8; i1++){
            for(j1=0; j1<8; j1++){
                if(threatening_piece_position == board[i1][j1].coordinate){
                    found_coordinate = true;
                    break;
                }
            }
            if(found_coordinate) break;
        }

        //Check if there's any piece that could stop the check by capturing the opponent's piece
        if(board[i][j].pPiece->getPossibleMoves(board).empty()){
            for(auto& line : board)
                for(auto& square : line)
                    if(square.pPiece != nullptr)
                        if(square.pPiece->getColor() == whos_turn)
                            if(!square.pPiece->getPossibleMoves(board).empty())
                                for(auto& possible_move : square.pPiece->getPossibleMoves(board))
                                    if(possible_move == threatening_piece_position)
                                        if(!putOwnKingInCheck(square.pPiece->getCurrentPosition(), threatening_piece_position))
                                            return false;

        }
        else{
            for(auto& possible_move : board[i][j].pPiece->getPossibleMoves(board))
                if(!putOwnKingInCheck(board[i][j].pPiece->getCurrentPosition(), possible_move))
                    return false;

            for(auto& line : board)
                for(auto& square : line)
                    if(square.pPiece != nullptr)
                        if(square.pPiece->getColor() == whos_turn)
                            if(!square.pPiece->getPossibleMoves(board).empty())
                                for(auto& possible_move : square.pPiece->getPossibleMoves(board))
                                    if(possible_move == threatening_piece_position)
                                        if(!putOwnKingInCheck(square.pPiece->getCurrentPosition(), threatening_piece_position))
                                            return false;


            //Check if there's any piece that could stop the check by blocking the check
            for(auto& line : board)
                for(auto& square : line)
                    if(square.pPiece != nullptr)
                        if(square.pPiece->getColor() == whos_turn)
                            if(!square.pPiece->getPossibleMoves(board).empty())
                                for(auto& possible_move : square.pPiece->getPossibleMoves(board))
                                    for(auto& threatening_piece_move : board[i1][j1].pPiece->getPossibleMoves(board))
                                        if(possible_move == threatening_piece_move)
                                            if(!putOwnKingInCheck(square.pPiece->getCurrentPosition(), possible_move))
                                                return false;
        }

    }
    else{

        for(auto& possible_move : board[i][j].pPiece->getPossibleMoves(board))
            if(!putOwnKingInCheck(board[i][j].pPiece->getCurrentPosition(), possible_move))
                return false;
    }


    return true;

}

std::vector<std::string> Board::getThreateningPiecesPosition(){

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

    std::vector<std::string> threatening_pieces_position;

    for(int i2 = 0; i2 < 8; i2++){
        for(int j2 = 0; j2 < 8; j2++){
            if(board[i2][j2].pPiece != nullptr){
                if(board[i2][j2].pPiece->getColor() != whos_turn){
                    if(!board[i2][j2].pPiece->getPossibleMoves(board).empty()){
                        for(auto& possible_move : board[i2][j2].pPiece->getPossibleMoves(board)){
                            if(possible_move == board[i][j].pPiece->getCurrentPosition()){
                                threatening_pieces_position.push_back(board[i2][j2].pPiece->getCurrentPosition());
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    return threatening_pieces_position;
}

std::string Board::getWhosTurn() const { return whos_turn; }

bool Board::isDraw(){
    bool is_stalemate = true;
    bool only_kings = true;

    //if a stalemate happens
    for(auto& line : board)
        for(auto& square : line)
            if(square.pPiece != nullptr)
                if(square.pPiece->getColor() == whos_turn)
                    if(!square.pPiece->getPossibleMoves(board).empty())
                        is_stalemate = false;

    if(is_stalemate)
        if(!isKingInCheck())
            return is_stalemate;


    //if there are only the kings left on the board
    for(auto& line : board)
        for(auto& square : line)
            if(square.pPiece != nullptr)
                if(square.pPiece->getSymbol() != 'K')
                        only_kings = false;

    return only_kings;

}

bool Board::canShortCastle(){

    if(isKingInCheck()) return false;

    if(whos_turn == "white"){
        if(board[0][5].pPiece != nullptr || board[0][6].pPiece != nullptr) return false;

        if(
            board[0][4].pPiece->getSymbol() != 'K' ||
            board[0][4].pPiece->getColor() != "white" ||
            board[0][7].pPiece->getSymbol() != 'R' ||
            board[0][7].pPiece->getColor() != "white"
           ) return false;

        auto& king = dynamic_cast<King&>(*board[0][4].pPiece);        auto& rook = dynamic_cast<Rook&>(*board[0][7].pPiece);

        if(king.getHasMoved()) return false;
        if(rook.getHasMoved()) return false;

        for(auto& line : board)
            for(auto& square : line)
                if(square.pPiece != nullptr)
                    if(square.pPiece->getColor() == "black")
                        for(auto& possible_move : square.pPiece->getPossibleMoves(board))
                            if(possible_move == board[0][5].coordinate || possible_move == board[0][6].coordinate)
                                return false;

        return true;
    }

    //Then it's blacks' turn

    if(board[7][5].pPiece != nullptr || board[7][6].pPiece != nullptr) return false;

    if(
        board[7][4].pPiece->getSymbol() != 'K' ||
        board[7][4].pPiece->getColor() != "black" ||
        board[7][7].pPiece->getSymbol() != 'R' ||
        board[7][7].pPiece->getColor() != "black"
       ) return false;

    auto& king = dynamic_cast<King&>(*board[7][4].pPiece);
    auto& rook = dynamic_cast<Rook&>(*board[7][7].pPiece);

    if(king.getHasMoved()) return false;
    if(rook.getHasMoved()) return false;

    for(auto& line : board)
        for(auto& square : line)
            if(square.pPiece != nullptr)
                if(square.pPiece->getColor() == "white")
                    for(auto& possible_move : square.pPiece->getPossibleMoves(board))
                        if(possible_move == board[7][5].coordinate || possible_move == board[7][6].coordinate)
                            return false;

    return true;

}

bool Board::canLongCastle(){

    if(isKingInCheck()) return false;

    if(whos_turn == "white"){
        if(board[0][1].pPiece != nullptr || board[0][2].pPiece != nullptr || board[0][3].pPiece != nullptr) return false;

        if(
            board[0][4].pPiece->getSymbol() != 'K' ||
            board[0][4].pPiece->getColor() != "white" ||
            board[0][0].pPiece->getSymbol() != 'R' ||
            board[0][0].pPiece->getColor() != "white"
           ) return false;

        auto& king = dynamic_cast<King&>(*board[0][4].pPiece);
        auto& rook = dynamic_cast<Rook&>(*board[0][0].pPiece);

        if(king.getHasMoved()) return false;
        if(rook.getHasMoved()) return false;

        for(auto& line : board)
            for(auto& square : line)
                if(square.pPiece != nullptr)
                    if(square.pPiece->getColor() == "black")
                        for(auto& possible_move : square.pPiece->getPossibleMoves(board))
                            if(possible_move == board[0][2].coordinate || possible_move == board[0][3].coordinate)
                                return false;

        return true;
    }

    //Then it's blacks' turn

    if(board[7][1].pPiece != nullptr || board[7][2].pPiece != nullptr || board[7][3].pPiece != nullptr) return false;

    if(
        board[7][4].pPiece->getSymbol() != 'K' ||
        board[7][4].pPiece->getColor() != "black" ||
        board[7][0].pPiece->getSymbol() != 'R' ||
        board[7][0].pPiece->getColor() != "black"
       ) return false;

    auto& king = dynamic_cast<King&>(*board[7][4].pPiece);
    auto& rook = dynamic_cast<Rook&>(*board[7][0].pPiece);

    if(king.getHasMoved()) return false;
    if(rook.getHasMoved()) return false;

    for(auto& line : board)
        for(auto& square : line)
            if(square.pPiece != nullptr)
                if(square.pPiece->getColor() == "white")
                    for(auto& possible_move : square.pPiece->getPossibleMoves(board))
                        if(possible_move == board[7][2].coordinate || possible_move == board[7][3].coordinate)
                            return false;

    return true;

}

//Function used to print the black squares
void Board::printBlackSquares(bool isTherePiece, char symbol, std::string piece_color){

    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    if(isTherePiece){
        for(int i=0; i<6; i++){
            if(i == 2){
                if(piece_color == "black"){
                    SetConsoleTextAttribute(h,24); //Function used to change the color of black pieces
                    std::cout << symbol;
                    SetConsoleTextAttribute(h,264);
                }
                else{
                    std::cout << symbol;
                }
            }
            else{
                std::cout << " ";
            }
        }
    }
    else{
       for(int i=0; i<6; i++){
            std::cout << " ";
        }
    }
}

//Function used to print the white squares
void Board::printWhiteSquares(bool isTherePiece, char symbol, std::string piece_color){

    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

    if(isTherePiece){
        for(int i=0; i<6; i++){
            if(i == 2){
                if(piece_color == "black"){
                    SetConsoleTextAttribute(h,24); //Function used to change the color of black pieces
                    std::cout << symbol;
                    SetConsoleTextAttribute(h,264);
                }
                else{
                    std::cout << symbol;
                }
            }
            else{
                SetConsoleTextAttribute(h,24); //Function used to change the color of white rectangles
                std::cout << (char) 219;
                SetConsoleTextAttribute(h, 264);
            }
        }
    }
    else{
       for(int i=0; i<6; i++){
            SetConsoleTextAttribute(h, 24);
            std::cout << (char) 219;
            SetConsoleTextAttribute(h, 264);
        }
    }
}

