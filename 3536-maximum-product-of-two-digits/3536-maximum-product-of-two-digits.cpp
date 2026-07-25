class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while(n > 0) {
            int temp = n % 10;
            arr.push_back(temp);
            n = n/10;
        }
        sort(arr.begin(), arr.end());
        return arr[arr.size() - 1] * arr[arr.size() - 2];
    }
};