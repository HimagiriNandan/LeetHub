class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        vector<pair<char, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });
        string res = "";
        for(auto &[ch, fr] : v){
            res += string(fr, ch);
        }
        return res;
    }
};