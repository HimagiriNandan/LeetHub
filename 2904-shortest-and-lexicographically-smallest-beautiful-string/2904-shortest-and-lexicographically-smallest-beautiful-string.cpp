class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int l = 0;
        int ones = 0;

        string ans = "";

        for (int r = 0; r < s.length(); r++) {

            if (s[r] == '1') {
                ones++;
            }

            while (ones == k) {

                string temp = s.substr(l, r - l + 1);

                if (ans == "") {
                    ans = temp;
                }
                else if (temp.length() < ans.length()) {
                    ans = temp;
                }
                else if (temp.length() == ans.length() && temp < ans) {
                    ans = temp;
                }
                if (s[l] == '1') {
                    ones--;
                }

                l++;
            }
        }

        return ans;
    }
};