class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> digitPrefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            digitPrefix[i + 1] = digitPrefix[i] + (s[i] - '0');

        vector<int> pos;
        vector<int> digit;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> pref(m + 1, 0);
        for (int i = 0; i < m; i++)
            pref[i + 1] = (pref[i] * 10 + digit[i]) % MOD;

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = digitPrefix[r + 1] - digitPrefix[l];

            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);

            if (it1 == it2) {
                ans.push_back(0);
                continue;
            }

            int L = it1 - pos.begin();
            int R = (it2 - pos.begin()) - 1;

            int len = R - L + 1;

            long long x = (pref[R + 1] - pref[L] * pow10[len]) % MOD;
            if (x < 0) x += MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};