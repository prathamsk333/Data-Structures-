#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> hash;
        unordered_map<string, char> hash2;
        stringstream ss(s);
        string token;
        vector<string> vec;
        
        while (getline(ss, token, ' ')) {
            vec.push_back(token);
        }

        if (vec.size() != pattern.size())
            return false;

        for (int i = 0; i < pattern.size(); i++) {
            if (hash.find(pattern[i]) == hash.end())
                hash[pattern[i]] = vec[i];

            if (hash2.find(vec[i]) == hash2.end())
                hash2[vec[i]] = pattern[i];

            if (hash.find(pattern[i]) != hash.end() && hash[pattern[i]] != vec[i])
                return false;

            if (hash2.find(vec[i]) != hash2.end() && hash2[vec[i]] != pattern[i])
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    string pattern = "abba";
    string s = "dog cat cat dog";

    bool result = sol.wordPattern(pattern, s);
    
    cout << (result ? "True" : "False") << endl;

    pattern = "abba";
    s = "dog cat cat fish";

    result = sol.wordPattern(pattern, s);
    
    cout << (result ? "True" : "False") << endl;

    pattern = "aaaa";
    s = "dog cat cat dog";

    result = sol.wordPattern(pattern, s);
    
    cout << (result ? "True" : "False") << endl;

    pattern = "abba";
    s = "dog dog dog dog";

    result = sol.wordPattern(pattern, s);
    
    cout << (result ? "True" : "False") << endl;

    return 0;
}
