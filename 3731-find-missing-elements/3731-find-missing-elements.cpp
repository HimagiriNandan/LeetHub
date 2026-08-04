class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        unordered_set<int> st;
        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        for(int i = mini; i < maxi; i++) {
            if(st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};