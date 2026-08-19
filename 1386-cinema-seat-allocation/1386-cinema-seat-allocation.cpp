class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;
        for(auto it : reservedSeats) {
            int row = it[0];
            int col = it[1];
            mp[row] |= (1 << col);
        }
        int leftMask = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int midMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int rightMask = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        int ans = 0;

        ans += 2 * (n - mp.size());
        for(auto &[key, mask] : mp) {
            if((mask & leftMask) == 0) {
                ans++;
                if((mask & rightMask) == 0) {
                    ans++;
                }
            } else if((mask & midMask) == 0) {
                ans++;
            } else if((mask & rightMask) == 0) {
                ans++;
            }
        }
        return ans;
    }
};