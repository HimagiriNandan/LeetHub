class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int largest = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++) {
            if(i == 0){
                if(arr[0] == 1) {
                    continue;
                } else {
                    arr[0] = 1;
                }
            } else {
                if(arr[i] - arr[i - 1] > 1) {
                    arr[i] = arr[i - 1] + 1;
                }
            }
        }
        return arr[arr.size() - 1];
    }
};