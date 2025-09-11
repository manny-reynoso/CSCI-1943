#include "header.h"

int main() {
    head();  // Print header info

    // Declare & initialize 2 arrays
    int arrayOne[10] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    int arrayTwo[5]  = {5, 10, 15, 20, 25};

    // Output arrayOne
    cout << "Array One: ";
    displayArray(arrayOne, 10);

    // Output arrayTwo
    cout << "Array Two: ";
    displayArray(arrayTwo, 5);

    return 0;
}

// Function definition
void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

