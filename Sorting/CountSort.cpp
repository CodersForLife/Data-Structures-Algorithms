#include <iostream>

using namespace std;

static const int MAX_VALUE = 100000;

int main() {
  int array[MAX_VALUE] = {};
  int number;

  while (cin >> number) {
    ++array[number];
  }

  for (int i = 0; i < MAX_VALUE; ++i) {
    for (int count = 0; count < array[i]; ++count) {
      cout << i << endl;
    }
  }

  return 0;
}
