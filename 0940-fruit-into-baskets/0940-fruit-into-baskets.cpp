class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int l = 0, maxi = 0;
        for(int r = 0; r < fruits.size(); r++){
            mp[fruits[r]]++;
            if(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }
            else if(mp.size() <= 2){
                maxi = max(maxi, r - l + 1);
            }
        }
        return maxi;
    }
};