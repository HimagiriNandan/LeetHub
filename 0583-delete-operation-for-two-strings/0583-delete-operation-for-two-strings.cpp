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
        return dp[ind1][ind2] = max(solve(s1, s2, dp, ind1 - 1, ind2), solve(s1, s2, dp, ind1, ind2 - 1));
    }
    int helper(string& word1, string& word2, int n, int m){
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(word1, word2, dp, n - 1, m - 1);
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        int k = helper(word1, word2, n, m);
        return (n - k) + (m - k);
    }
};