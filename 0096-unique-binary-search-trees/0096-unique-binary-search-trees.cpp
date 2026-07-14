class Solution {
public:

    int solve(int n) {
        if(n == 0 || n == 1) return 1;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            int left = i - 1;
            int right = n - i;
            ans += solve(left) * solve(right);
        } 
        return ans;
    }

    int numTrees(int n) {
       int ans = solve(n);
       return ans;
    }
};