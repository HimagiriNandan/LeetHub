class Solution {
public:
    string makeFancyString(string s) {
        if(s.length() <= 2) return s;
        string res = "";
        for(int i = 0; i < s.length(); i++){
            int c = s[i];
            if(res.length() >= 2){
                if(res[res.length() - 1] == c && res[res.length() - 2] == c){
                    continue;
                }
            }
            res += c;
        }
        return res;
    }
};