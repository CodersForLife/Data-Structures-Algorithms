#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target)
{
    int n = nums.size();

    int s = 0, e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] > target) {
            if (nums[mid] <= nums[e])
                e = mid - 1;
            else {
                if (target > nums[e])
                    e = mid - 1;
                else
                    s = mid + 1;
            }
        }
        else {
            if (nums[mid] >= nums[s])
                s = mid + 1;
            else {
                if (target > nums[e])
                    e = mid - 1;
                else
                    s = mid + 1;
            }
        }
    }
    return -1;
}

int main() {
  vector<int> array;

  int number, target;
  cin>>target;

  while (cin >> number) {
    array.push_back(number);
  }

  cout << search(array, target) << endl;

  return 0;
}
