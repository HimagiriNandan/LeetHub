class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        int bitLength = (int)floor(log2(num)) + 1;
        
        for(int i = 0; i < bitLength; i++){
            num = num ^ (1 << i);
        }
        return num;
    }
};