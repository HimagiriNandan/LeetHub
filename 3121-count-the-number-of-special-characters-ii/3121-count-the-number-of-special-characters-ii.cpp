class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> l, u;
        for(int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if(islower(ch)){
                l[ch] = i; 
            }else{
                if(u.count(ch) == 0) {
                    u[ch] = i;
                }
            }
        }
        int cnt = 0;
        for(auto const& it: u){
            char temp = tolower(it.first);
            if(l.count(temp) && l[temp] < it.second) {
                cnt++;
            }
        }
        return cnt;
    }
};