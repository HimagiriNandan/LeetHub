class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        
        for(int i = 0; i < num.length(); i++){
            while(k > 0 && !s.empty() && s.back() > num[i]){
                k--;
                s.pop_back();
            }
            s.push_back(num[i]);
        }
        
        while(k > 0 && !s.empty()){
            s.pop_back();
            k--;
        }
        
        int start = 0;
        while(start < s.length() && s[start] == '0'){
            start++;
        }
        
        string result = s.substr(start);
        
        return result.empty() ? "0" : result;
    }
};