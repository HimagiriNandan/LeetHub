class Solution {
public:
    vector<int> findPse(vector<int> &heights){
        stack<int> st;
        vector<int> res(heights.size());
        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = -1;
            }else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }
    vector<int> findNse(vector<int> &heights){
        stack<int> st;
        vector<int> res(heights.size());
        for(int i = heights.size() - 1; i >= 0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = heights.size();
            }else{
                res[i] = st.top();
            }
            st.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = findPse(heights);
        vector<int> nse = findNse(heights);
        int maxi = -1;
        for(int i = 0; i < heights.size(); i++){
            maxi = max(maxi, (nse[i] - pse[i] - 1) * heights[i]);
        }
        return maxi;
    }
};