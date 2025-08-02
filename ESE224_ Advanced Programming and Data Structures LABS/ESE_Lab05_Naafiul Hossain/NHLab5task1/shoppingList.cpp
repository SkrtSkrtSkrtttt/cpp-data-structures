#include "shoppingList.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

ShoppingList::ShoppingList() {

}

//task1
bool ShoppingList::fileOpen(istream& in) {
	in >> file_name;
	if (file_name == "d") {
		file_name = "ItemCatalogItem.txt";
	}
	myFile.open(file_name);
	return myFile.is_open();
}

void ShoppingList::PrintAll() {
    int counter = 0;
    cout << endl;
    //myFile.seekg(0, ios::beg); // Corrected the function name 'seekbeg' to 'seekg'

    while (!myFile.eof()){
        myFile >> name >> price; // Use the file read operation as the condition
        cout << ++counter << " . " << name << " is " << price << endl; // Added spaces and corrected the string formatting
    }

    //myFile.clear(); // Clear any error flags if they were set
    //myFile.seekg(0, ios::beg); // Move the file pointer back to the beginning of the file
    cout << endl;
}
void ShoppingList::PrintTranspose() {
    myFile.seekg(0, ios::beg);

    while (myFile >> name >> price) {
        int best_width = max(name.length(), to_string(price).length()) + 1;
        cout << setw(best_width) << left << name;
    }
    cout << endl;
    myFile.clear(); // Clear any error flags if they were set
    myFile.seekg(0, ios::beg);

    while (myFile >> name >> price) {
        int best_width = max(name.length(), to_string(price).length()) + 1;
        cout << setw(best_width) << left << price;
    }
    cout << endl;
    myFile.clear(); // Clear any error flags if they were set
    myFile.seekg(0, ios::beg);
}

bool ShoppingList::itemExists(istream& in) {
    string input;
    in >> input;
    myFile.seekg(0, ios::beg); // Ensure the file is at the beginning
    while (myFile >> name >> price) {
        if (name == input) {
            cout << "Item: " << name << " Price: " << price << endl;
            return true; // Item exists, return true
        }
    }
    return false;

}

void ShoppingList::addItem(istream& in) {
    string newItemName;
    double newItemPrice;

    // Read the item name and price from the user
    cout << "Enter the item name: ";
    in >> newItemName;

    cout << "Enter the item price: ";
    in >> newItemPrice;

    // Open the file in append mode to add the new item to the end
    myFile.open(file_name, ios::app);

    if (myFile.is_open()) {
        // Write the new item to the file
        myFile << newItemName << " " << newItemPrice << endl;

        cout << "Item added to the shopping list: " << newItemName << " Price: " << newItemPrice << endl;

        // Close the file to save the changes
        myFile.close();
    }
    else {
        cerr << "Error: Unable to open the file for adding the item." << endl;
    }
}
void ShoppingList::PrintMostExpensiveItem() {
    // Open the file containing the shopping list data
    myFile.open(file_name);

    if (!myFile.is_open()) {
        cerr << "Error: Unable to open the file." << endl;
        return;
    }

    string mostExpensiveItemName;
    double mostExpensiveItemPrice = 0; // Initialize with a low value

    while (myFile >> name >> price) {
        // Check if the current item is more expensive than the previously found most expensive item
        if (price > mostExpensiveItemPrice) {
            mostExpensiveItemName = name;
            mostExpensiveItemPrice = price;
        }
    }

    // Close the file
    myFile.close();

    if (mostExpensiveItemName.empty()) {
        cout << "No items in the shopping list." << endl;
    }
    else {
        cout << "The most expensive item is: " << mostExpensiveItemName << " Price: " << mostExpensiveItemPrice << endl;
    }
}
void ShoppingList::PrintSort() {
    // Ensure the file is at the beginning
    myFile.clear();
    myFile.seekg(0, ios::beg);

    vector<pair<string, double>> Items;

    while (myFile >> name >> price) {
        Items.push_back(make_pair(name, price));
    }

    int s = Items.size();

    for (int i = 0; i < s - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < s - 1 - i; j++) {
            if (Items[j].second < Items[j + 1].second) {
                swap(Items[j], Items[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break; // If no swaps were made in a pass, the list is already sorted
        }
    }

    cout << "\nPrices sorted in descending order: " << endl;

    for (int i = 0; i < s; i++) {
        cout << i + 1 << ". " << Items[i].first << "\t$" << fixed << setprecision(2) << Items[i].second << endl;
    }

    cout << endl;
}

