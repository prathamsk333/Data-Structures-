#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string temp = "";
        for (char c : s) {
            if (isalnum(c))
                temp.push_back(c);
        }
        int left = 0;
        int right = temp.size() - 1;
        while (left < right) {
            if (temp[left] != temp[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution solution;
    string testString = "A man, a plan, a canal: Panama";
    bool isPalindromic = solution.isPalindrome(testString);
    if (isPalindromic) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}
