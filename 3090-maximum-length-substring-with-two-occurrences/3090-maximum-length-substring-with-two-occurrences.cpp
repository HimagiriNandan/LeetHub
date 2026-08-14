class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0;
        int maxi = INT_MIN;
        for(int r = 0; r < s.length(); r++) {
            mp[s[r]]++;
            while(mp[s[r]] > 2) {
                mp[s[l]]--;
                l++;
            }
            maxi = max(r - l + 1, maxi);
        }
        return maxi;
    }
};