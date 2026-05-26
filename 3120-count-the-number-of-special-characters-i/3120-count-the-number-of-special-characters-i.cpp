class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> l, u;
        int cnt = 0;
        for(auto ch : word) {
            if(islower(ch)) {
                l.insert(ch);
            }else {
                u.insert(ch);
            }
        }
        for(auto ch: l){
            if(u.count(toupper(ch))){
                cnt++;
            }
        }
        return cnt;
    }
};