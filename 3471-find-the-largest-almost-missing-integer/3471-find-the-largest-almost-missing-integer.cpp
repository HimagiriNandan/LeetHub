class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        int n = nums.size();

        for (int l = 0; l <= n - k; l++) {
            unordered_set<int> seen;

            for (int r = l; r < l + k; r++) {
                seen.insert(nums[r]);
            }

            for (int x : seen) {
                count[x]++;
            }
        }

        int ans = -1;

        for (auto &[x, cnt] : count) {
            if (cnt == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};