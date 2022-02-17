#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "board.h"
#include "helper_functions.h"

int main()
{

    int menu_option;
    do
    {
        displayMenu();
        std::cin >> menu_option;
        cleanBuffer();

        if(menu_option < 1 || menu_option > 3)
        {
            std::cout << "Invalid option! Please enter a number between 1 and 3\n";
            continue;
        }

        switch(menu_option)
        {
            case 1:
            {
                Board game_board;
                std::vector<std::string> game_moves;

                while(true)
                {
                    system("cls||clear");
                    game_board.display();

                    if(game_board.isKingInCheck()){
                        if(game_board.isCheckmate()){
                            game_moves.push_back(game_board.getWhosTurn() == "white"? "0-1" : "1-0");
                            std::cout << "Checkmate! "
                                        << game_board.getWhosTurn()
                                        << " lost!"
                                        << " Type any key to go back to main menu...";
                            char back_to_menu;
                            std::cin >> back_to_menu;
                            break;
                        }
                    }

                    if(game_board.isDraw()){
                        game_moves.push_back("0.5-0.5");
                        std::cout << "Draw!\n"
                                    << " Type any key to go back to main menu...";
                        char back_to_menu;
                        std::cin >> back_to_menu;
                        break;
                    }

                    std::string player_move;
                    do{
                        std::cout << "Please enter a valid move: ";
                        std::getline(std::cin, player_move);
                    } while(player_move != "q" && game_board.isMove(player_move) == false);
                    if(player_move == "q") break;

                    game_board.movePiece(player_move);
                    game_moves.push_back(player_move);

                    game_board.switchTurn();
                }

                if(game_moves.empty())
                {
                    std::cout << "Press enter to go back to main menu... ";
                    std::cin.ignore();
                    break;
                }


                if(game_moves.back() != "1-0" && game_moves.back() != "0-1" && game_moves.back() != "0.5-0.5")
                {
                    int endgame_option;
                    do{
                        std::cout << "Result menu:\n"
                                << "1 - White won.\n"
                                << "2 - Black won.\n"
                                << "3 - Draw.\n"
                                << "Enter the game result: ";
                        std::cin >> endgame_option;
                        cleanBuffer();
                        if(endgame_option < 1 || endgame_option > 3){
                            std::cout << "Invalid option! Please enter a number between 1 and 3. \n";
                        }
                    } while(endgame_option < 1 || endgame_option > 3);

                    switch(endgame_option)
                    {
                        case 1:
                            game_moves.push_back("1-0");
                            break;
                        case 2:
                            game_moves.push_back("0-1");
                            break;
                        default:
                            game_moves.push_back("0.5-0.5");
                            break;
                    }
                }


                char option;
                std::cout << "Do you want to save the game in a file? (y/n)\n";
                std::cin >> option;
                cleanBuffer();
                while(option != 'y' && option != 'n'){
                    std::cout << "Please enter 'y' to yes or 'n' to no: ";
                    std::cin >> option;
                    cleanBuffer();
                }

                if(option == 'y'){
                    saveGameInFile(game_moves);
                }
                else{
                    std::cout << "Press enter to go back to main menu... ";
                    std::cin.ignore();
                }



            }
                break;
            case 2:
            {
                readGameFromFile();

            }
            default:
                break;
        }

    }while(menu_option != 3);

    return 0;
}
