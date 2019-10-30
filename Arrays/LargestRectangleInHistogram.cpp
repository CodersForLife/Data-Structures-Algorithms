#include <iostream>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    heights.push_back(0);
    int n = heights.size();
    stack<int> stk;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (stk.empty() || heights[stk.top()] <= heights[i])
            stk.push(i);
        else {
            while (!stk.empty() && heights[stk.top()] > heights[i]) {
                int barHeight = heights[stk.top()];
                stk.pop();
                int area = 0;
                if (stk.empty())
                    area = i * barHeight;
                else
                    area = (i - 1 - (stk.top() + 1) + 1) * barHeight;
                ans = max(ans, area);
            }
            stk.push(i);
        }
    }
    return ans;
}

int main() {
  vector<int> array;

  int number;

  while (cin >> number) {
    array.push_back(number);
  }

  cout << largestRectangleArea(array) << endl;

  return 0;
}
