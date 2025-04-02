class Solution {
public:
    long long helper(vector<vector<int>>& questions, int ind, int n, vector<long long>& dp){
        if(ind >= n){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        long long pick = questions[ind][0] + helper(questions, ind + questions[ind][1] + 1, n, dp);
        long long notpick = 0 + helper(questions, ind + 1, n, dp);
        return dp[ind] = max(pick, notpick);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size() + 1, -1);
        return helper(questions, 0, questions.size(), dp);
    }
};