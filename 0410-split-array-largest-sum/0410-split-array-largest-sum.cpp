class Solution {
public:
    int helper(int s, vector<int>& nums){
        int res = 1;
        int ts = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] + ts <= s){
                ts += nums[i];
            }else{
                res++;
                ts = nums[i];
            }
        }
        return res;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low <= high){
            int mid = (low + high) / 2;
            if(helper(mid, nums) > k){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};