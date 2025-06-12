class Solution {
public:
    bool rotateString(string s, string goal) {
        string str = s;
        if(s.length() != goal.length()) return false;
        for(int i = 0; i < str.length(); i++){
            char temp = str[0];
            str = str.substr(1) + temp;
            if(str == goal) return true;
        }
        return false;
    }
};