class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int a = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > a){
                maxi = max(maxi, nums[i] - a);
            }
            else if(nums[i] < a){
                a = nums[i];
            }
        }
        if(maxi == INT_MIN){
            return -1;
        }
        return maxi;
    }
};