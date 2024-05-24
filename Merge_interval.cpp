#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back({intervals[0][0], intervals[0][1]});
        
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int>& lastMerged = mergedIntervals.back();
            if (intervals[i][0] <= lastMerged[1]) {
                lastMerged[1] = max(lastMerged[1], intervals[i][1]);
            } else {
                mergedIntervals.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return mergedIntervals;
    }
};

void printIntervals(const vector<vector<int>>& intervals) {
    for (const auto& interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    vector<vector<int>> intervals1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> intervals2 = {{1, 4}, {4, 5}};
    vector<vector<int>> intervals3 = {{1, 4}, {0, 4}};

    cout << "Merged intervals for intervals1: ";
    vector<vector<int>> result1 = solution.merge(intervals1);
    printIntervals(result1);

    cout << "Merged intervals for intervals2: ";
    vector<vector<int>> result2 = solution.merge(intervals2);
    printIntervals(result2);

    cout << "Merged intervals for intervals3: ";
    vector<vector<int>> result3 = solution.merge(intervals3);
    printIntervals(result3);

    return 0;
}
