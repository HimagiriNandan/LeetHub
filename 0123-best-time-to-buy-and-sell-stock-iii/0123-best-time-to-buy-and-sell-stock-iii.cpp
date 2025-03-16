class Solution {
public:
    // buy = 1, sell = 0
    int helper(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(ind == prices.size()) return 0;
        if(cap == 0) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if(buy){
            return dp[ind][buy][cap] = max(-prices[ind] + helper(ind + 1, 0, cap, prices, dp),
            0 + helper(ind + 1, 1, cap, prices, dp));
        }
        else{
            return dp[ind][buy][cap] = max(prices[ind] + helper(ind + 1, 1, cap-1, prices, dp), 
            0 + helper(ind + 1, 0, cap, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(3, -1)));
        return helper(0, 1, 2, prices, dp); // index, buy/sell, capacity (at most 2 transactions)
    }
};