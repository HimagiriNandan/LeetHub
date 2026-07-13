class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string str = "123456789";
        int lowLen = to_string(low).size();
        int highLen = to_string(high).size();

        for(int len = lowLen; len <= highLen; len++) {
            for(int i = 0; i <= 9 - len; i++) {
                int num = stoi(str.substr(i, len));
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};