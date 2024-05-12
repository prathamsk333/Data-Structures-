/*Check if Grid Satisfies Conditions
User Accepted:17321
User Tried:19411
Total Accepted:18167
Total Submissions:48897
Difficulty:Easy
You are given a 2D matrix grid of size m x n. You need to check if each cell grid[i][j] is:

Equal to the cell below it, i.e. grid[i][j] == grid[i + 1][j] (if it exists).
Different from the cell to its right, i.e. grid[i][j] != grid[i][j + 1] (if it exists).
Return true if all the cells satisfy these conditions, otherwise, return false.
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (m == 1 && n == 1)
            return true;
       
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (grid[i][j] != grid[i + 1][j] || grid[i][j] == grid[i][j + 1])
                    return false;
            }
        }

        for (int j = 0; j < n - 1; j++) {
            if (grid[m - 1][j] == grid[m - 1][j + 1])
                return false;
        }

        for (int i = 0; i < m - 1; i++) {
            if (grid[i][n - 1] != grid[i + 1][n - 1])
                return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {{1}};
    cout << "Grid 1 satisfies conditions: " << boolalpha << sol.satisfiesConditions(grid1) << endl;

    vector<vector<int>> grid2 = {{1, 2}, {3, 4}};
    cout << "Grid 2 satisfies conditions: " << boolalpha << sol.satisfiesConditions(grid2) << endl;

    vector<vector<int>> grid3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Grid 3 satisfies conditions: " << boolalpha << sol.satisfiesConditions(grid3) << endl;

    vector<vector<int>> grid4 = {{1, 2, 3}, {4, 1, 6}, {7, 8, 1}};
    cout << "Grid 4 satisfies conditions: " << boolalpha << sol.satisfiesConditions(grid4) << endl;

    return 0;
}

