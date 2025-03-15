class Solution {
public:
    bool allStars(string& pattern, int j){
        for(int i = 0; i <= j; i++){
            if(pattern[i] != '*') return false;
        }
        return true;
    }
    bool helper(int i, int j, string& str, string& pattern, vector<vector<int>>& dp){
        //base cases
        if(j < 0){
            if(i >= 0) return false;
            else{
                return true;
            }
        }
        if(i < 0){
            if(allStars(pattern, j)){
                return true;
            }
            return false;
        }
        if(dp[i][j] != -1) return dp[i][j]; 

        if(str[i] == pattern[j] || pattern[j] == '?'){
            return dp[i][j] = helper(i - 1, j - 1, str, pattern, dp);
        }
        else{
            if(pattern[j] == '*'){
                return dp[i][j] = helper(i - 1, j, str, pattern, dp) || helper(i, j - 1, str, pattern, dp);
            }else{
                return false;
            }
        }
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, s, p, dp);
    }
};