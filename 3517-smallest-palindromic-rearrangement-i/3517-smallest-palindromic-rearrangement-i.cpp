class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for(char st : s) {
            freq[st - 'a']++;
        }
        string left = "";
        string middle = "";
        for(int i = 0; i < 26; i++) {
            left += string(freq[i] / 2, 'a' + i);

            if (freq[i] % 2)
                middle = char('a' + i);
        }
        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};