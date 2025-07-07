class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1) return dividend;
        bool sign = true;
        if(dividend < 0 && divisor > 0) sign = false;
        if(dividend > 0 && divisor < 0) sign = false;
        long d = labs((long)dividend);
        long ds = labs((long)divisor);
        int quotient = 0;
        while(d >= ds){
            int cnt = 0;
            while(d >= (ds << cnt + 1)) cnt++;
            quotient += (1 << cnt);
            d -= (ds << cnt);
        }
        if(quotient == (1 << 31) && sign) return INT_MAX;
        else if(quotient == (1 << 31)) return INT_MIN;
        return sign ? quotient : -quotient;
    }
};