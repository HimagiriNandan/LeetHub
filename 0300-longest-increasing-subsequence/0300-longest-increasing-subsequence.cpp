class Solution {
public:
    int helper(vector<int>& nums, vector<vector<int>>& dp, int n, int ind, int prev_ind){
        if(ind == n) return 0;
        if(dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];
        int len = 0 + helper(nums, dp, n, ind + 1, prev_ind);
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            len = max(len, 1 + helper(nums, dp, n, ind + 1, ind));
        }
        return dp[ind][prev_ind + 1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(nums, dp, n, 0, -1);
    }
};