class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixMax(nums.size());
        prefixMax[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            prefixMax[i] = max(nums[i], prefixMax[i - 1]);
        }
        vector<int> prefixGcd(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            prefixGcd[i] = gcd(nums[i], prefixMax[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int l = 0, r = nums.size() - 1;
        long long sum = 0;
        while(l < r) {
            sum += gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }
        return sum;
    }
};