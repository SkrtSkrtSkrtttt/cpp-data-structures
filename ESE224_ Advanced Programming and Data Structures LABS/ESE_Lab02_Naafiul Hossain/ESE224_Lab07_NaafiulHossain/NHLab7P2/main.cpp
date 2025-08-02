//Naafiul Hossain
//SBU ID: 115107623
#include <iostream>
using namespace std;

bool isSorted(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

void bubblesort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements if they are out of order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter the values for the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool sorted = isSorted(arr, n);
    cout << "isSorted: " << (sorted ? "true" : "false") << endl;

    if (!sorted) {
        cout << "Sorting the array using bubblesort..." << endl;
        bubblesort(arr, n);
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; 
    return 0;
}
