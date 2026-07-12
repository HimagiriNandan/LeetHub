class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copiedArr;
        copiedArr = arr;
        unordered_map<int, int> mp;
        sort(copiedArr.begin(), copiedArr.end());
        int rank = 1;
        for(int i = 0; i < arr.size(); i++) {
            if(mp.find(copiedArr[i]) == mp.end()) {
                mp[copiedArr[i]] = rank++;
            }
        }
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++) {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};