class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        int ele = false;
        for(int i = 0; i < nums.size(); i++) {
            xr = xr ^ nums[i];
            if(nums[i] != 0){
                ele = true;
            };
        }
        if(xr != 0) return nums.size();
        if(ele) return nums.size() - 1;
        return 0;
    }
};