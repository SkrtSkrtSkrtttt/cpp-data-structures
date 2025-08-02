//Naafiul Hossian
//SBU ID: 115107623
#pragma once
#include <string>
#include <fstream>
using namespace std;
class ShoppingList {
private:
    string file_name;
    fstream myFile;
    string most_expensive_item;
    string name;
    double price;
    double max_price;

public:
    ShoppingList();
    bool fileOpen(istream& in);
    bool itemExists(istream& in);
    void addItem(istream& in);
    void PrintMostExpensiveItem();
    void PrintAll();
    void PrintTranspose();
    void PrintSort();

};