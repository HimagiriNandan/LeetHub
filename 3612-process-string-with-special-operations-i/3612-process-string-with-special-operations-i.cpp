class Solution {
public:
    string processStr(string s) {
        string res;
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= 'a' && s[i] <= 'z') {
                res.push_back(s[i]);
            } else if(s[i] == '*'){
                if(!res.empty()){
                    res.pop_back();
                }
            } else if(s[i] == '#'){
                res += res;
            } else if (s[i] == '%') {
                reverse(res.begin(), res.end());
            }
        }
        return res;
    }
};