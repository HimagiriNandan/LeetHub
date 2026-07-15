class Solution {
public:
    int dp[201][201][201];
    static const int mod = 1e9 + 7;
    int solve(int ind, int gcd1, int gcd2, int n, vector<int>& nums) {
        if(ind == n) {
            return (gcd1 == gcd2 && gcd1 != 0);
        }
        if(dp[ind][gcd1][gcd2] != -1) {
            return dp[ind][gcd1][gcd2];
        }
        long long ans = 0;
        ans += solve(ind + 1, gcd(gcd1, nums[ind]), gcd2, n, nums);

        ans += solve(ind + 1, gcd1, gcd(gcd2, nums[ind]), n, nums);

        ans += solve(ind + 1, gcd1, gcd2, n, nums);

        return dp[ind][gcd1][gcd2] = ans % mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums.size(), nums);
    }
};