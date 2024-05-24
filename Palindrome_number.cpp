#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        long revnum = 0;
        long original = x;
        
        while (x != 0) {
            revnum = revnum * 10 + x % 10;
            x = x / 10;
        }
        
        return original == revnum;
    }
};

int main() {
    Solution solution;
    
    int testNum1 = 121;
    int testNum2 = -121;
    int testNum3 = 10;
    int testNum4 = 12321;

    std::cout << "Is " << testNum1 << " a palindrome? " << (solution.isPalindrome(testNum1) ? "Yes" : "No") << std::endl;
    std::cout << "Is " << testNum2 << " a palindrome? " << (solution.isPalindrome(testNum2) ? "Yes" : "No") << std::endl;
    std::cout << "Is " << testNum3 << " a palindrome? " << (solution.isPalindrome(testNum3) ? "Yes" : "No") << std::endl;
    std::cout << "Is " << testNum4 << " a palindrome? " << (solution.isPalindrome(testNum4) ? "Yes" : "No") << std::endl;

    return 0;
}
