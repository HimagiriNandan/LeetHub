class Solution {
public:

    int solve(string &s, string &t, int l1, int l2, vector<vector<int>>& dp) {
        if(l2 < 0) {
            return 1;
        }

        if(l1 < 0) {
            return 0;
        }

        if(dp[l1][l2] != -1) {
            return dp[l1][l2];
        }
        int not_pick = solve(s, t, l1 - 1, l2, dp);
        int pick = 0;

        if(s[l1] == t[l2]) {
            pick = solve(s, t, l1 - 1, l2 - 1, dp);
        }
        return dp[l1][l2] = not_pick + pick;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(t.length(), -1));
        return solve(s, t, s.length() - 1, t.length() - 1, dp);
    }
};