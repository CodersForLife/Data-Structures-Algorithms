#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > fourSum(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int> > ans;
    int i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n) {
            int s = j + 1, e = n - 1;
            while (s < e) {
                int cSum = nums[i] + nums[j] + nums[s] + nums[e];
                if (cSum == target) {
                    vector<int> temp = { nums[i], nums[j], nums[s], nums[e] };
                    ans.push_back(temp);
                    s += 1;
                    e -= 1;
                    while (s < n && nums[s] == nums[s - 1])
                        s += 1;

                    while (e >= 0 && nums[e] == nums[e + 1])
                        e -= 1;
                }
                else if (cSum > target)
                    e -= 1;
                else
                    s += 1;
            }
            j += 1;
            while (j < n && nums[j] == nums[j - 1])
                j += 1;
        }
        i += 1;
        while (i < n && nums[i] == nums[i - 1])
            i += 1;
    }
    return ans;
}

int main() {
  vector<int> array;

  int number, target;
  cin>>target;

  while (cin >> number) {
    array.push_back(number);
  }

  cout << fourSum(array, target) << endl;

  return 0;
}
