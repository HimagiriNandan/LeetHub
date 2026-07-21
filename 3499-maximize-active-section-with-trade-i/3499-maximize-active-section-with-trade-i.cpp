class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int totalOnes = 0;
        for(char ch : s) {
            if(ch == '1') totalOnes++;
        }
        vector<pair<char, int>> mp;
        int cnt = 1;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i - 1]) cnt++;
            else{
                mp.push_back({s[i-1], cnt});
                cnt = 1;
            }
        }
        mp.push_back({s.back(), cnt});
        int ans = 0;
        for(int i = 1; i + 1 < mp.size(); i++) {
            if(mp[i].first == '1' && mp[i - 1].first == '0' && mp[i + 1].first == '0') {
                int zeroes = mp[i - 1].second + mp[i + 1].second;
                ans = max(zeroes, ans);
            }
        }
        return totalOnes + ans;
    }
};