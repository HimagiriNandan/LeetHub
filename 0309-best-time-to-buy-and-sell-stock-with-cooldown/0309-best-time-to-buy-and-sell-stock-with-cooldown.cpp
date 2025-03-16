class Solution {
public:
    int helper(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp, int n){
        if(ind >= n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            return dp[ind][buy] = max(-prices[ind] + helper(ind + 1, 0, prices, dp, n), 
            0 + helper(ind + 1, 1, prices, dp, n));
        }else{
            return dp[ind][buy] = max(prices[ind] + helper(ind + 2, 1, prices, dp, n),
            0 + helper(ind + 1, 0, prices, dp, n));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return helper(0, 1, prices, dp, prices.size());
    }
};