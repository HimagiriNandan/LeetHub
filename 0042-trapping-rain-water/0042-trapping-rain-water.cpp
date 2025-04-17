class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int l = 0, r = 0, ans = 0;
        while(left <= right){
            if(height[left] <= height[right]){
                l = max(l, height[left]);
                ans += l - height[left];
                left++;
            }else{
                r = max(r, height[right]);
                ans += r - height[right];
                right--;
            }
        }
        return ans;
    }
};