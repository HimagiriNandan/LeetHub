class DSU{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_parent(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = find_parent(parent[x]);
    }

    void unionbysize(int u, int v){
        int pu = find_parent(u);
        int pv = find_parent(v);
        if(pu == pv){
            return;
        }
        if(size[pu] >= size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU ds(edges.size() + 1);
        vector<int> ans;
        for(auto const& edge : edges){
            if(ds.find_parent(edge[0]) != ds.find_parent(edge[1])){
                ds.unionbysize(edge[0], edge[1]);
            }else{
                ans = {edge[0], edge[1]};
            }
        }
        return ans;
    }
};