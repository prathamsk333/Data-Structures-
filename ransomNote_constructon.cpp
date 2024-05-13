#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;

        for(int i = 0; i < magazine.size(); i++) {
            hash[magazine[i]]++;
        }

        for(int i = 0; i < ransomNote.length(); i++) {
            if(hash.find(ransomNote[i]) == hash.end() || hash[ransomNote[i]] <= 0) {
                return false;
            }
            else {
                hash[ransomNote[i]]--;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string ransomNote = "aa";
    string magazine = "aab";

    if(sol.canConstruct(ransomNote, magazine)) {
        cout << "Ransom note can be constructed from magazine." << endl;
    }
    else {
        cout << "Ransom note cannot be constructed from magazine." << endl;
    }

    return 0;
}
