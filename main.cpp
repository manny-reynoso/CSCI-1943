#include "header.h"

int main(){
  // Declare & init 2 arrays
    int arrayOne[10] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}:
    int arrayTwo[5] = {5, 10, 15, 20, 25};

  // Output arrayOne
    cout << "Array One: ";
    displayArray(arrayOne, 10);

  //Output arrayTwo
  cout <<"Array Two: ";
  displayArray(arrayTwo, 5);

  return 0;
}