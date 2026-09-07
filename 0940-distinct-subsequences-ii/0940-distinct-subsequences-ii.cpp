class Solution {
public:
    const long long MOD = 1000000007;

    vector<long long> dp;

    long long solve(string &s, int i) {
        if (i == 0) {
            return 1;
        }

        if (dp[i] != -1) {
            return dp[i];
        }
        long long ans = 2 * solve(s, i - 1);

        int prev = -1;

        for (int j = i - 2; j >= 0; j--) {
            if (s[j] == s[i - 1]) {
                prev = j;
                break;
            }
        }

        if (prev != -1) {
            ans -= solve(s, prev);
        }

        return dp[i] = (ans + MOD) % MOD;
    }

    int distinctSubseqII(string s) {
        int n = s.length();

        dp.assign(n + 1, -1);

        return (solve(s, n) - 1 + MOD) % MOD;
    }
};