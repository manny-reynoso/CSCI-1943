#include "header.h"

int main(){
  head();

  vector<int> numbers; //Declare empty vector
  int input;

  cout << "Enter 10 numbers:" << endl;

  //For loop to enter 10 numbers
  for (int i=0; i < 10; i++) {
    cout << "Value" << (i + 1) << ":" ;
    cin >> input;
    numbers.push_back(input);
  }

  cout << "\nYou entered: \n";

  //Output 10 values
  displayVector(numbers);

  return 0;
}

// Function 
void displayVector(const vector<int>& vec){
  for (int value : vec){
    cout << value << endl; // Shuld print on new linecls
  }
}