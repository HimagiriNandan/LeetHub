class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            int a = (26 - (s[i] - 'a')) * (i + 1);
            ans += a;
        }
        return ans;
    }
};