class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = 36;
        for(int n : nums) {
            int temp = n - 9 * (n/10 + n/100 + n/1000 + n/10000);
            if(temp < mini) mini = temp;
        }
        return mini;
    }
};