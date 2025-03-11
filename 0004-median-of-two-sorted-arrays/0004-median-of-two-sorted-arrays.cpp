class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int ind1 = (n+m-1)/2, ind2 = ind1 + 1;
        int cnt = 0;
        int ind1el = -1, ind2el = -1;
        int i = 0, j = 0;
        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                if(cnt == ind1) ind1el = nums1[i];
                if(cnt == ind2) ind2el = nums1[i];
                cnt++;
                i++;
            }else{
                if(cnt == ind1) ind1el = nums2[j];
                if(cnt == ind2) ind2el = nums2[j];
                cnt++;
                j++;
            }
        }
        while(i < n){
            if(cnt == ind1) ind1el = nums1[i];
            if(cnt == ind2) ind2el = nums1[i];
            cnt++;
            i++;
        }
        while(j < m){
            if(cnt == ind1) ind1el = nums2[j];
            if(cnt == ind2) ind2el = nums2[j];
            cnt++;
            j++;            
        }
        if((n+m) % 2 == 1) return (double)ind1el;
        else{
            return (double)(ind1el + ind2el) / 2.0;
        }
    }
};