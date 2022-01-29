#include <iostream>
#include "board.h"
#include "helper_functions.h"
#include <string>
#include <exception>

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

                    std::string playerMove;
                    do{
                        std::cout << "Please enter a valid move: ";
                        std::getline(std::cin, playerMove);
                    } while(gameBoard.isMove(playerMove) == false && playerMove != "q");
                    if(playerMove == "q") break;

                    std::string initialPiecePosition = playerMove.substr(0,2);
                    std::string finalPiecePosition = playerMove.substr(3,2);


                    std::cout << initialPiecePosition << " " << finalPiecePosition << std::endl;

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
