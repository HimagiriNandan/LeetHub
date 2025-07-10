class NumArray {
private:
    int n;
    vector<int> bit;
    vector<int> data;
    void add(int index, int toAdd){
        index++;
        while(index <= n){
            bit[index] += toAdd;
            index += (index & -index);
        }
    }

    int prefixSum(int index){
        index++;
        int res = 0;
        while(index > 0){
            res += bit[index];
            index -= index & -index;
        }
        return res;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        bit.assign(n + 1, 0);
        data = nums;
        for(int i = 0; i < n; i++){
            add(i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        int toAdd = val - data[index];
        data[index] = val;
        add(index, toAdd);
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right) - prefixSum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */