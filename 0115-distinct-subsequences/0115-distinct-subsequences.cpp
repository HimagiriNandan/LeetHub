class Solution {
public:

    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(s.length() + 1, vector<long long>(t.length() + 1, 0));
        int m = s.length();
        int n = t.length();
        for(int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                int ans = 0;
                if(s[i - 1] == t[j - 1]){
                    ans = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    ans = dp[i - 1][j]; 
                }
                dp[i][j] = ans;
            }
        }
        return dp[m][n];
    }
};