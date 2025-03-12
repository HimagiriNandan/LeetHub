class Solution {
public:
    int solve(string& s1, string& s2, vector<vector<int>>& dp, int ind1, int ind2){
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2]){
            return dp[ind1][ind2] = 1 + solve(s1, s2, dp, ind1 - 1, ind2 - 1);
        }
        return dp[ind1][ind2]  = max(solve(s1, s2, dp, ind1 - 1, ind2), solve(s1, s2, dp, ind1, ind2 - 1));
    }
    int helper(string& s){
        string rev_string = s;
        reverse(rev_string.begin(), rev_string.end());
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return solve(s, rev_string, dp, s.length() - 1, s.length() - 1);
    }
    int minInsertions(string s) {
        return s.size() - helper(s);
    }
};