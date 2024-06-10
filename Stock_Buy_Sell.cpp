#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        int min = prices[0];
        int profit = 0;
        for(int i=0; i<prices.size(); i++) {
            if(prices[i] - min > profit) {
                profit = prices[i] - min;
            } else if(min > prices[i]) {
                min = prices[i];
            }
        }
        return profit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl;
    return 0;
}
