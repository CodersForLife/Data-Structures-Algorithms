#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height)
{
    int n = height.size();
    if (n == 0 || n == 1 || n == 2)
        return 0;

    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);

    leftMax[0] = height[0];
    rightMax[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], height[i]);

    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], height[i]);

    int ans = 0;
    for (int i = 1; i <= n - 2; i++) {
        ans += max((min(leftMax[i - 1], rightMax[i + 1]) - height[i]), 0);
    }
    return ans;
}

int main() {
  vector<int> array;

  int number;

  while (cin >> number) {
    array.push_back(number);
  }

  cout << trap(array) << endl;

  return 0;
}
