//Naafiul Hossain
//SBU ID: 115107623
#include "Game.h"

int generateRandomNumber() {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(0)));

    // Generate a random number between 10 and 99
    return std::rand() % 90 + 10;
}

void displayMenu() {
    std::cout << "Input a number 1 - 5 to select a random problem or exit the game.\n";
    std::cout << "1 - Addition\n";
    std::cout << "2 - Subtraction\n";
    std::cout << "3 - Multiplication\n";
    std::cout << "4 - Division\n";
    std::cout << "5 - Exit\n";
}


void addition() {
    int num1 = generateRandomNumber();
    int num2 = generateRandomNumber();
    int result = num1 + num2;

    int userAnswer;
    std::cout << "Addition problem: " << num1 << " + " << num2 << " = ?\n";
    std::cout << "Your answer: ";
    std::cin >> userAnswer;

    if (userAnswer == result)
        std::cout << "Correct!\n";
    else
        std::cout << "Wrong. The correct answer is: " << result << "\n";
}

void subtraction() {
    int num1 = generateRandomNumber();
    int num2 = generateRandomNumber();
    int result = num1 - num2;

    int userAnswer;
    std::cout << "Subtraction problem: " << num1 << " - " << num2 << " = ?\n";
    std::cout << "Your answer: ";
    std::cin >> userAnswer;

    if (userAnswer == result)
        std::cout << "Correct!\n";
    else
        std::cout << "Wrong. The correct answer is: " << result << "\n";
}

void multiplication() {
    int num1 = generateRandomNumber();
    int num2 = generateRandomNumber();
    int result = num1 * num2;

    int userAnswer;
    std::cout << "Multiplication problem: " << num1 << " * " << num2 << " = ?\n";
    std::cout << "Your answer: ";
    std::cin >> userAnswer;

    if (userAnswer == result)
        std::cout << "Correct!\n";
    else
        std::cout << "Wrong. The correct answer is: " << result << "\n";
}

void division() {
    int num1 = generateRandomNumber();
    int num2 = generateRandomNumber();

    // Ensure num2 is not 0 to avoid division by zero
    while (num2 == 0)
        num2 = generateRandomNumber();

    int result = num1 / num2;

    int userAnswer;
    std::cout << "Division problem: " << num1 << " / " << num2 << " = ?\n";
    std::cout << "Your answer: ";
    std::cin >> userAnswer;

    if (userAnswer == result)
        std::cout << "Correct!\n";
    else
        std::cout << "Wrong. The correct answer is: " << result << "\n";
}



