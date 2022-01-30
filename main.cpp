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
                Board gameBoard;

                while(true)
                {
                    gameBoard.display();

                    std::string player_move;
                    do{
                        std::cout << "Please enter a valid move: ";
                        std::getline(std::cin, player_move);
                    } while(gameBoard.isMove(player_move) == false && player_move != "q");
                    if(player_move == "q") break;

                    gameBoard.movePiece(player_move);

                    gameBoard.switchTurn();
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
