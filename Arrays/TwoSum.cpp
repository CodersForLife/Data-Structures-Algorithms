#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    int n = nums.size();
    if(n == 0 || n == 1)
        return ans;
        
    unordered_map<int,int> um;    
    um[nums[0]] = 0;
    for(int i=1;i<n;i++)
    {
        auto it = um.find(target - nums[i]);
        if(it != um.end())
        {
            ans.push_back((*it).second);
            ans.push_back(i);
            break;
        }
        um[nums[i]] = i;
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

  cout << twoSum(array, target) << endl;

  return 0;
}
