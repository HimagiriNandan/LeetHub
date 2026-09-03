class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        bool canMakeOdd = true;
        bool canMakeEven = true;

        for (int x : nums1) {
            bool odd = (x % 2 != 0);
            bool even = (x % 2 == 0);

            if (x != mn) {
                int diff = x - mn;

                odd |= (diff % 2 != 0);
                even |= (diff % 2 == 0);
            }

            if (!odd)
                canMakeOdd = false;

            if (!even)
                canMakeEven = false;
        }

        return canMakeOdd || canMakeEven;
    }
};