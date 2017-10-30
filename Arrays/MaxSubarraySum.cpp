#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySum(const vector<int> &array) {
  int maxSum = *array.begin();

  int sum = 0;
  for (vector<int>::const_iterator i = array.begin(); i != array.end(); ++i) {
    sum += *i;
    maxSum = max(maxSum, sum);

    if (sum < 0) {
      sum = 0;
    }
  }

  return maxSum;
}

int main() {
  vector<int> array;

  int number;
  while (cin >> number) {
    array.push_back(number);
  }

  cout << maxSubarraySum(array) << endl;

  return 0;
}
