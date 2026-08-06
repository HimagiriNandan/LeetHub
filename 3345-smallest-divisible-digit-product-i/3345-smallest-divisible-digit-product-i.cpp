class Solution {
public:
    int solve(int n) {
        int ans = 1;
        while(n > 0) {
            int temp = n % 10;
            ans = ans * temp;
            n = n / 10;
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        for(int i = n; i <= n + 10; i++) {
            int prod = solve(i);
            if(prod % t == 0) return i;
        }
        return n;
    }
};