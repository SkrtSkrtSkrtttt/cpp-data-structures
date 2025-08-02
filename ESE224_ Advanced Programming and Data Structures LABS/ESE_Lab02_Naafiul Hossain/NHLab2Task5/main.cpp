//Naafiul Hossain
//SBU ID: 115107623
#include "Game.h"

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    for (;;) {
        displayMenu();

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addition();
            break;
        case 2:
            subtraction();
            break;
        case 3:
            multiplication();
            break;
        case 4:
            division();
            break;
        case 5:
            std::cout << "Exiting the game.\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
