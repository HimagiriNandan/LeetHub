class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        sort(nums.begin(), nums.end());
        int maxi = 1;
        int lastIndex = 0;
        for(int i = 0; i < n; i++){
            hash[i] = i;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> res;
        res.push_back(nums[lastIndex]);
        while(lastIndex != hash[lastIndex]){
            lastIndex = hash[lastIndex];
            res.push_back(nums[lastIndex]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};