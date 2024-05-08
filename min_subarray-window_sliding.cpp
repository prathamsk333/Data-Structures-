#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int n = nums.size();
    int start = 0, end = 0;
    int sum = 0, ans = n + 1;

    while (end < n) {
      while (sum < target && end < n) {
        sum += nums[end];
        end++;
      }
      while (sum >= target && start < end) {
        if (end - start < ans)
          ans = end - start;
        sum -= nums[start];
        start++;
      }
    }
    if (ans == n + 1)
      return 0;
    else
      return ans;
  }
};

int main() {
  Solution solution;
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;
  int result = solution.minSubArrayLen(target, nums);
  cout << "Minimum length of subarray with sum >= " << target << ": " << result
       << endl;
  return 0;
}
