class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() < 0) return 0;
        vector<int> right_max(n, 0);
        long long maxi = 0;
        right_max[n - 1] = 0;
        for(int j = n - 2; j >= 0; j--){
            right_max[j] = max(right_max[j + 1], nums[j + 1]);
        }
        int left_max = nums[0];
        for(int j = 1; j < n - 1; j++){
            long long curr = (long long)(left_max - nums[j]) * right_max[j];
            maxi = max(curr, maxi);
            left_max = max(left_max, nums[j]);
        }
        if(maxi < 0) return 0;
        return maxi;
    }
};