class Solution {
public:
    int maxDepth(string s) {
        int lc = 0;
        int maxi = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                lc++;
                maxi = max(maxi, lc);
            }else if(s[i] == ')'){
                lc--;
            }
        }
        return maxi;
    }
};