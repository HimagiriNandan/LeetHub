class Solution {
public:
    int isPalin(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            for(int j = i; j < s.length(); j++){
                if(isPalin(s, i, j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};