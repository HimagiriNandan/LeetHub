class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> suffix(nums.size());
        int mini = INT_MAX;
        for(int i = nums.size() - 1; i >= 0; i--) {
            mini = min(nums[i], mini);
            suffix[i] = mini;
        }
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            maxi = max(nums[i], maxi);
            int diff = maxi - suffix[i];
            if(diff <= k){
                return i;
            }
        }
        return -1;
    }
};