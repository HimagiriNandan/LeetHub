class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = INT_MIN;
        int b = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= a) {
                b = a;
                a = nums[i];
            } else if(nums[i] > b) {
                b = nums[i];
            }
        }
        return (a - 1) * (b - 1);
    }
};