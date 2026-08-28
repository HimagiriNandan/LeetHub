class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        int oddChar = -1, oddCount = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) { oddCount++; oddChar = i; }
        }
        string mid = "";
        if (n % 2 == 0) {
            if (oddCount > 0) return "";
        } else {
            if (oddCount != 1) return "";
            mid = string(1, char('a' + oddChar));
        }
        
        int halfLen = n / 2;
        vector<int> halfCnt(26, 0);
        for (int i = 0; i < 26; i++) halfCnt[i] = cnt[i] / 2;
        
        string targetHalf = target.substr(0, halfLen);
        
        {
            vector<int> tc(26, 0);
            for (char c : targetHalf) tc[c - 'a']++;
            if (tc == halfCnt) {
                string H = targetHalf;
                string rev = H;
                reverse(rev.begin(), rev.end());
                string candidate = H + mid + rev;
                if (candidate > target) return candidate;
            }
        }
        
        vector<vector<int>> prefixCounts;
        prefixCounts.push_back(halfCnt);
        vector<int> counts = halfCnt;
        int maxMatch = 0;
        for (int i = 0; i < halfLen; i++) {
            int ch = targetHalf[i] - 'a';
            if (counts[ch] > 0) {
                counts[ch]--;
                prefixCounts.push_back(counts);
                maxMatch++;
            } else {
                break;
            }
        }
        
        int start = min(maxMatch, halfLen - 1);
        for (int i = start; i >= 0; i--) {
            vector<int>& avail = prefixCounts[i];
            int targetChar = targetHalf[i] - 'a';
            
            int found = -1;
            for (int c = targetChar + 1; c < 26; c++) {
                if (avail[c] > 0) { found = c; break; }
            }
            
            if (found != -1) {
                vector<int> newCounts = avail;
                newCounts[found]--;
                
                string rest = "";
                for (int c = 0; c < 26; c++) {
                    rest += string(newCounts[c], char('a' + c));
                }
                
                string H = targetHalf.substr(0, i) + char('a' + found) + rest;
                string rev = H;
                reverse(rev.begin(), rev.end());
                return H + mid + rev;
            }
        }
        
        return "";
    }
};