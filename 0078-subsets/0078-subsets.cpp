class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int s = (1 << n) - 1;
        for(int num = 0; num <= s; num++){
            vector<int> res;
            for(int i = 0; i < n; i++){
                if((num >> i) & 1){
                    res.push_back(nums[i]);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};