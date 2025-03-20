class Solution {
public:
    //here s1 is larger than s2
    bool checkIspossible(string& s1, string& s2){
        if(s1.size() != s2.size() + 1) return false;
        int i = 0, j = 0;
        while(i < s1.size()){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return (i == s1.size() && j == s2.size());
    }
    static bool comp(string& s1, string& s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int ind = 0; ind < n; ind++){
            for(int prev = 0; prev < ind; prev++){
                if(checkIspossible(words[ind], words[prev]) && dp[prev] + 1 > dp[ind]){
                    dp[ind] = dp[prev] + 1;
                }
                maxi = max(maxi, dp[ind]);
            }
        }
        return maxi;
    }
};