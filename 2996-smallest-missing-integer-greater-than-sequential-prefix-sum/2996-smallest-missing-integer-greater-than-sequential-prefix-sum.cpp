class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int s = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] + 1 == nums[i]) {
                s += nums[i];
            } else{
                break;
            }
        }
        unordered_set<int> st(nums.begin(), nums.end());
         while (st.count(s)) {
            s++;
        }
        return s;
    }
};