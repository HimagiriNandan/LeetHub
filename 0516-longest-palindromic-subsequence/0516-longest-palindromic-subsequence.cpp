class Solution {
public:
    int helper(string& s1, string& s2, vector<vector<int>>& dp, int ind1, int ind2){
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        int match = INT_MIN;
        if(s1[ind1] == s2[ind2]){
            match = 1 + helper(s1, s2, dp, ind1 - 1, ind2 - 1);
        }
        int notmatch = 0 + max(helper(s1, s2, dp, ind1 - 1, ind2), helper(s1, s2, dp, ind1, ind2 - 1));
        return dp[ind1][ind2] = max(match, notmatch);
    }
    int longestPalindromeSubseq(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return helper(s, rs, dp, s.length()-1, rs.length()-1);
    }
};