#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int result = sol.searchInsert(nums, target);
    cout << "Insert position of target " << target << " is: " << result << endl;

    target = 2;
    result = sol.searchInsert(nums, target);
    cout << "Insert position of target " << target << " is: " << result << endl;

    target = 7;
    result = sol.searchInsert(nums, target);
    cout << "Insert position of target " << target << " is: " << result << endl;

    target = 0;
    result = sol.searchInsert(nums, target);
    cout << "Insert position of target " << target << " is: " << result << endl;

    return 0;
}
