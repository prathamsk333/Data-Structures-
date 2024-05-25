#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.size(), b.size());
        while (a.size() < n) a.insert(a.begin(), '0');
        while (b.size() < n) b.insert(b.begin(), '0');
        int carry = 0;
        int sum;
        string result;
        for (int i = n - 1; i >= 0; --i) {
            sum = (a[i] - '0') + (b[i] - '0') + carry;
            result.insert(result.begin(), (sum % 2) + '0');
            carry = sum / 2;
        }
        if (carry) {
            result.insert(result.begin(), '1');
        }
        return result;
    }
};

int main() {
    Solution solution;
    string a = "1010";
    string b = "1011";
    string result = solution.addBinary(a, b);
    cout << "The sum of " << a << " and " << b << " is " << result << endl;
    return 0;
}
