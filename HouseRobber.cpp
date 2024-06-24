class Solution {
public:
    int solve(int n, vector<int>& nums, vector<int> &dp)
    {
        if(n<0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        int first = solve(n-2, nums, dp) + nums[n];
        int second = solve(n-1, nums, dp);
        return dp[n]=max(first, second);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums.size()-1, nums, dp);
    }
};
