#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "board.h"
#include "helper_functions.h"

int main()
{
    int option;
    do
    {

        displayMenu();
        std::cin >> option;
        cleanBuffer();

        if(option < 1 || option > 3)
        {
            std::cout << "Invalid option! Please enter a number between 1 and 3\n";
            continue;
        }

        switch(option)
        {
            case 1:
            {
                Board game_board;

                while(true)
                {

                    game_board.display();

                    if(game_board.isKingInCheck()){
                        if(game_board.isCheckmate()){
                            std::cout << "Checkmate! "
                                        << game_board.getWhosTurn()
                                        << " lost!"
                                        << " Type any key to go back to main menu..."
                                        << std::endl;
                            char back_to_menu;
                            std::cin >> back_to_menu;
                            break;
                        }
                    }

                    std::string player_move;
                    do{
                        std::cout << "Please enter a valid move: ";
                        std::getline(std::cin, player_move);
                    } while(game_board.isMove(player_move) == false && player_move != "q");
                    if(player_move == "q") break;

                    game_board.movePiece(player_move);

                    game_board.switchTurn();


                }
            }
                break;
            case 2:
            {
                std::string file_path = "games/";
                std::string file_name;
                std::string player_move;
                std::ifstream game_file;
                char option;

                std::cout << "Enter the file name (without extension) to open the game: ";
                std::getline(std::cin, file_name);

                file_path.append(file_name);
                file_path.append(".txt");

                game_file.open(file_path);
                if(game_file.is_open()){
                    Board game_board;

                    while(std::getline(game_file, player_move)){
                        game_board.display();

                        if(player_move == "1-0"){
                            std::cout << "White won! Enter any key to go back to main menu: ";
                            std::cin >> option;
                            game_file.close();
                            break;
                        }
                        else if(player_move == "0-1"){
                            std::cout << "Black won! Enter any key to go back to main menu: ";
                            std::cin >> option;
                            game_file.close();
                            break;
                        }
                        else if(player_move == "0.5-0.5"){
                            char option;
                            std::cout << "Draw! Enter any key to go back to main menu: ";
                            std::cin >> option;
                            game_file.close();
                            break;
                        }

                        std::cout << "Type 'p' to proceed or any other key to go back to main menu: ";
                        std::cin >> option;
                        if(option != 'p'){
                            game_file.close();
                            break;
                        }
                        if(!game_board.isMove(player_move)){
                            std::cout << "An invalid move was found! Game cannot be reproduced!\n";
                            std::cout << "Enter any key to go back to main menu: ";
                            std::cin >> option;
                            game_file.close();
                            break;
                        }
                        game_board.movePiece(player_move);
                        game_board.switchTurn();

                    }

                    game_file.close();
                    break;
                }
                else{
                    std::cout << "File not found!" << std::endl;
                    std::cout << "Enter any key to go back to main menu: ";
                    std::cin >> option;
                    break;
                }

            }
                break;
            default:
                break;
        }

    }while(option != 3);

    return 0;
}
