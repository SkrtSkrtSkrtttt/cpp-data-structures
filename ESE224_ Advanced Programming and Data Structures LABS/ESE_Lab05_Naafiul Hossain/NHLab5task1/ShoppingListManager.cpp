//Naafiul Hossain
// SBU ID: 115107623

#include <iostream>
#include <fstream> // Include the <fstream> header for file operations
#include "shoppingList.h"

int main() {
    std::cout << "Opening shopping list manager... " << std::endl << std::endl;
    std::cout << "Please enter the file name: ";

    ShoppingList shoppingList;
    if (!shoppingList.fileOpen(std::cin)) {
        std::cerr << "Error opening the target file!" << std::endl;
        exit(1);
    }

    std::cout << "\nSuccessfully opening the file";

    // Display a menu to the user
    while (true) {
        std::cout << " (a) - add an item and its price" << std::endl;
        std::cout << " (e) - print the most expensive item" << std::endl;
        std::cout << " (i) - check to see if this item exists" << std::endl;
        std::cout << " (p) - print all items and their prices" << std::endl;
        std::cout << " (q) - quit the program" << std::endl;
        std::cout << " (s) - print in descending order" << std::endl;
        std::cout << " (t) - print in transposed format" << std::endl;
        std::cout << "Enter your choice: ";

        char choice;
        std::cin >> choice;

        switch (choice) {
        case 'p':
            shoppingList.PrintAll();
            break;
        case 't':
            shoppingList.PrintTranspose();
            break;
        case 'e':
            shoppingList.PrintMostExpensiveItem();
            break;
        case 'i':
            std::cout << "Enter the item name to check: ";
            if (shoppingList.itemExists(std::cin)) {
                std::cout << "Item found." << std::endl;
            }
            else {
                std::cout << "Item not found." << std::endl;
            }
            break;
        case 'a':
            shoppingList.addItem(std::cin);
            break;
        case 's':
            shoppingList.PrintSort();
            break;
        case 'q':
            std::cout << "Exiting the program." << std::endl;
            return 0; // Exit the program
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}


