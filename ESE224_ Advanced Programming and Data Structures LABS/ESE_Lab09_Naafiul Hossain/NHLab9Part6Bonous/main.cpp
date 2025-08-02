//Naafiul Hossain
//SBU ID: 115107623 
#include <iostream>
#include <string>
using namespace std;

// Structure for the binary tree node
struct Node {
    string data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to play the game
void playGame(Node* root) {
    char choice;
    do {
        Node* current = root;
        while (current) {
            cout << current->data << " (yes/no): ";
            string answer;
            cin >> answer;

            if (answer == "yes") {
                if (current->left)
                    current = current->left;
                else {
                    cout << "I guessed it right!" << endl;
                    break;
                }
            }
            else if (answer == "no") {
                if (current->right)
                    current = current->right;
                else {
                    string animal;
                    cout << "What animal were you thinking of?: ";
                    cin >> animal;
                    string question;
                    cout << "What is a yes/no question that would distinguish "
                        << animal << " from " << current->data << "?: ";
                    cin.ignore();
                    getline(cin, question);
                    cout << "I'll remember that for next time!" << endl;
                    current->right = createNode(animal);
                    current->left = createNode(current->data);
                    current->data = question;
                    break;
                }
            }
            else {
                cout << "Invalid input. Please enter 'yes' or 'no'." << endl;
            }
        }
        cout << "Press 'q' to quit, press any other key to continue: ";
        cin >> choice;
    } while (choice != 'q');
}

int main() {
    // Create the initial tree structure
    Node* root = createNode("Is it a vertebrate?");
    root->left = createNode("Bird");
    root->right = createNode("Snail");

    cout << "Welcome to the Animal Guessing Game!" << endl;
    playGame(root);

    return 0;
}