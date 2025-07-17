class Solution {
public:
    vector<int> findple(vector<int> &nums) {
        stack<int> st;
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> findnle(vector<int> &nums) {
        stack<int> st;
        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            res[i] = st.empty() ? nums.size() : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> findpse(vector<int> &nums) {
        stack<int> st;
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return res;
    }

    vector<int> findnse(vector<int> &nums) {
        stack<int> st;
        vector<int> res(nums.size());
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            res[i] = st.empty() ? nums.size() : st.top();
            st.push(i);
        }
        return res;
    }

    long long subMin(vector<int>& nums) {
        int n = nums.size();
        vector<int> pse = findpse(nums);
        vector<int> nse = findnse(nums);
        long long t = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            t += left * right * nums[i];
        }
        return t;
    }

    long long subMax(vector<int>& nums) {
        int n = nums.size();
        vector<int> ple = findple(nums);
        vector<int> nle = findnle(nums);
        long long t = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - ple[i];
            long long right = nle[i] - i;
            t += left * right * nums[i];
        }
        return t;
    }

    long long subArrayRanges(vector<int>& nums) {
        return subMax(nums) - subMin(nums);
    }
};
