class Solution {
public:
    void helper(vector<int>& nums, int ind, int n, vector<int>& ans, int sum){
        if(ind == n){
            ans.push_back(sum);
            return;
        }
        helper(nums, ind + 1, n, ans, sum ^ nums[ind]);
        helper(nums, ind + 1, n, ans, sum);

    }
    int subsetXORSum(vector<int>& nums) {
        vector<int> ans;
        helper(nums, 0, nums.size(), ans, 0);
        int total = 0;
        for(int i = 0; i < ans.size(); i++){
            total += ans[i];
        }
        return total;
    }
};