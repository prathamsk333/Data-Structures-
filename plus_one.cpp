#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        if (digits[size - 1] == 9) {
            int i = size - 2;
            digits[size - 1] = 0;
            int carry = 1;
            while (carry != 0) {
                if (i < 0) {
                    digits.insert(digits.begin(), 1);
                    break;
                }
                digits[i] += carry;
                carry = digits[i] / 10;
                digits[i] %= 10;
                i--;
            }
        } else {
            digits[size - 1] += 1;
        }
        return digits;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> digits1 = {1, 2, 3};
    vector<int> result1 = solution.plusOne(digits1);
    cout << "Result 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> digits2 = {4, 3, 2, 1};
    vector<int> result2 = solution.plusOne(digits2);
    cout << "Result 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> digits3 = {9, 9, 9};
    vector<int> result3 = solution.plusOne(digits3);
    cout << "Result 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
