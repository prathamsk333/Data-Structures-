#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int j;
  int removeElement(vector<int> &nums, int val) {

    for (j = 0; j < nums.size(); j++) {
      if (nums[j] == val) {
        swap(nums[j], nums.back());
        nums.pop_back();
        j--;
      }
    }
    return nums.size();
  }
};

int main() {
  Solution sol;
  vector<int> nums = {3, 2, 2, 3, 4, 5};
  int val = 3;
  int newSize = sol.removeElement(nums, val);

  cout << "New size of the array after removing " << val << ": " << newSize
       << endl;
  cout << "Remaining elements in the array: ";
  for (int i = 0; i < newSize; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;

  return 0;
}
