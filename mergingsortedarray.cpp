#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mergedArray;
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                mergedArray.push_back(nums1[i]);
                i++;
            } else {
                mergedArray.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m) {
            mergedArray.push_back(nums1[i]);
            i++;
        }

        while (j < n) {
            mergedArray.push_back(nums2[j]);
            j++;
        }

        for (i = 0; i < mergedArray.size(); i++) {
            nums1[i] = mergedArray[i];
        }
    }
};

int main() {
    // Example usage
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
