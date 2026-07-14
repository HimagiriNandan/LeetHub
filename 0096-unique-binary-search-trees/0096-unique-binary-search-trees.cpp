class Solution {
public:

    int solve(int n, vector<int>& dp) {
        if(n == 0 || n == 1) return 1;
        if(dp[n] != 0) return dp[n];
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int left = i - 1;
            int right = n - i;
            ans += solve(left, dp) * solve(right, dp);
        } 
        return dp[n] = ans;
    }

    int numTrees(int n) {
       vector<int> dp(n + 1, 0);
       int ans = solve(n, dp);
       return ans;
    }
};