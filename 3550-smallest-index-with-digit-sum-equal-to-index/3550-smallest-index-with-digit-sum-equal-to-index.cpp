class Solution {
public:
    int solve(int num){
        int res = 0;
        while(num > 0) {
            int rem = num % 10;
            res += rem;
            num /= 10;
        }
        return res;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(solve(nums[i]) == i){
                return i;
            }
        }
        return -1;
    }
};