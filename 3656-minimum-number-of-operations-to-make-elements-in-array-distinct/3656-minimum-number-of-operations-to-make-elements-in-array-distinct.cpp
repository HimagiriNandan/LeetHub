class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int op = 0;
        while(true){
            unordered_set<int> st;
            bool hasdup = false;
            for(int num : nums){
                if(st.count(num)){
                    hasdup = true;
                    break;
                }
                st.insert(num);
            }
            if(!hasdup) break;
            int rem = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + rem);
            op++;
        }
        return op;
    }
};