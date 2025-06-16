class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxi = 0, temp = 0;
        unordered_map<int, int> mp;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            temp += nums[r];
            mp[nums[r]]++;
            while(r - l + 1 > k || mp[nums[r]] > 1){
                temp -= nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]] == 0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            if(mp.size() == k){
                maxi = max(maxi, temp);
            }
        }
        return maxi;
    }
};