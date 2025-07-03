class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int len = (int) floor(log2(n)) + 1;
        return (n == (1 << (len - 1)));
    }
};