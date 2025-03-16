class Solution {
public:
    int helper(int ind, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp, int n){
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            return dp[ind][buy] = max(-prices[ind] + helper(ind + 1, 0, prices, fee, dp, n),
            0 + helper(ind + 1, 1, prices, fee, dp, n));
        }else{
            return dp[ind][buy] = max(prices[ind] - fee + helper(ind + 1, 1, prices, fee, dp, n),
            0 + helper(ind + 1, 0, prices, fee, dp, n));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, fee, dp, n);
    }
};