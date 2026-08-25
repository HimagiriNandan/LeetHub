class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        int mul = k;
        for(int i = 0; i <= st.size(); i++) {
            if(st.count(mul) == 0) {
                return mul;
            }
            mul = mul + k;
        }
        return mul;
    }
};