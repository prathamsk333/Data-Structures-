#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string temp;

        while (getline(ss, temp, '/')) {
            if (temp == "" || temp == ".") {
                continue;
            } else if (temp == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(temp);
            }
        }

        stringstream result;
        for (const string& ele : stack) {
            result << '/' << ele;
        }

        if (stack.empty()) {
            return "/";
        } else {
            return result.str();
        }
    }
};

int main() {
    Solution sol;

    cout << sol.simplifyPath("/home/") << endl;
    cout << sol.simplifyPath("/home//foo/") << endl;
    cout << sol.simplifyPath("/home/user/Documents/../Pictures") << endl;
    cout << sol.simplifyPath("/../") << endl;
    cout << sol.simplifyPath("/.../a/../b/c/../d/./") << endl;

    return 0;
}
