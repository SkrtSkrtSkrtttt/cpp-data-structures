//Naafiul Hossain
//sbu id: 115107623

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Define a struct to represent a brawler
struct Brawler {
    string name;
    int level;
    string type;
    int damage;
    int health;
};

int main() {
    // Create a vector to store brawlers
    vector<Brawler> brawlers;

    // Read data from the "Brawlers.dat" file
    ifstream inFile("Brawlers.dat");
    if (!inFile) {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        // Split the line by comma
        stringstream ss(line);
        Brawler brawler;
        getline(ss, brawler.name, ',');
        ss >> brawler.level;
        ss.ignore(); // Ignore the comma
        getline(ss, brawler.type, ',');
        ss >> brawler.damage;
        ss.ignore(); // Ignore the comma
        ss >> brawler.health;

        brawlers.push_back(brawler);
    }

    inFile.close();

    // Perform part (a) by sorting the list of brawlers by their names
    sort(brawlers.begin(), brawlers.end(), [](const Brawler& a, const Brawler& b) {
        return a.name < b.name;
        });

    // Output the sorted list
    cout << "Sorted list of brawlers:" << endl;
    for (const Brawler& brawler : brawlers) {
        cout << brawler.name << " - Level: " << brawler.level << " - Type: " << brawler.type << " - Damage: " << brawler.damage << " - Health: " << brawler.health << endl;
    }

    // b) Find and print all the brawlers that are epic and have health above 8000
    cout << "\nEpic Brawlers with health above 8000:" << endl;
    for (const Brawler& brawler : brawlers) {
        if (brawler.type == "epic" && brawler.health > 8000) {
            cout << brawler.name << " - Health: " << brawler.health << endl;
        }
    }

    // c) Find and display all the brawlers that are super-rare and deal damage below 4000
    cout << "\nSuper-Rare Brawlers with damage below 4000:" << endl;
    for (const Brawler& brawler : brawlers) {
        if (brawler.type == "super-rare" && brawler.damage < 4000) {
            cout << brawler.name << " - Damage: " << brawler.damage << endl;
        }
    }

    return 0;
}
