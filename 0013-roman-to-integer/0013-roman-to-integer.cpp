class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int prev = 0, ans = 0;
        for(int i = 0; i < s.length(); i++){
            int temp = mp[s[i]];
            if(temp > prev){
                ans -= prev;
                int t = temp - prev;
                ans += t;
            }else{
                ans += temp;
            }
            prev = temp;
        }
        return ans;
    }
};