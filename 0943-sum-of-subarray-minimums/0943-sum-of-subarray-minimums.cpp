class Solution {
public:
    vector<int> findNse(vector<int>& arr){
        vector<int> res(arr.size());
        stack<int> st;
        for(int i = arr.size() - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            res[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }

        return res;
    }

    vector<int> findPse(vector<int>& arr){
        stack<int> st;
        vector<int> res(arr.size());
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                res[i] = -1;
            }else res[i] = st.top();
            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        long long total = 0, mod = 1e9 + 7;
        for(int i = 0; i < arr.size(); i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            long long contribution = ((long long)left * right % mod) * arr[i] % mod;
            total = (total + contribution) % mod;
        }
        return total;
    }
};