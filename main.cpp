#include <iostream>
#include <string>
#include <exception>
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

            }
                break;
            default:
                break;
        }

    }while(option != 3);

    return 0;
}
