/*
  This programm compute and print a sequence of numbers described by the
  Collatz conjecture, porposed by the mathematian Lothar Collatz in 30's.
  For more information: https://en.wikipedia.org/wiki/Collatz_conjecture
*/

#include <iostream>

using namespace std;

void collatz_conjecture(int number){
  while (number != 1) {
    if (number % 2 == 0){
      number = number / 2;
    } else {
      number = number * 3 + 1;
    }
    cout << number << '\n';
  }
}


int main() {

  cout << "Enter with a random number: ";

  int number {0};
  cin >> number;

  cout << "The sequence created by the given number is: " << endl;
  collatz_conjecture(number);

  return 0;
}
