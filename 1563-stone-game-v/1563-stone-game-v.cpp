class Solution {
public:

    int solve(int low, int high, vector<int>& arr, vector<vector<int>>& dp) {
        if(low == high) {
            return 0;
        }
        if(dp[low][high] != 0) {
            return dp[low][high];
        }
        int ans = 0;
        for(int i = low; i <= high; i++) {
            int leftSum = arr[i] - (low > 0 ? arr[low - 1] : 0);
            int rightSum = arr[high] - arr[i];
            int currentScore;
            if(leftSum < rightSum) {
                currentScore = leftSum + solve(low, i, arr, dp);

            }
            else if(leftSum > rightSum) {
                currentScore = rightSum + solve(i + 1, high, arr, dp);

            }
            else {
                currentScore = max(
                    leftSum + solve(low, i, arr, dp),
                    rightSum + solve(i + 1, high, arr, dp)
                );
            }

            ans = max(ans, currentScore);

        }

        return dp[low][high] = ans;

    }

    int stoneGameV(vector<int>& stoneValue) {
        vector<int> prefixSum(stoneValue.size());
        prefixSum[0] = stoneValue[0];
        for(int i = 1; i < stoneValue.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + stoneValue[i];
        }
        vector<vector<int>> dp(stoneValue.size() + 1, vector<int>(stoneValue.size() + 1, 0));
        return solve(0, stoneValue.size() - 1, prefixSum, dp);
    }
};