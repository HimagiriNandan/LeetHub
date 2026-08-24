class Solution {
    vector<long long> pref;
    int n;
    long long solve(int i, vector<long long> &dp) {
        if (i == n - 1) {
            return pref[n - 1];
        }
        if(dp[i] != -1e18){
            return dp[i];
        }
        long long pick = pref[i] - solve(i + 1,dp);
        long long notPick = solve(i + 1,dp);
        return dp[i] = max(pick, notPick);
    }

public:
    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        vector<long long> dp(n+1 , -1e18);
        pref.resize(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + stones[i];
        }
        return solve(1,dp);
    }
};