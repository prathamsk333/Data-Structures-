#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_max = nums[0];
        int glob_max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curr_max = max(nums[i], nums[i] + curr_max);
            if (curr_max > glob_max) {
                glob_max = curr_max;
            }
        }
        return glob_max;
    }
};

int main() {
    // Example usage:
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    int result = sol.maxSubArray(nums);
    cout << "Maximum subarray sum: " << result << endl;
    return 0;
}
