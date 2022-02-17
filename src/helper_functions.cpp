#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "board.h"

void displayMenu()
{
    system("cls||clear");
    std::cout << "\n\<------------MAIN MENU------------>\n\n"
            << "1. Play a game (2 players)\n"
            << "2. Open a game\n"
            << "3. Quit\n"
            << "Please enter a valid option: ";
}

void cleanBuffer()
{
    std::cin.clear();
    fflush(stdin);
}

void saveGameInFile(const std::vector<std::string>& game_moves)
{
    std::string file_path = "games/";
    std::string file_name;
    std::ofstream game_file;


    std::cout << "Enter the file name (without extension): ";
    std::getline(std::cin, file_name);

    file_path.append(file_name);
    file_path.append(".txt");

    game_file.open(file_path);
    if(game_file.is_open()){
        for(auto& player_move : game_moves)
            game_file << player_move << std::endl;

        game_file.close();

        std::cout << "Game saved successfully!\n"
                << "Press enter to go back to main menu... ";
        std::cin.ignore();
    }
    else{
        std::cout << "Could not open the file!\n";
        std::cout << "Press enter to go back to main menu... ";
        std::cin.ignore();
    }

}

void readGameFromFile()
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
                std::cout << "White won! Press enter to go back to main menu... ";
                std::cin.ignore();
                game_file.close();
                break;
            }
            else if(player_move == "0-1"){
                std::cout << "Black won! Press enter to go back to main menu... ";
                std::cin.ignore();
                game_file.close();
                break;
            }
            else if(player_move == "0.5-0.5"){
                std::cout << "Draw! Press enter to go back to main menu... ";
                std::cin.ignore();
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
                std::cout << "Press enter to go back to main menu... ";
                std::cin.ignore();
                game_file.close();
                break;
            }
            game_board.movePiece(player_move);
            game_board.switchTurn();

        }

        game_file.close();
    }
    else{
        std::cout << "File not found!" << std::endl;
        std::cout << "Press enter to go back to main menu... ";
        std::cin.ignore();
    }
}
