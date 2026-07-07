class Solution {
public:
    long long rev(long long temp) {
        long long ans = 0;
        while(temp > 0) {
            int rem = temp % 10;
            temp = temp / 10;
            ans = (ans * 10 + rem);
        }
        return ans;
    }
    
    long long sumAndMultiply(int n) {
        long long temp = 0;
        int sum = 0;
        while(n > 0) {
            int rem = n % 10;
            n = n / 10;
            if(rem != 0)
                temp = (temp * 10 + rem);
            sum = sum + rem;
        }
        long long num = rev(temp);
        return num * sum;
    }
};