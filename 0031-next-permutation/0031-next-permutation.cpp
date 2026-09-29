class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind = -1;
        if(nums.size() <= 1) {
            return;
        }
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i + 1] > nums[i]){
                ind = i;
                break;
            }
        }
        if(ind < 0){
            reverse(nums.begin(), nums.end());
            return;
        }

       int successor = nums.size() - 1;
       while(nums[successor] <= nums[ind]) {
            successor--;
       }
       swap(nums[ind], nums[successor]);
       reverse(nums.begin() + ind + 1, nums.end());
    }
};