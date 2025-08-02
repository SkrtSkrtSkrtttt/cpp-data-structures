//Naafiul Hossain
//SBU ID: 115107623

#include <iostream>
#include "Player.h"  // Include the header file to access class declarations

// Constructor
Player::Player() : coins(200), choice(0) {}

// Function to play a round
void Player::playround(int dice) {
    if (choice == dice) {
        coins += 100;  // Double the coins if choice matches dice
    }
    else {
        coins -= 50;   // Lose 50 coins if choice doesn't match dice
    }
}

// Getter for coins
int Player::getCoins() const {
    return coins;
}

// Setter for coins
void Player::setCoins(int coins) {
    this->coins = coins;
}

// Getter for choice
int Player::getChoice() const {
    return choice;
}

// Setter for choice
void Player::setChoice(int choice) {
    this->choice = choice;
}
