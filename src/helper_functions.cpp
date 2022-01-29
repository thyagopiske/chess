#include <iostream>

void displayMenu()
{
    std::cout << "1. Play a game (2 players)\n"
            << "2. Open a game\n"
            << "3. Quit\n"
            << "Please enter a valid option: ";
}

void cleanBuffer()
{
    std::cin.clear();
    fflush(stdin);
}
