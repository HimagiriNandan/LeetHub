class DisjointSet {
    vector<int> size, parent;
    public:
        DisjointSet(int n) {
            size.resize(n + 1, 1);
            parent.resize(n + 1);
            for(int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int findPar(int n) {
            if(parent[n] == n) {
                return n;
            }
            return parent[n] = findPar(parent[n]);
        }

        void unionBySize(int u, int v) {
            int pu = findPar(u);
            int pv = findPar(v);
            if(pu == pv) return;
            if(size[pu] >= size[pv]) {
                parent[pv] = pu;
                size[pu] += size[pv];
            } else {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
        }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet dsu(n);
        for(int i = 1; i < n; i++) {
            if(abs(nums[i] - nums[i - 1]) <= maxDiff) {
                dsu.unionBySize(i, i - 1);
            }
        }
        vector<bool> ans;
        for(auto it : queries) {
            int u = it[0];
            int v = it[1];
            if(dsu.findPar(u) == dsu.findPar(v)) {
                ans.push_back(true);
            } else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};