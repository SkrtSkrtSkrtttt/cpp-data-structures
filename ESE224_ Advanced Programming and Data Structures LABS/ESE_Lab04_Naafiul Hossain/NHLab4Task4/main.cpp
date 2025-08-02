//Naafiul Hossain
//SBU ID: 11507623

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Player.h"  // Include the Player class header file

int rollDice() {
    return rand() % 6 + 1;  // Simulating a dice roll (1-6)
}

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Instantiate two player objects
    Player player1;
    Player player2;

    for (int round = 1; round <= 3; ++round) {
        std::cout << "\nRound " << round << ":\n";

        // Get player choices
        std::cout << "Player 1, enter your choice (1-6): ";
        int choice1;
        std::cin >> choice1;
        player1.setChoice(choice1);

        std::cout << "Player 2, enter your choice (1-6): ";
        int choice2;
        std::cin >> choice2;
        player2.setChoice(choice2);

        // Roll the dice
        int diceValue = rollDice();
        std::cout << "Dice value: " << diceValue << "\n";

        // Play the round for each player
        player1.playround(diceValue);
        player2.playround(diceValue);

        // Display current scores
        std::cout << "Player 1 coins: " << player1.getCoins() << "\n";
        std::cout << "Player 2 coins: " << player2.getCoins() << "\n";
    }

    // Determine the winner
    if (player1.getCoins() > player2.getCoins()) {
        std::cout << "\nPlayer 1 wins!\n";
    }
    else if (player1.getCoins() < player2.getCoins()) {
        std::cout << "\nPlayer 2 wins!\n";
    }
    else {
        std::cout << "\nIt's a draw!\n";
    }

    return 0;
}
