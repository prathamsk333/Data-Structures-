#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);

        int size = nums.size();
        if (size == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (size == 2 && nums[0] < nums[1])
            return 1;
        if (nums[size - 1] > nums[size - 2])
            return size - 1;

        for (int i = 1; i < size - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                return i;
        }

        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    cout << sol.findPeakElement(nums) << endl;
    return 0;
}
