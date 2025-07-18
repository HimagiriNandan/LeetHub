class Solution {
public:
    vector<int> findNse(vector<int>& nums){
        vector<int> ans(nums.size(), nums.size());
        stack<int> st;
        for(int i = nums.size() - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> findPse(vector<int>& nums){
        vector<int> ans(nums.size(), -1);
        stack<int> st;
        for(int i = 0; i < nums.size(); i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

    int helper(vector<int>& nums){
        vector<int> nse = findNse(nums);
        vector<int> pse = findPse(nums);
        int maxi = INT_MIN; 
        for(int i = 0; i < nums.size(); i++){
            maxi = max(maxi, nums[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pref(n, vector<int>(m));
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                if(matrix[i][j] == '1') sum += (matrix[i][j] - '0');
                if(matrix[i][j] == '0') sum = 0;
                pref[i][j] = sum;
            }
        }
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, helper(pref[i]));
        }
        return maxi;
    }
};