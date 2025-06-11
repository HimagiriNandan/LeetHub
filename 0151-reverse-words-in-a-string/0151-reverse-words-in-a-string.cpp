class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string str = "";
        s += ' ';
        for(int i = 0; i < s.length(); i++){
            if (s[i] != ' ') {
                str += s[i];
            } else if (!str.empty()) {
                st.push(str);
                str = "";
            }
        }
        string ans = "";
        while(!st.empty()){
            string a = st.top();
            st.pop();
            ans += a;
            if(!st.empty()) ans += ' ';
        }
        return ans;
    }
};